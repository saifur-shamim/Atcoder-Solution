///Bismillahir Rahmanir Rahim
///Happy Coding

#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef  long int li;
typedef  double dl;
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<pii>vpi;
typedef  vector<pll> vpl;

#define     PB        push_back
#define     MP        make_pair
#define     F         first
#define     S         second
#define     sz(x)     (int)x.size()
#define     all(a)    (a).begin(),(a).end()
#define     faster    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define     endl      '\n'
#define     mem(a,b)  memset(a,b,sizeof(a))
#define     mod       1000000007
#define     gcd(a,b)  __gcd(a,b)
#define     pf        printf
#define     YES       cout<<"YES\n"
#define     Yes       cout<<"Yes\n"
#define     NO        cout<<"NO\n"
#define     No        cout<<"No\n"

const dl PI=acos(-1);
const int inf=2e9;
const ll infll=900000000000000000;

int main()
{

    faster;
    /*
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    */
    ll n,i;
    cin>>n;

    vl v1,v2;
    map<ll,ll>mp;

    for(i=0; i<n; i++)
    {
        ll a;
        cin>>a;

        if(mp[a] or a>n)
        {
            v2.PB(a);
        }
        else
        {
            v1.PB(a);
        }

        mp[a]++;
    }


    sort(all(v1));
    sort(all(v2));

    for(i=0;i<sz(v2);i++)
    {
        v1.PB(v2[i]);
    }

    ll ans=0;
    ll cnt=1;
    for(i=0; i<sz(v1);)
    {
        if(v1[i]==cnt)
        {
            ans=cnt;
            cnt++;
            i++;
        }
        else
        {
            if(i+2<=sz(v1))
            {
                ans=cnt;
                cnt++;

                v1.pop_back();
                v1.pop_back();
            }
            else break;
        }
    }

    cout<<ans<<endl;
    return 0;
}
