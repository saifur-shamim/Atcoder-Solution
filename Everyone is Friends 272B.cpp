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

    map<pair<int,int>,int>mp;

    int ar[n+2];

    for(i=0; i<m; i++)
    {
        int tm;
        cin>>tm;
        for(int j=0; j<tm; j++)
        {
            cin>>ar[j];
        }


        for(int j=0; j<tm; j++)
        {
            for(int k=j+1; k<tm; k++)
            {
                int mn,mx;
                mn=min(ar[j],ar[k]);
                mx=max(ar[j],ar[k]);

                mp[ {mn,mx}]++;

            }
        }
    }


    for(i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(mp[ {i,j}]>=1)
            {
                continue;
            }
            else
            {
                No;
                return 0;
            }

        }
    }

    Yes;
    return 0;
}
