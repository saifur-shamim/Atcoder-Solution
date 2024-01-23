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
const int mx=1e5+3;
int n,k;
int h[mx],dp[mx];

int solve(int x)
{
    if(x==n) return 0;

    if(dp[x]!=-1) return dp[x];

    int mn=2e9;
    for(int i=1;i<=k;i++)
    {
        if(x+i<=n)
        {
            mn=min(mn,abs(h[x]-h[x+i])+solve(x+i));
        }
    }


    return dp[x]=mn;


}
int main()
{



    cin>>n>>k;

    int i;
    mem(dp,-1);
    for(i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int ans=solve(1);
    cout<<ans<<endl;

    return 0;
}
