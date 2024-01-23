///Bismillahir Rahmanir Rahim
///Happy Coding

#include<bits/stdc++.h>

using namespace std;


#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}


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

/* 8 Direction
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1};
 */
const dl PI=acos(-1);
const int inf=2e9;
const ll infll=900000000000000000;

const int mx=2e5+123;

vi adj[mx],indegree,order;

int n,m;
bool toposort()
{
    queue<int> q;

    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {

        if(sz(q)>1)
        {
            return false;
        }
        int t=q.front();

        q.pop();

        order.PB(t);

        for(auto it:adj[t])
        {
            indegree[it]--;

            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }

    return true;
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
    cin>>n>>m;

    indegree.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].PB(v);

        indegree[v]++;
    }

    if(!toposort())
    {
        No;

        return 0;
    }


    vi ans(n+2);
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        ans[order[i]]=cnt;
        cnt++;
    }

    Yes;

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}

