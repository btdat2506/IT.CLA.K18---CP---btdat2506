#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, nxt[1010], dp[1010][1010];
string s, t;

void process()
{
    n = s.length(), m = t.length();
    s = ' ' + s;
    t = ' ' + t;
    For(i, 1, n)
    {
        ll bal = 0;
        nxt[i] = -1;
        For(j, i, n)
        {
            if (s[j] == '.') bal--; else bal++;
            if (bal == 0) 
            {
                nxt[i] = j;
                break;
            }
        }
    }

    For(i, 1, n+1)
    For(j, 1, m+1)
    dp[i][j] = 1e9;
    dp[1][1] = 0;

    For(i, 1, n)
    For(j, 1, m+1)
    {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        if (j <= m && s[i] == t[j])
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        if (s[i] != '.' && nxt[i] != -1)
            dp[nxt[i] + 1][j] = min(dp[nxt[i] + 1][j], dp[i][j]);
    }

    cout << dp[n+1][m+1] << "\n";
}

void input()
{
    cin >> s >> t;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}