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
#define oo 1e10
#define int long long
#define eps 1e-8

const int N = 1e4 + 5;
int n , k , m;
int dp[N][3] , ans[N];

main()
{
    //freopen("BINARYLIST.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    dp[1][1] = 1;
    dp[1][0] = 1;
    dp[0][1] = 1;
    k--;
    FOR(i , 2 , n)
    {
        if(dp[i - 1][1] + dp[i - 1][0] <= k)
            dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
        else
            dp[i][1] = 1e10;
        FORD(j , i - 1 , max((ll)0 , i - m + 1))
        {
            if(dp[i][0] + dp[j][1] <= k)
                dp[i][0] += dp[j][1];
            else
            {
                dp[i][0] = 1e10;
                break;
            }
        }
    }

    int cnt = 0;
    FORD(i , n , 1)
    {
        int res = 0;
        ans[i] = 0;
        cnt++;
        FORD(j , i - 1 , max((ll)0 , i - m + cnt))
            res += dp[j][1];
        if(res <= k)
        {
            cnt = 0;
            k -= res;
            ans[i] = 1;
        }
    }

    if(k != 0)
        cout << "-1";
    else
    {
        FORD(i , n , 1)
            cout << ans[i] << " ";
    }
}
