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
const int mx=2e5+2;
int dp[mx];
int n;
int h[mx];

int solve(int i)
{
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];

    int ret1=inf,ret2=inf;

    if(i+1<=n)
    ret1=abs(h[i]-h[i+1])+solve(i+1);
    if(i+2<=n)
    ret2=abs(h[i]-h[i+2])+solve(i+2);

    return dp[i]=min(ret1,ret2);
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
    cin>>n;
    mem(dp,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    cout<<solve(1)<<endl;
    return 0;
}
