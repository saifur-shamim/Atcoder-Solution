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
    // cin>>tc;

    while(tc--)
    {
        ll r,c,i,j,k;

        cin>>r>>c>>k;

        char ch[r+2][c+2];

        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                cin>>ch[i][j];
            }
        }


        ll ans=infll;

        ll pr[c+2]= {0},zr[c+2]= {0};

        for(i=1; i<=r; i++)
        {


            for(j=1; j<=c; j++)
            {
                if(j==1)
                {
                    pr[0]=0;
                    zr[0]=0;
                }

                zr[j]=0;
                if(ch[i][j]=='x')
                {
                    pr[j]=pr[j-1]-1;
                }
                else
                {
                    pr[j]=pr[j-1]+1;

                    if(ch[i][j]=='o')
                    {
                        zr[j]=1;
                    }
                }

                zr[j]+=zr[j-1];
            }


            for(j=1; j<=c; j++)
            {
                if(ch[i][j]=='x')
                {
                    continue;
                }

                ll bnd=j+k-1;

                if(bnd<=c and (pr[bnd]-pr[j])==(k-1))
                {
                    ll ache=zr[bnd]-zr[j-1];

                    ll lagbe=(k-ache);

                    ans=min(ans,lagbe);
                }
            }
        }



        ll pr1[r+2]= {0},zr1[r+2]= {0};

        for(i=1; i<=c; i++)
        {


            pr1[0]=0;
            zr1[0]=0;


            for(j=1; j<=r; j++)
            {
                zr1[j]=0;
                if(ch[j][i]=='x')
                {
                    pr1[j]=pr1[j-1]-1;
                }
                else
                {
                    pr1[j]=pr1[j-1]+1;

                    if(ch[j][i]=='o')
                    {
                        zr1[j]=1;
                    }
                }

                zr1[j]+=zr1[j-1];
            }


            for(j=1; j<=r; j++)
            {
                if(ch[j][i]=='x')
                {
                    continue;
                }

                ll bnd=j+k-1;

                if(bnd<=r and (pr1[bnd]-pr1[j])==(k-1))
                {
                    ll ache=zr1[bnd]-zr1[j-1];

                    ll lagbe=(k-ache);

                    ans=min(ans,lagbe);
                }
            }
        }

        if(ans==infll)
        {
            mone;
        }
        else
        {
            cout<<ans;
            nl;
        }


    }

    return 0;
}
