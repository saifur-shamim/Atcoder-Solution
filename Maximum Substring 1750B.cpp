#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nl endl

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n,i;
        cin>>n;

        string s;
        cin>>s;

        ll one=0,z=0,mx1=0,mx2=0;
        for(i=0; i<n; i++)
        {
            ll cnt1=0,cnt2=0;
            if(s[i]=='1')
            {
                while(s[i]=='1' and i<n)
                {

                    one++;
                    cnt1++;
                    i++;
                }

                i--;
                mx1=max(mx1,cnt1);

            }
            else
            {
                while(s[i]=='0' and i<n)
                {

                    z++;
                    cnt2++;
                    i++;
                }

                i--;
                mx2=max(mx2,cnt2);
            }
        }

        cout<<max({one*z,mx2*mx2,mx1*mx1})<<endl;


    }
}
