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
const int mx=2e5+123;

vi adj[mx];
int col[mx];
bool vis[mx];
vi v[3];

bool dfs(int node,int c)
{
    vis[node]=true;
    col[node]=c;

    v[c].PB(node);
    for(int child: adj[node])
    {
        if(vis[child]==false)
        {
            if(dfs(child,c^1)==false)return false;
        }
        else
        {
            if(col[node]==col[child])return false;
        }
    }

    return true;
}

int main()
{

    int n,m,i;
    cin>>n>>m;

    map<pair<int,int>,bool>mp;
    for(i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
        mp[{u,v}]=true;
        mp[{v,u}]=true;
    }

    bool ans = dfs(1,1);

    if(!ans)
    {
        cout<<"0\n";
    }
    else
    {

        ll ans=0;
        for(i=0;i<sz(v[0]);i++)
        {
            for(ll j=0;j<sz(v[1]);j++)
            {
                if(!mp[{v[0][i],v[1][j]}] and !mp[{v[1][j],v[0][i]}])
                    {
                        ans++;
                    }
            }
        }

        cout<<ans<<endl;
    }

}


