#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, p, q, a[110], b[110], dp[110][110];

ll min(ll a, ll b, ll c)
{
	return min(min(a, b), c);
}

void process()
{
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	For(i, 1, n)
	dp[i][0] = p*i;
	For(i, 1, m)
	dp[0][j] = q*i;
	For(i, 1, n)
	For(j, 1, m)
	dp[i][j] = min(dp[i-1][j-1] + abs(a[i] - b[j]), dp[i-1][j] + p, dp[i][j-1] + q);
	cout << dp[n][m] << "\n";
}

void input()
{
	cin >> n >> m >> p >> q;
	For(i, 1, n)
	cin >> a[i];
	For(i, 1, m)
	cin >> b[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}