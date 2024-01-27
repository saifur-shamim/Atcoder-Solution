///Bismillahir Rahmanir Rahim
///Happy Coding

/*

     * * * *             *              *  * * * * * *   *            *   * * * * *
    *                   * *             *  *             *            *   *         *
    *                  *   *            *  *             *            *   *          *
    *                 *     *           *  *             *            *   *           *
    *                *       *          *  *             *            *   *           *
     *              *         *         *  * * * * * *   *            *   *          *
       *           *           *        *  *             *            *   * * * * * *
         *        *             *       *  *             *            *   *  *
          *      * * * * * * * * *      *  *             *            *   *    *
           *    *                 *     *  *             *            *   *      *
           *   *                   *    *  *             *            *   *        *
           *  *                     *   *  *              *          *    *          *
    * * * *  *                       *  *  *                * * * * *     *            *


*/


#include<bits/stdc++.h>

using namespace std;


#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

///order_of_key (val) : Number of items strictly smaller than val.
///find_by_order(x) : x-th element in a set (zero based index).

typedef  long long ll;
typedef  long int li;
typedef  unsigned long long ull;
typedef  double dl;
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<pii>vpi;
typedef  vector<pll> vpl;

#define     pb        push_back
#define     dlt       pop_back
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
#define     nl        cout<<endl
#define     mone      cout<<"-1\n"
#define    For(i,a,b)  for(i = a; i <= b; i++)
#define    Forr(i,a,b)  for(i = a; i >= b; i--)

// int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
// int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

//            { U  , D ,  L  , R , UL  , UR  , DL  , DR }

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

/// Patience, persistence, and perspiration make an unbeatable combination for success.
/// The formula for success: rise early, work hard, strike oil.
/// Winners are not afraid of losing. But losers are. Failure is part of the process of success. People who avoid failure also avoid success.

    int tc=1;
    //cin>>tc;

    while(tc--)
    {


        ll n,i;
        cin>>n;

        ll q[n+2],a[n+2],b[n+2];


        For(i,1,n) cin>>q[i];
        For(i,1,n) cin>>a[i];
        For(i,1,n) cin>>b[i];

        ll mx1=-1,mx2=-1;

        ll mn1=infll,mn2=infll;

        for(i=1; i<=n; i++)
        {
            if(a[i]==0) continue;

            if(a[i]>q[i])
            {
                mn1=infll;
                break;
            }

            mn1=min(mn1,q[i]/a[i]);
        }

        for(i=1; i<=n; i++)
        {
            if(b[i]==0) continue;

            if(b[i]>q[i])
            {
                mn2=infll;
                break;
            }

            mn2=min(mn2,q[i]/b[i]);
        }

       // dbg(mn1,mn2);
        if(mn1!=infll)
            mx1=mn1;

        if(mn2!=infll)
            mx2=mn2;

        //dbg(mx1,mx2);
        ll fmx=max(mx1,mx2);

        if(fmx==-1)
        {
            cout<<"0\n";
            return 0;
        }

        ll ans=fmx;
        if(fmx==mx1 and mx2!=-1)
        {

            for(ll j=fmx; j>1; j--)
            {
                ll tmp=infll;
                bool f=true;
                for(i=1; i<=n; i++)
                {
                   //dbg(j);
                    ll rem=q[i]-(a[i]*j);

                    if(b[i]==0 or (rem==0 and a[i]==0))
                    {
                        tmp=tmp;
                        continue;
                    }
                    ll pos=rem/b[i];

                   // dbg(rem,pos,b[i]);

                   if(rem<=0 and b[i]!=0)
                    {
                        //dbg("2nd");
                        f=false;
                        break;
                    }
                    else
                        tmp=min(tmp,pos);
                }



                if(tmp!=infll)
                    ans=max(ans,j+tmp);

                    //dbg(ans);
            }


        }
        else if(fmx==mx2 and mx1!=-1)
        {
            //dbg("else");

            for(ll j=fmx; j>=1; j--)
            {
                ll tmp=infll;
                bool f=true;
                for(i=1; i<=n; i++)
                {
                  //  dbg(i);
                    ll rem=q[i]-(b[i]*j);

                    if(a[i]==0 or (rem==0 and a[i]==0))
                    {
                        tmp=tmp;
                        continue;
                    }
                    ll pos=rem/a[i];

                   // dbg(rem,pos,a[i]);

                   if(rem<=0 and a[i]!=0)
                    {
                        //dbg("2nd");
                        f=false;
                        break;
                    }
                    else
                        tmp=min(tmp,pos);

                    //dbg(j,i,tmp);
                }


                if(tmp!=infll)
                    ans=max(ans,j+tmp);
            }


        }

        cout<<ans;nl;

    }

    return 0;
}
