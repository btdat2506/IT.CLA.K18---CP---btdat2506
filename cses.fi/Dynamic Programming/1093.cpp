#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define MOD (ll) (1e9 + 7)
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, t, dp[510][130000];

void process()
{
    if ((n * (n + 1) / 2) % 2 != 0)
    {
        cout << 0 << "\n";
        return;
    }
    t = n * (n + 1) / 4;
    dp[0][0] = 1;
    For(i, 1, n-1)
    For(x, 0, t)
    if (x - i >= 0)
        dp[i][x] = (dp[i-1][x] + dp[i-1][x-i]) % MOD;
    else
        dp[i][x] = dp[i-1][x];
    cout << dp[n-1][t] << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}