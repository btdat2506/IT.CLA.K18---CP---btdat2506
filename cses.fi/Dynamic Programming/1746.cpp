#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define MOD (ll) (1e9 + 7)
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, ans, arr[100010], dp[100010][110];

void process()
{
    if (arr[1] == 0) 
        fill(dp[1]+1, dp[1]+m+1, 1);
    else
        dp[1][arr[1]] = 1;
    For(i, 2, n)
    if (arr[i] == 0)
    {
        For(j, 1, m)
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j + 1]) % MOD;
    }
    else
        dp[i][arr[i]] = (dp[i-1][arr[i]-1] + dp[i-1][arr[i]] + dp[i-1][arr[i] + 1]) % MOD;
    For(x, 1, m)
        ans = (ans + dp[n][x]) % MOD;
    cout << ans << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}