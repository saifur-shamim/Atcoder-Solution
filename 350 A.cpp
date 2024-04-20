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



int main()
{




    /*
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    */

/// Patience, persistence, and perspiration make an unbeatable combination for success.
/// The formula for success: rise early, work hard, strike oil.
/// Winners are not afraid of losing. But losers are. Failure is part of the process of success. People who avoid failure also avoid success.



    string s;
    cin>>s;

    int dig=s[3]-'0';

    dig*=10;

    dig+=s[4]-'0';

    dig*=10;

    dig+=s[5]-'0';


    if(s[0]=='A' and s[1]=='B' and s[2]=='C' and dig!=316 and dig>0 and dig<350)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }



    return 0;
}

