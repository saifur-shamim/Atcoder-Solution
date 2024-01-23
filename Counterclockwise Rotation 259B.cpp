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
double sq(double s)
{
    return (s*s);
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
    double a,b,d;
    cin>>a>>b>>d;

    double r=pow(a,2);
    r+=pow(b,2);
    r=sqrt(r);
    cout<<" r = "<<r<<endl;
    double a1=atan(b/a);
    a1=a1*180/3.1415;
    cout<<"a1= "<<a1<<endl;
    a1+=d;
 cout<<"a1= "<<a1<<endl;
    double x=cos(a1)*(3.1415/180);
    x*=r;
    double y=r*sin(a1);
    cout<<x<<" "<<y<<endl;

    return 0;
}
