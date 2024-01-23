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

bool f(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
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
    int n,x,y,z,i;
    cin>>n>>x>>y>>z;

    int ar[n+1],br[n+1];

    vpi math,eng,tot;
    vi v;
    for(i=1; i<=n; i++)
    {
        cin>>ar[i];
        math.PB({ar[i],i});
    }

    for(i=1; i<=n; i++)
    {
        cin>>br[i];
        eng.PB({br[i],i});
        tot.PB({ar[i]+br[i],i});

    }

    sort(all(math),f);
    sort(all(eng),f);
    sort(all(tot),f);
/*
    reverse(all(math));
    reverse(all(eng));
    reverse(all(tot));   */

    map<int,int>mp;

    for(i=0;i<x;i++)
    {
        v.PB(math[i].S);
        mp[math[i].S]++;
    }

    for(i=0;i<y;i++)
    {
        if(mp[eng[i].S])
        {
            y++;
            continue;
        }

        v.PB(eng[i].S);
        mp[eng[i].S]++;
    }

    for(i=0;i<z;i++)
    {
         if(mp[tot[i].S])
        {
            z++;
            continue;
        }

        v.PB(tot[i].S);
        mp[tot[i].S]++;
    }
    sort(all(v));

    for(auto it:v)
    {
        cout<<it<<"\n";
    }
    return 0;
}
