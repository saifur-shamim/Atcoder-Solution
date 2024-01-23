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

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const dl PI=acos(-1);
const int inf=2e9;
const ll infll=900000000000000000;

const int  mx= 2e5+24;

vi adj[mx];
bool vis [mx];
ll ans;

ll par[mx],c_node[mx];
void dfs(ll node,ll p)
{


    if(vis[node] and c_node[node]==0)
    {
        ll u=node;

        while(p!=u)
        {
            c_node[p]=1;
            p=par[p];
        }

        c_node[u]=1;

        ans++;

        return ;
    }
    else if(c_node[node]) return ;

    vis[node]=true;

    par[node]=p;
    for(auto child: adj[node])
    {

      if(child==p) continue;
      else dfs(child,node);
    }
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

    ll n,m,i;
    cin>>n>>m;

    for(i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].PB(v);
        adj[v].PB(u);
    }

    dfs(1,-1);

    cout<<ans<<endl;
    return 0;
}

