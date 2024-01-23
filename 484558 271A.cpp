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


string base_convert(int n, int b)
{
    map<int,char>mp;
    char ch='A';
    for(int i=10; i<=15; i++)
    {
        mp[i]=ch;
        ch++;
    }
    if (n == 0) return "0";
    int x = 0;
    int power = 1;
    while (power * b <= n)
    {
        power *= b;
        x++;
    }
    string d;
    while (power > 0)
    {
        int k = n / power;

        if(k>=10)
        {
            d += mp[k];
        }
        else
        {

            d += k + '0';
        }

        n -= k * power;
        power /= b;
    }
    return d;
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

    ll n;
    cin>>n;

    cout<< base_convert(n,16)<<endl;

    return 0;
}
