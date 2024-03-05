import asyncio
import json
import time

from indy import pool, wallet, did, ledger, anoncreds, blob_storage
from indy.error import ErrorCode, IndyError
from indy.pairwise import get_pairwise

from os.path import dirname


async def verifier_get_entities_from_ledger(pool_handle, _did, identifiers, actor, timestamp=None):
    schemas = {}
    cred_defs = {}
    rev_reg_defs = {}
    rev_regs = {}
    for item in identifiers:
        print("\"{}\" -> Get Schema from Ledger".format(actor))
        (received_schema_id, received_schema) = await get_schema(pool_handle, _did, item['schema_id'])
        schemas[received_schema_id] = json.loads(received_schema)

        print("\"{}\" -> Get Claim Definition from Ledger".format(actor))
        (received_cred_def_id, received_cred_def) = await get_cred_def(pool_handle, _did, item['cred_def_id'])
        cred_defs[received_cred_def_id] = json.loads(received_cred_def)

        if 'rev_reg_id' in item and item['rev_reg_id'] is not None:
            # Get Revocation Definitions and Revocation Registries
            print("\"{}\" -> Get Revocation Definition from Ledger".format(actor))
            get_revoc_reg_def_request = await ledger.build_get_revoc_reg_def_request(_did, item['rev_reg_id'])

            get_revoc_reg_def_response = \
                await ensure_previous_request_applied(pool_handle, get_revoc_reg_def_request,
                                                      lambda response: response['result']['data'] is not None)
            (rev_reg_id, revoc_reg_def_json) = await ledger.parse_get_revoc_reg_def_response(get_revoc_reg_def_response)

            print("\"{}\" -> Get Revocation Registry from Ledger".format(actor))
            if not timestamp: timestamp = item['timestamp']
            get_revoc_reg_request = \
                await ledger.build_get_revoc_reg_request(_did, item['rev_reg_id'], timestamp)
            get_revoc_reg_response = \
                await ensure_previous_request_applied(pool_handle, get_revoc_reg_request,
                                                      lambda response: response['result']['data'] is not None)
            (rev_reg_id, rev_reg_json, timestamp2) = await ledger.parse_get_revoc_reg_response(get_revoc_reg_response)

            rev_regs[rev_reg_id] = {timestamp2: json.loads(rev_reg_json)}
            rev_reg_defs[rev_reg_id] = json.loads(revoc_reg_def_json)

    return json.dumps(schemas), json.dumps(cred_defs), json.dumps(rev_reg_defs), json.dumps(rev_regs)


async def get_schema(pool_handle, _did, schema_id):
    get_schema_request = await ledger.build_get_schema_request(_did, schema_id)
    get_schema_response = await ensure_previous_request_applied(
        pool_handle, get_schema_request, lambda response: response['result']['data'] is not None)
    return await ledger.parse_get_schema_response(get_schema_response)


async def get_cred_def(pool_handle, _did, cred_def_id):
    get_cred_def_request = await ledger.build_get_cred_def_request(_did, cred_def_id)
    get_cred_def_response = \
        await ensure_previous_request_applied(pool_handle, get_cred_def_request,
                                              lambda response: response['result']['data'] is not None)
    return await ledger.parse_get_cred_def_response(get_cred_def_response)



async def ensure_previous_request_applied(pool_handle, checker_request, checker):
    for _ in range(3):
        response = json.loads(await ledger.submit_request(pool_handle, checker_request))
        try:
            if checker(response):
                return json.dumps(response)
        except TypeError:
            pass
        time.sleep(5)


async def create_wallet(identity):
    print("\"{}\" -> Create wallet".format(identity['name']))
    try:
        await wallet.create_wallet(identity['wallet_config'],
                                   identity['wallet_credentials'])
    except IndyError as ex:
        if ex.error_code == ErrorCode.PoolLedgerConfigAlreadyExistsError:
            pass
    identity['wallet'] = await wallet.open_wallet(identity['wallet_config'],
                                                  identity['wallet_credentials'])



