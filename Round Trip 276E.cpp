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

const int mx = 500000;
char c[mx][mx];
int n, m, cnt;
bool vis[mx][mx];
map<pair<int,int>,pair<int,int> > par;
int in1,in2;
int dx[] = { -1, +1, 0, 0 };
int dy[] = { 0, 0, -1, +1 };

bool dfs ( int x, int y )
{
    vis[x][y] = 1;
    cnt++;

    for ( int i = 0; i < 4; i++ )
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if(x1==in1 and y1==in2 and par[{x1,y1}].F!=in1 and par[{x1,y1}].S!=in2 and cnt>=4)
        {
            return true;
        }
        if ( x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] == '.' && vis[x1][y1] == 0 )
        {
            par[ {x1,y1}]={x,y};

            dfs ( x1, y1 );

        }
    }

    cnt--;

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
    cnt=0;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c[i][j];

            if(c[i][j]=='S')
            {
                in1=i;
                in2=j;
            }
        }
    }

    bool f=false;
    if(dfs(in1,in2)==true){
        Yes;
    }

    else No;

    return 0;
}
