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
    int n,i;
    cin>>n;


    string s[n];

    for(i=0; i<n; i++)
    {
        cin>>s[i];
    }

    bool f=true;

    map<string,int>mp;
    for(i=0; i<n; i++)
    {
        char ch=s[i][0];

        mp[s[i]]++;
        if(mp[s[i]]==2)
        {
            f=false;
            break;
        }
        else if(ch=='D' or ch=='H' or ch=='S' or ch=='C')
        {
            if(s[i][1]=='2' or s[i][1]=='3' or s[i][1]=='4' or s[i][1]=='5' or s[i][1]=='6' or s[i][1]=='7' or s[i][1]=='8' or s[i][1]=='9')
            {
                continue;

            }
            else if(s[i][1]=='A' or s[i][1]=='T' or s[i][1]=='J' or s[i][1]=='Q' or s[i][1]=='K')
            {
                continue;
            }
            else
            {
                f=false;
                break;
            }
        }
        else
        {
            f=false;
            break;
        }




    }



    if(f) Yes;
    else No;

    return 0;
}
