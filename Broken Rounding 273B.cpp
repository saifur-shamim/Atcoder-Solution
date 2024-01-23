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
    ll x,k;
    cin>>x>>k;

    ll a=1;
    if(x<=1)
    {
        x=0;
    }
    for(ll i=1; i<=k and x>0; i++)
    {
       // cout<<"i = "<<i<<endl;
        a*=10;

        ll div1=x/a;
        ll div2=div1;
        if(x%div1!=0) div1++;

        ll mn1=0,mn2=0,mn3=0;
        div2=max(0*1LL,div2);
        mn1=abs(div1*a-x);
        mn2=abs(div2*a-x);
        mn3=x;

        if(mn1<mn2 and mn1<mn3)
        {
            x=max(0*1LL,1LL*div1*a);
        }
        else if(mn2<mn1 and mn2<mn3)
        {
            x=max(0*1LL,1LL*div2*a);
        }
        else if (mn3<mn1 and mn3<mn2)
        {
            x=0;
        }
        else
        {
            x=x;
        }


        //cout<<" x= "<<x<<endl;
    }



    cout<<x<<endl;
    return 0;
}