async def getting_verinym(from_, to):
    await create_wallet(to)

    (to['did'], to['key']) = await did.create_and_store_my_did(to['wallet'], "{}")

    from_['info'] = {
        'did': to['did'],
        'verkey': to['key'],
        'role': to['role'] or None
    }

    await send_nym(from_['pool'], from_['wallet'], from_['did'], from_['info']['did'],
                   from_['info']['verkey'], from_['info']['role'])


async def send_nym(pool_handle, wallet_handle, _did, new_did, new_key, role):
    nym_request = await ledger.build_nym_request(_did, new_did, new_key, None, role)
    print(nym_request)
    await ledger.sign_and_submit_request(pool_handle, wallet_handle, _did, nym_request)


async def get_credential_for_referent(search_handle, referent):
    credentials = json.loads(
        await anoncreds.prover_fetch_credentials_for_proof_req(search_handle, referent, 10))
    return credentials[0]['cred_info']


async def prover_get_entities_from_ledger(pool_handle, _did, identifiers, actor, timestamp_from=None,
                                          timestamp_to=None):
    schemas = {}
    cred_defs = {}
    rev_states = {}
    for item in identifiers.values():
        print("\"{}\" -> Get Schema from Ledger".format(actor))
        print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.", item['schema_id'])
        (received_schema_id, received_schema) = await get_schema(pool_handle, _did, item['schema_id'])
        schemas[received_schema_id] = json.loads(received_schema)

        print("\"{}\" -> Get Claim Definition from Ledger".format(actor))
        (received_cred_def_id, received_cred_def) = await get_cred_def(pool_handle, _did, item['cred_def_id'])
        cred_defs[received_cred_def_id] = json.loads(received_cred_def)

        if 'rev_reg_id' in item and item['rev_reg_id'] is not None:
            # Create Revocations States
            print("\"{}\" -> Get Revocation Registry Definition from Ledger".format(actor))
            get_revoc_reg_def_request = await ledger.build_get_revoc_reg_def_request(_did, item['rev_reg_id'])

            get_revoc_reg_def_response = \
                await ensure_previous_request_applied(pool_handle, get_revoc_reg_def_request,
                                                      lambda response: response['result']['data'] is not None)
            (rev_reg_id, revoc_reg_def_json) = await ledger.parse_get_revoc_reg_def_response(get_revoc_reg_def_response)

            print("\"{}\" -> Get Revocation Registry Delta from Ledger".format(actor))
            if not timestamp_to: timestamp_to = int(time.time())
            get_revoc_reg_delta_request = \
                await ledger.build_get_revoc_reg_delta_request(_did, item['rev_reg_id'], timestamp_from, timestamp_to)
            get_revoc_reg_delta_response = \
                await ensure_previous_request_applied(pool_handle, get_revoc_reg_delta_request,
                                                      lambda response: response['result']['data'] is not None)
            (rev_reg_id, revoc_reg_delta_json, t) = \
                await ledger.parse_get_revoc_reg_delta_response(get_revoc_reg_delta_response)

            tails_reader_config = json.dumps(
                {'base_dir': dirname(json.loads(revoc_reg_def_json)['value']['tailsLocation']),
                 'uri_pattern': ''})
            blob_storage_reader_cfg_handle = await blob_storage.open_reader('default', tails_reader_config)

            print('%s - Create Revocation State', actor)
            rev_state_json = \
                await anoncreds.create_revocation_state(blob_storage_reader_cfg_handle, revoc_reg_def_json,
                                                        revoc_reg_delta_json, t, item['cred_rev_id'])
            rev_states[rev_reg_id] = {t: json.loads(rev_state_json)}

    return json.dumps(schemas), json.dumps(cred_defs), json.dumps(rev_states)


