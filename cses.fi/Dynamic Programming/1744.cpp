#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, dp[510][510];

void process()
{
    For(i, 1, n)
    For(j, 1, m)
    dp[i][j] = 1e5;
    //===========================================================
    For(i, 1, n)
    For(j, 1, m)
    if (i == j)
        dp[i][j] = 0;
    else
    {
        For(k, 1, j)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        For(k, 1, i)
            dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
    }
    cout << dp[n][m] << '\n';
}

void input()
{
    cin >> n >> m;
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}