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
#define     nn        cout<<endl
#define     negone    cout<<"-1\n"

// int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
// int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

//            { U  , D ,  L  , R , UL  , UR  , DL  , DR }

const dl PI=acos(-1);
const int inf=2e9;
const ll infll=900000000000000000;

bool f(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
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

/// Patience, persistence, and perspiration make an unbeatable combination for success.
/// The formula for success: rise early, work hard, strike oil.
/// Winners are not afraid of losing. But losers are. Failure is part of the process of success. People who avoid failure also avoid success.

    int tc=1;
    // cin>>tc;

    while(tc--)
    {

        ll  n,m,i,j;

        cin>>n>>m;

        ll plr[n+2],ar[m+2];

        mem(plr,-1);

        vpl v,v1;

        for(i=0; i<m; i++)
        {
            cin>>ar[i];

            v.pb({ar[i],i});
        }
        string s[n+2];

        ll mx=0,tmp=-1;

        for(i=0; i<n; i++)
        {
            cin>>s[i];

            ll cnt=0;

            for(j=0; j<m; j++)
            {
                if(s[i][j]=='o')
                {
                    cnt+=ar[j];
                }
            }

            v1.pb({cnt,i});

            if(cnt>0)
            {
                cnt+=i+1;
            }


            if(mx<cnt)
            {
                mx=cnt;
                tmp=i;
            }


        }



        sort(all(v));

        if(tmp==-1)
        {
            mx=v[0].F+1;
            tmp=0;
            plr[tmp]=1;
        }
        else
        plr[tmp]=0;

        reverse(all(v));

        sort(all(v1),f);


        //v1.dlt();

        for(i=0; i<n; i++)
        {

            ll in=v1[i].S;
            if(plr[in]!=-1)
            {
                continue;
            }


            ll val=v1[i].F;
            val+=in+1;


            ll tmp=0;

            //dbg(i,val,mx);
            for(j=0; j<m; j++)
            {
                if(val>mx)
                {
                    break;
                }
                ll ind=v[j].S;

                if(s[i][ind]=='x')
                {
                    val+=v[j].F;
                    tmp++;
                }
            }

            plr[in]=tmp;

            mx=val;

            //dbg("after",val,mx);

        }


        for(i=0; i<n; i++)
        {
            cout<<plr[i];
            nn;
        }

    }

    return 0;
}


/*

3 3
500 700 800
xxx
xxx
xxx

*/
