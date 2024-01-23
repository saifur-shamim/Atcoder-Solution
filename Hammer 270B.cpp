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
    int x,y,z;

    cin>>x>>y>>z;

    int ans=0;
    if(x>0)
    {
        if(y<0) ans=x;
        else
        {
            if(z>y or z>x) ans=-1;
            else if(z<0)
            {
                ans=2*abs(z)+x;
            }
            else
            {
                ans=x;
            }
        }
    }
    else
    {
        if(y>0) ans=abs(x);
        else
        {
            if(z<0 and (abs(z)>abs(y) or abs(z)>abs(x))) ans=-1;
            else if(z<0)
            {
                ans=abs(x);
            }
            else
            {
                ans=2*abs(z)+abs(x);
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
