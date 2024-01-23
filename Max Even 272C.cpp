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

    vl od,ev;


    for(i=0; i<n; i++)
    {
        ll a;
        cin>>a;

        if(a%2) od.PB(a);
        else ev.PB(a);
    }

    if(sz(od)<2 and sz(ev)<2)
    {
        cout<<"-1\n";
    }
    else
    {
        ll a1=0;
        ll a2=0;

        ev.PB(0);
        ev.PB(0);
        sort(all(od));
        sort(all(ev));

        ll s1=sz(ev);
        a1=ev[s1-1]+ev[s1-2];

        if(sz(od)>=2)
        {
            ll s2=sz(od);
            a2=od[s2-1]+od[s2-2];
        }

        cout<<max(a1,a2)<<endl;
    }


    return 0;
}
