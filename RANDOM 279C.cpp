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

    int r,c,i,j;
    cin>>r>>c;

    string s1[r],s2[r];

    for(i=0; i<r; i++)
    {
        cin>>s1[i];
    }

    for(i=0; i<r; i++)
    {
        cin>>s2[i];
    }

    vector<vector<char>>v1(c),v2(c);

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            v1[i].PB(s1[j][i]);
            v2[i].PB(s2[j][i]);
        }
    }

    sort(all(v1));
    sort(all(v2));


    bool f=true;
    for(i=0;i<c;i++)
    {
     //cout<<" v1 "<<v1[i]<<endl;
        //cout<<" v2 "<<v2[i]<<endl;
        if(v1[i]!=v2[i])
        {
            f=false;
            break;
        }
    }

    if(f) Yes;
    else No;

    return 0;
}

