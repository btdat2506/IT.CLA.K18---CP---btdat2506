#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 1e6 + 10;
ll n, x, c[N], dp[N];

void process()
{
    For(i, 1, x)
    For(j, 1, n)
    if (i - c[j] >= 0)
        dp[i] = min(dp[i], dp[i-c[j]] + 1);
    cout << ((dp[x] != 1e12) ? dp[x] : -1) << "\n";
}

void input()
{
    cin >> n >> x;
    fill(dp+1, dp+x+5, 1e12);
    For(i, 1, n)
    {
        cin >> c[i];
        dp[c[i]] = 1;
    }
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}