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

const int lm=2e5+3;

vi adj[lm];
bool vis[lm];
vi cp,sp;

void dfs(int u,int v)
{
    vis[u]=true;
    cp.PB(u);

    if(u==v)
    {
        sp.assign(cp.begin(),cp.end());
        vis[u]=false;
        cp.pop_back();
        return ;
    }

    for(auto child:adj[u])
    {
       if(vis[child]==false) dfs(child,v);
    }


    cp.pop_back();
    vis[u]=false;
}
int main()
{


    /*
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    */
    int n,u,v;
    cin>>n>>u>>v;

    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].PB(y);
        adj[y].PB(x);
    }

    dfs(u,v);

    for(auto it:sp)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
