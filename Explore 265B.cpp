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
    ll n,m,t,i;
    cin>>n>>m>>t;

    ll ar[n+1]={0};

    for(i=2;i<=n;i++)
    {
        cin>>ar[i];
    }
    map<ll,ll>mp;
    for(i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;

        mp[a]=b;

    }


    bool f=true;

    for(i=2;i<=n;i++)
    {

        t-=ar[i];

        if(mp[i] and t>0)
        {
            t+=mp[i];
        }

        if(t<=0)
        {
            f=false;
            break;
        }
    }

    if(f) Yes;
    else No;

    return 0;
}
