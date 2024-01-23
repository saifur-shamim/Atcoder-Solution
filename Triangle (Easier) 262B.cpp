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
    int n,m,i;
    cin>>n>>m;
    int cnt=0;

    vector<vector<int>>v(n+1,vector<int>(n+1));


    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        v[a][b]=1;
        v[b][a]=1;
    }

    for(i=1;i<=n;i++)
    {
        //cout<<"size of v "<<i<<" "<<sz(v[i])<<endl;
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(v[i][j] and v[j][k] and v[k][i])
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
