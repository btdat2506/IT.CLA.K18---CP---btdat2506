#include <bits/stdc++.h>

using namespace std;

typedef int16_t ll;
typedef pair<ll, ll> ii;
#define x first
#define y second
#define For(i, a, b) for (ll i = a; i <= b; i++)

string s, t, ans;
ll n, m, dp[3][10010];

void solve(ll i)
{
    if (i > n || i < 2)
        return;
    swap(dp[0], dp[1]);
    For(j, 1, m) if (s[i] == t[j])
        dp[1][j] = dp[0][j - 1] + 1;
    else dp[1][j] = max(dp[0][j], dp[1][j - 1]);
}

void build(ll i, ll j)
{
    if (i > n || j > m)
        return;
    if (s[i] == t[j])
    {
        ans += s[i];
        solve(i + 1);
        build(i + 1, j + 1);
    }
    else
    {
        if (dp[0][j] == dp[1][j])
        {
            solve(i + 1);
            build(i + 1, j);
        }
        else
            build(i, j + 1);
    }
}

void process()
{
    n = s.length();
    m = t.length();
    s = ' ' + s;
    t = ' ' + t;
    For(i, 1, 2)
    {
        For(j, 1, m) if (s[i] == t[j])
            dp[1][j] = dp[0][j - 1] + 1;
        else dp[1][j] = max(dp[0][j], dp[1][j - 1]);
        swap(dp[0], dp[1]);
    }
    build(1, 1);
    cout << ans << "\n";
}

void input()
{
    cin >> s >> t;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}