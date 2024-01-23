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
int n,s;
ll dp[123][mx];
ll w[124],val[124];

ll solve(int i,int curw)
{
    if(i>n) return 0;
    if(dp[i][curw]!=-1) return dp[i][curw];

    ll ret1=0,ret2=0;

    if(curw+w[i]<=s)
    {
        ret1=val[i]+solve(i+1,curw+w[i]);
    }

    ret2=solve(i+1,curw);

    return dp[i][curw]=max(ret1,ret2);
}
int main()
{

    faster;
 /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
*/
    cin>>n>>s;
    mem(dp,-1);

    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>val[i];
    }

    cout<<solve(1,0)<<endl;

    return 0;
}
