#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define eps 1e-8

const int N = 3e5 + 5;
int n , h , res , ans;
ii a[N];

main()
{
    //reopen("GLIDER.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    FOR(i , 1 , n)
        cin >> a[i].fi >> a[i].se;

    int res = 0;
    int j = 1;
    res = a[1].se - a[1].fi;
    FOR(i , 1 , n)
    {
        while(j <= n)
        {
            if(h <= (a[j + 1].fi - a[j].se))
                break;
            else
            {
                if(j != n)
                {
                    h -= (a[j + 1].fi - a[j].se);
                    res += (a[j + 1].fi - a[j].se);
                }
                j++;
                res += (a[j].se - a[j].fi);
            }
        }

        ans = max(res + h , ans);
        h += (a[i + 1].fi - a[i].se);
        res -= (min(res , a[i + 1].fi - a[i].fi));
    }
    cout << ans << "\n";
}
