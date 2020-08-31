#include <bits/stdc++.h>

using namespace std;

typedef int ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, dp[5010][5010];
string t, p;

//cách giải LCS chỉ dành cho bài toán chỉ có 2 trường hợp là xoá và thêm

void process()
{
    For(i, 0, n)
    fill(dp[i], dp[i]+5005, 1e9);
    dp[0][0] = 0;
    For(i, 0, n)
    For(j, 0, m)
    {
        if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
		if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (t[i-1] != p[j-1]));
    }
    cout << dp[n][m] << "\n";
}

void input()
{
    cin >> t >> p;
    n = t.length();
    m = p.length();
    /* t = ' ' + t;
    p = ' ' + p; */
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}