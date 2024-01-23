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
    ll n,m,i;
    cin>>n>>m;

    ll ar[n+2];

    for(i=1; i<=n; i++)
    {
        cin>>ar[i];
    }

    map<ll,ll>mp;

    ll c,y,mx=0,pos=0;

    for(i=1; i<=m; i++)
    {
        cin>>c>>y;
        mp[c]=y;
        if(y>mx)
        {
            pos=c;
            mx=y;
        }
        else if(y==mx)
        {
            pos=max(c,pos);
        }
    }
    ll sum=0,cnt=0;
    //cout<<"pos = "<<pos<<endl;
    // cout<<"mx = "<<mx<<endl;
    for(i=1; i<=n; i++)
    {
        //cout<<"cnt = "<<cnt<<endl;
        //cout<<"i = "<<i<<endl;
        // cout<<"ar[i]+mp[cnt] = "<<ar[i]+mp[cnt+1]<<endl;
        //cout<<" n-i = "<<n-i<<endl;
        if((n-i)>=pos and i+cnt<=n and (ar[i]+mp[cnt+1])<(ar[i+cnt]+mx) and cnt==pos)
        {
            cnt=0;
        }
        else
        {
            cnt++;
            sum+=ar[i]+mp[cnt];

        }

        //cout<<" sum = "<<sum<<endl;
    }

    cout<<sum<<endl;

    return 0;
}
