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
    ll r,c,i,j;
    cin>>r>>c;

    string mat[r];
    for(i=0; i<r; i++)
    {
        cin>>mat[i];

    }
    ll tot=r*c;
    i=0,j=0;
    bool f=true;
    ll ans=-1;
    ll l,r1;
    ll cnt=0;
    while(1)
    {

        l=i;
        r1=j;
        if(mat[i][j]=='*')
        {
            break;
        }
        else if(mat[i][j]=='R')
        {
            mat[i][j]='*';

            j=j+1;

        }

        else if(mat[i][j]=='L')
        {
            mat[i][j]='*';
            j=j-1;
        }
        else if(mat[i][j]=='D')
        {
            mat[i][j]='*';
            i=i+1;
        }
        else
        {
            mat[i][j]='*';
            i=i-1;
        }

        if(i<0 or j<0 or i>=r or j>=c)
        {
            f=false;
            i=l;
            j=r1;
            break;
        }


    }

    if(f) cout<<ans<<endl;
    else cout<<i+1<<" "<<j+1<<endl;

    return 0;
}