async def run():

    pool_ = {
        'name': 'pool1'
    }
    print("\nOpen Pool Ledger: {}".format(pool_['name']))
    pool_['genesis_txn_path'] = "pool1.txn"
    pool_['config'] = json.dumps({"genesis_txn": str(pool_['genesis_txn_path'])})

    print(pool_)

    # Set protocol version 2 to work with Indy Node 1.4
    await pool.set_protocol_version(2)

    try:
        await pool.create_pool_ledger_config(pool_['name'], pool_['config'])
    except IndyError as ex:
        if ex.error_code == ErrorCode.PoolLedgerConfigAlreadyExistsError:
            pass
    pool_['handle'] = await pool.open_pool_ledger(pool_['name'], None)

    print(pool_['handle'])
    
    #  Accessing a steward.

    steward = {
        'name': "Sovrin Steward",
        'wallet_config': json.dumps({'id': 'sovrin_steward_wallet'}),
        'wallet_credentials': json.dumps({'key': 'steward_wallet_key'}),
        'pool': pool_['handle'],
        'seed': '000000000000000000000000Steward1'
    }
    print(steward)

    await create_wallet(steward)

    print(steward["wallet"])

    steward["did_info"] = json.dumps({'seed':steward['seed']})
    print(steward["did_info"])

    # did:demoindynetwork:Th7MpTaRZVRYnPiabds81Y
    steward['did'], steward['key'] = await did.create_and_store_my_did(steward['wallet'], steward['did_info'])


    # ----------------------------------------------------------------------
    # Create and register dids for Government, passport office and visa center
    # ----------------------------------------------------------------------

    print("\n\n\n==================================================")
    print("==      Government registering Verinym     == ")
    print("\n------------------------------------------------------")


    government = {
        'name': 'Government',
        'wallet_config': json.dumps({'id': 'government_wallet'}),
        'wallet_credentials': json.dumps({'key': 'government_wallet_key'}),
        'pool': pool_['handle'],
        'role': 'TRUST_ANCHOR'
    }

    await getting_verinym(steward, government)



    print("\n\n=========================================================")
    print("==     The Passport office getting Verinym      ==")
    print("\n----------------------------------------------------------")

    thepassportoffice = {
        'name': 'thepassportoffice',
        'wallet_config': json.dumps({'id': 'thepassportoffice_wallet'}),
        'wallet_credentials': json.dumps({'key': 'thepassportoffice_wallet_key'}),
        'pool': pool_['handle'],
        'role': 'TRUST_ANCHOR'
    }

    await getting_verinym(steward, thepassportoffice)

    print("\n=======================================\n")
    print("==== The VISA Center getting Verinym  ====\n")
    print("-------------------------------------------\n")

    visacenter = {
        'name': 'visacenter',
        'wallet_config': json.dumps({'id': 'visacenter_wallet'}),
        'wallet_credentials': json.dumps({'key': 'visacenter_wallet_key'}),
        'pool': pool_['handle'],
        'role': 'TRUST_ANCHOR'
    }

    await getting_verinym(steward, visacenter)

    # -----------------------------------------------------
    # Government creates passport schema
    #------------------------------------------------------

    print("\n\nGovernment -> Create Passport Schema \n")
    passport = {
        'name': 'passport',
        'version': '1.2',
        'attributes': ['first_name', 'last_name', 'dob', 'ssn','issuedate','expirydate','average']
    }
    (government['passport_schema_id'], government['passport_schema']) = \
        await anoncreds.issuer_create_schema(government['did'], passport['name'], passport['version'],
                                             json.dumps(passport['attributes']))
    
    print(government['passport_schema'])
    passport_schema_id = government['passport_schema_id']
    print("\n")
    print(government['passport_schema_id'], government['passport_schema'])

    print("Government -> Send  Passport Schema to Ledger\n")

    
    schema_request = await ledger.build_schema_request(government['did'], government['passport_schema'])
    await ledger.sign_and_submit_request(government['pool'], government['wallet'], government['did'], schema_request)
    

    # -----------------------------------------------------
    # passport office will create a credential definition
    
    print("\n\n====================================================")
    print("===   The Passport Office Credential Definition Setup ==")
    print("\n-------------------------------------------------------")

    print("\n  The Passport Office  -> Get Passport Schema from Ledger")

    # GET SCHEMA FROM LEDGER
    get_schema_request = await ledger.build_get_schema_request(thepassportoffice['did'], passport_schema_id)
    get_schema_response = await ensure_previous_request_applied(
       thepassportoffice['pool'], get_schema_request, lambda response: response['result']['data'] is not None)
    (thepassportoffice['passport_schema_id'],thepassportoffice['passport_schema']) = await ledger.parse_get_schema_response(get_schema_response)

    # passport CREDENTIAL DEFINITION
    print("\n The Passport Office  -> Create and store in Wallet \"Passport\" Credential Definition")
    passport_cred_def = {
        'tag': 'TAG1',
        'type': 'CL',
        'config': {"support_revocation": False}
    }
    (thepassportoffice['passport_cred_def_id'],thepassportoffice['passport_cred_def']) = \
        await anoncreds.issuer_create_and_store_credential_def(thepassportoffice['wallet'],thepassportoffice['did'],
                                                              thepassportoffice['passport_schema'], passport_cred_def['tag'],
                                                               passport_cred_def['type'],
                                                               json.dumps(passport_cred_def['config']))

    print("\nThe passport office -> Send  \"Passport\" Credential Definition to Ledger\n")
    # print(thepassportoffice['passport_cred_def'])

    cred_def_request = await ledger.build_cred_def_request(thepassportoffice['did'],thepassportoffice['passport_cred_def'])
    # print(cred_def_request)
    await ledger.sign_and_submit_request(thepassportoffice['pool'],thepassportoffice['wallet'],thepassportoffice['did'], cred_def_request)
    print("\n\n>>>>>>>>>>>>>>>>>>>>>>.\n\n",thepassportoffice['passport_cred_def_id'])

    # ------------------------------------------------------------
    #  Alice getting passport from passport office

    print("\n==================================================")
    print("===   Getting Passport from the Passport Office    ==")
    print("\n===================================================")
    
    print("\n  ======== Alice setup ==========")
    print("--------------------------------------\n")

    alice = {
        'name': 'Alice',
        'wallet_config': json.dumps({'id': 'alice_wallet'}),
        'wallet_credentials': json.dumps({'key': 'alice_wallet_key'}),
        'pool': pool_['handle'],
    }

    await create_wallet(alice)
    (alice['did'], alice['key']) = await did.create_and_store_my_did(alice['wallet'], "{}")

    # passport office creates passport credential offer

    print("The Passport Office -> Create \"Passport\" Credential Offer for Alice")
    thepassportoffice['passport_cred_offer'] = \
        await anoncreds.issuer_create_credential_offer(thepassportoffice['wallet'],thepassportoffice['passport_cred_def_id'])

    print("\nThe Passport Office -> Send \"Passport\" Credential Offer to Alice\n")
    
    # Over Network 
    alice['passport_cred_offer'] =thepassportoffice['passport_cred_offer']

    print(alice['passport_cred_offer'])

    # Alice prepares a passport credential request

    passport_cred_offer_object = json.loads(alice['passport_cred_offer'])

    alice['passport_schema_id'] = passport_cred_offer_object['schema_id']
    alice['passport_cred_def_id'] = passport_cred_offer_object['cred_def_id']

    print("\nAlice -> Create and store \"Alice Master Secret\" in Wallet")
    alice['master_secret_id'] = await anoncreds.prover_create_master_secret(alice['wallet'], None)

    print("\nAlice -> Get \"The Passport-Office Passport\" Credential Definition from Ledger\n")
    (alice['thepassportoffice_passport_cred_def_id'], alice['thepassportoffice_passport_cred_def']) = \
        await get_cred_def(alice['pool'], alice['did'], alice['passport_cred_def_id'])

    print("Alice -> Create \"Passport\" Credential Request for the Passport Office\n")
    (alice['passport_cred_request'], alice['passport_cred_request_metadata']) = \
        await anoncreds.prover_create_credential_req(alice['wallet'], alice['did'],
                                                     alice['passport_cred_offer'],
                                                     alice['thepassportoffice_passport_cred_def'],
                                                     alice['master_secret_id'])

    print("\nAlice -> Send Passport Credential Request to the Passport-Office\n")

    # Over Network
    thepassportoffice['passport_cred_request'] = alice['passport_cred_request']


    # passport office issues credential to alice ----------------
    print("The Passport office -> Create \"Passport\" Credential for Alice\n")
    thepassportoffice['alice_passport_cred_values'] = json.dumps({
            "first_name": {"raw": "Alice", "encoded": "1139481716457488690172217916278103335"},
            "last_name": {"raw": "Garcia", "encoded": "5321642780241790123587902456789123452"},
            "dob": {"raw": "05 March 2001", "encoded": "12434523576212321"},
            "ssn": {"raw": "123-45-6789", "encoded": "3124141231422543541"},
            "issuedate": {"raw": "10 January 2020", "encoded": "2015"},
            "expirydate": {"raw": "20 April 2030", "encoded": "2015"},
             "average": {"raw": "5", "encoded": "5"}
        })
    thepassportoffice['passport_cred'], _, _ = \
        await anoncreds.issuer_create_credential(thepassportoffice['wallet'],thepassportoffice['passport_cred_offer'],
                                                thepassportoffice['passport_cred_request'],
                                                thepassportoffice['alice_passport_cred_values'], None, None)

    print(" The Passport Office  -> Send \"passport\" Credential to Alice \n")
    print(thepassportoffice['passport_cred'])
    # Over the network
    alice['passport_cred'] =thepassportoffice['passport_cred']

    print("\nAlice -> Store \"Passport\" Credential from the Passport-office")
    _, alice['passport_cred_def'] = await get_cred_def(alice['pool'], alice['did'],
                                                         alice['passport_cred_def_id'])

    await anoncreds.prover_store_credential(alice['wallet'], None, alice['passport_cred_request_metadata'],
                                            alice['passport_cred'], alice['passport_cred_def'], None)
    
    print("\n\n>>>>>>>>>>>>>>>>>>>>>>.\n\n", alice['passport_cred_def'])

    # Verifiable Presentation

    # Creating application request (presentaion request) --- validator - visacenter
    print("\nVisa-Center -> Create \"Visa-Application\" Proof Request")
    nonce = await anoncreds.generate_nonce()
    visacenter['visa_application_proof_request'] = json.dumps({
        'nonce': nonce,
        'name': 'Visa-Application',
        'version': '0.1',
        'requested_attributes': {
            'attr1_referent': {
                'name': 'first_name'
            },
            'attr2_referent': {
                'name': 'last_name'
            },
            'attr3_referent': {
                'name': 'dob',
                'restrictions': [{'cred_def_id':thepassportoffice['passport_cred_def_id']}]
            },
            'attr4_referent': {
                'name': 'ssn',
                'restrictions': [{'cred_def_id':thepassportoffice['passport_cred_def_id']}]
            },
            'attr5_referent': {
                'name': 'expirydate',
                'restrictions': [{'cred_def_id':thepassportoffice['passport_cred_def_id']}]
            },
            'attr6_referent': {
                'name': 'phone_number'
            }
        },
        'requested_predicates': {
            'predicate1_referent': {
                'name': 'average',
                'p_type': '>=',
                'p_value': 4,
                'restrictions': [{'cred_def_id':thepassportoffice['passport_cred_def_id']}]
            }
        }
    })

    print("\nVisa-Center -> Send \"Visa-Application\" Proof Request to Alice\n")

    # Over Network
    alice['visa_application_proof_request'] = visacenter['visa_application_proof_request']

    print(alice['visa_application_proof_request'])

    # Alice prepares the presentation ===================================

    print("\n\n>>>>>>>>>>>>>>>>>>>>>>>>.\n\n", alice['visa_application_proof_request'])

    print("\nAlice -> Get credentials for \"Visa-Application\" Proof Request\n")

    search_for_visa_application_proof_request = \
        await anoncreds.prover_search_credentials_for_proof_req(alice['wallet'],
                                                                alice['visa_application_proof_request'], None)
    
    print("-------------------------------------------------\n")
    print(search_for_visa_application_proof_request)
    print("--------------------------------------------------\n")

    cred_for_attr1 = await get_credential_for_referent(search_for_visa_application_proof_request, 'attr1_referent')
    cred_for_attr2 = await get_credential_for_referent(search_for_visa_application_proof_request, 'attr2_referent')
    cred_for_attr3 = await get_credential_for_referent(search_for_visa_application_proof_request, 'attr3_referent')
    cred_for_attr4 = await get_credential_for_referent(search_for_visa_application_proof_request, 'attr4_referent')
    cred_for_attr5 = await get_credential_for_referent(search_for_visa_application_proof_request, 'attr5_referent')
    cred_for_predicate1 = \
        await get_credential_for_referent(search_for_visa_application_proof_request, 'predicate1_referent')
    
    print("--------------------------------------------\n")
    print(cred_for_attr1)
    print("---------------------------------------------\n")


    await anoncreds.prover_close_credentials_search_for_proof_req(search_for_visa_application_proof_request)

    alice['creds_for_visa_application_proof'] = {cred_for_attr1['referent']: cred_for_attr1,
                                                cred_for_attr2['referent']: cred_for_attr2,
                                                cred_for_attr3['referent']: cred_for_attr3,
                                                cred_for_attr4['referent']: cred_for_attr4,
                                                cred_for_attr5['referent']: cred_for_attr5,
                                                cred_for_predicate1['referent']: cred_for_predicate1}

    print("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
    print(alice['creds_for_visa_application_proof'])

    alice['schemas_for_visa_application'], alice['cred_defs_for_visa_application'], \
    alice['revoc_states_for_visa_application'] = \
        await prover_get_entities_from_ledger(alice['pool'], alice['did'],
                                              alice['creds_for_visa_application_proof'], alice['name'])

    print("\"Alice\" -> Create \"Visa-Application\" Proof")
    alice['visa_application_requested_creds'] = json.dumps({
        'self_attested_attributes': {
            'attr1_referent': 'Alice',
            'attr2_referent': 'Garcia',
            'attr6_referent': '123-45-6789'
        },
        'requested_attributes': {
            'attr3_referent': {'cred_id': cred_for_attr3['referent'], 'revealed': True},
            'attr4_referent': {'cred_id': cred_for_attr4['referent'], 'revealed': True},
            'attr5_referent': {'cred_id': cred_for_attr5['referent'], 'revealed': True},
        },
        'requested_predicates': {'predicate1_referent': {'cred_id': cred_for_predicate1['referent']}}
    })

    alice['visa_application_proof'] = \
        await anoncreds.prover_create_proof(alice['wallet'], alice['visa_application_proof_request'],
                                            alice['visa_application_requested_creds'], alice['master_secret_id'],
                                            alice['schemas_for_visa_application'],
                                            alice['cred_defs_for_visa_application'],
                                            alice['revoc_states_for_visa_application'])
    print(alice['visa_application_proof'])

    print("\nAlice -> Send \"Visa-Application\" Proof to the VISA Center\n")

    # Over Network
    visacenter['visa_application_proof'] = alice['visa_application_proof']
    

    # Validating the verifiable presentation
    visa_application_proof_object = json.loads(visacenter['visa_application_proof'])

    visacenter['schemas_for_visa_application'], visacenter['cred_defs_for_visa_application'], \
    visacenter['revoc_ref_defs_for_visa_application'], visacenter['revoc_regs_for_visa_application'] = \
        await verifier_get_entities_from_ledger(visacenter['pool'], visacenter['did'],
                                                visa_application_proof_object['identifiers'], visacenter['name'])

    print("\nVisa-Center -> Verify \"Visa-Application\" Proof from Alice\n")
    assert '05 March 2001' == \
           visa_application_proof_object['requested_proof']['revealed_attrs']['attr3_referent']['raw']
    assert '123-45-6789' == \
           visa_application_proof_object['requested_proof']['revealed_attrs']['attr4_referent']['raw']
    assert '20 April 2030' == \
           visa_application_proof_object['requested_proof']['revealed_attrs']['attr5_referent']['raw']

    assert 'Alice' == visa_application_proof_object['requested_proof']['self_attested_attrs']['attr1_referent']
    assert 'Garcia' == visa_application_proof_object['requested_proof']['self_attested_attrs']['attr2_referent']
    assert '012233445566' == visa_application_proof_object['requested_proof']['self_attested_attrs']['attr6_referent']

    assert await anoncreds.verifier_verify_proof(visacenter['visa_application_proof_request'], visacenter['visa_application_proof'],
                                                 visacenter['schemas_for_visa_application'],
                                                 visacenter['cred_defs_for_visa_application'],
                                                 visacenter['revoc_ref_defs_for_visa_application'],
                                                 visacenter['revoc_regs_for_visa_application'])


loop = asyncio.get_event_loop()
loop.run_until_complete(run())
