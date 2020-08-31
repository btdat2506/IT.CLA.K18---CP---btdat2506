#include <bits/stdc++.h>

using namespace std;

typedef int ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x, h[1010], s[1010], dp[1010][100010];

void process()
{
    For(i, 1, n)
    For(j, 1, x)
    if (j >= h[i])
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]] + s[i]);
    else
        dp[i][j] = dp[i-1][j];
    cout << dp[n][x] << "\n";
}

void input()
{
    cin >> n >> x;
    For(i, 1, n)
    cin >> h[i];
    For(i, 1, n)
    cin >> s[i];
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}