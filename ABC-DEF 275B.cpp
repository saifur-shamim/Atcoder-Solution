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

ll mod1(string num, ll a)
{
    // Initialize result
    ll res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < sz(num); i++)
        res = (res * 10 + (int)num[i] - '0') % a;

    return res;
}
string multiplyTwoNumbers(string num1, string num2) {
   if (num1 == "0" || num2 == "0") {
      return "0";
   }
   string product(num1.size() + num2.size(), 0);
   for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }
   if (product[0] == '0') {
      return product.substr(1);
   }
   return product;
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
   ll a,b,c,d,e,f;
   cin>>a>>b>>c>>d>>e>>f;
   ll m=998244353;


   string a1=to_string(a);

   string b1=to_string(b);

   string c1=to_string(c);


   string one=multiplyTwoNumbers(a1,b1);
   string two=multiplyTwoNumbers(one,c1);

   ll a11=mod1(two,m);

   string d1=to_string(d);

   string e1=to_string(e);

   string f1=to_string(f);


   string o=multiplyTwoNumbers(d1,e1);
   string tw=multiplyTwoNumbers(o,f1);

   ll b11=mod1(tw,m);


   cout<<(a11%m - b11%m)%m<<endl;

    return 0;
}
