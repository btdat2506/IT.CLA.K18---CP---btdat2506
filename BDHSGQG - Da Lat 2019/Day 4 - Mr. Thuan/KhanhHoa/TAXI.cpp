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

const int N = 22;
const int VAL = (1 << 21);
int n;
int a[N];
int dp[N][VAL] , val[N][N];
bool f[VAL];

int ok(int mask)
{
    FOR(i , n / 2 + 1 , 2 * n)
    {
        if(((mask >> i) & 1) == 1 && ((mask >> (i - n / 2)) & 1) == 0)
            return false;
    }
    return true;
}

main()
{
    //freopen("TAXI.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp , 0x1f , sizeof(dp));
    cin >> n;
    FOR(i , 0 , n)
        FOR(j , 0 , n)
            cin >> val[i][j];
    dp[0][1] = 0;
    REP(mask , (1 << (n + 1)))
    {
        int r = 0;
        FOR(j , 0 , n)
            if((mask >> j) & 1)
                a[++r] = j;
        if(ok(mask))
        {
            f[mask] = true;
            FOR(u , 1 , r)
            {
                int x = a[u];
                int submask = mask ^ (1 << x);
                FOR(v , 1 , r)
                    if(u != v)
                {
                    int y = a[v];
                    if(f[mask])
                        dp[x][mask] = min(dp[x][mask] , dp[y][submask] + val[y][x]);
                }
            }
        }
    }
    int res = 1e10;
    FOR(i , 1 , n)
        res = min(res , dp[i][(1 << (n + 1)) - 1] + val[i][0]);
    cout << res;
}
