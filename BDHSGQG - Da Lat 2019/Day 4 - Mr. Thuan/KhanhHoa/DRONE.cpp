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
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long

const int N = 3e3 + 5;
int n , k;
int val[N] , dist[N];
int dp[N][105];

main()
{
    //freopen("DRONE.inp","r",stdin);
    //freopen("DRONE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    FOR(i , 1 , n)
        cin >> val[i];
    FOR(i , 1 , n)
         cin >> dist[i];
    memset(dp , -1 , sizeof(dp));
    dp[1][0] = val[1];
    FOR(i , 2 , n)
    {
        FOR(j , 1 , k)
        {
            FORD(x , i - 1 , max((ll)1 , i - 50))
                if(dp[x][j - 1] > 0 && x + dist[x] >= i)
                    dp[i][j] = max(dp[i][j] , dp[x][j - 1] + val[i]);
        }
    }
    int res = -1;
    FOR(i , 1 , k)
        res = max(res , dp[n][i]);
    cout << res << "\n";
}
