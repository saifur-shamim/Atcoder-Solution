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
    string s1,s2;
    cin>>s1>>s2;

    int n1=0;
    int n2=sz(s2);

    int i=0,j=0,cnt1,cnt2;
    string ans="";
    while(n1<n2)
    {
        cnt1=1,cnt2=0;

        while(s1[i]==s1[i+1])
        {
            cnt1++;
            i++;
        }

        if(s1[i]==s2[j]) cnt2++;

        while(s2[j]==s2[j+1])
        {
            cnt2++;
            j++;
        }

        //cout<<" cnt1 = "<<cnt1<<"\ncnt2 = "<<cnt2<<endl;
        if(cnt1==cnt2)
        {
            for(int k=0;k<cnt1;k++)
            {
                ans+=s2[j];
            }
           n1+=cnt1;

        }
        else if(cnt1>=2 and cnt2>=cnt1)
        {
            for(int k=0;k<cnt2;k++)
            {
                ans+=s2[j];
            }

            n1+=cnt2;
        }
        else
        {
            break;
        }

        //cout<<"ans = "<<ans<<endl;
        i++;
        j++;

        //cout<<" n1 = "<<n1<<" n2 = "<<n2<<endl;

    }

    if(ans==s2) Yes;
    else No;

    return 0;
}
