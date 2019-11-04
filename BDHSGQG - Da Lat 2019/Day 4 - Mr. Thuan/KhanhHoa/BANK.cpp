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

const int N = 1e4 + 5;
const int VAL = 50;
int n , m;
ii a[N];
int dp[N][VAL];

bool cmp(ii a , ii b)
{
    return a.se < b.se;
}

main()
{
    //freopen("BANK.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i , 1 , n)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1 , a + 1 + n , cmp);
    FOR(i , 1 , n)
    {
        dp[i][0] = max(dp[i - 1][0] , a[i].fi);
        FOR(j , 1 , m)
        {
            dp[i][j] = dp[i - 1][j];
            if(j <= a[i].se)
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + a[i].fi);
        }
    }
    int res = 0;
    FOR(i , 0 , m)
        res = max(res , dp[n][i]);
    cout << res << "\n";
}
