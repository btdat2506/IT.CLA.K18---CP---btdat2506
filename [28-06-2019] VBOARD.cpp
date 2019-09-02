#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, q, white[600][600], black[600][600], pros_white[600][600],  pros_black[600][600];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	For(i, 1, n)
	For(j, 1, n)
	{
		ll x;
		cin >> x;
		if ((i + j) % 2 == 0) white[i][j] = x; else black[i][j] = x;
	}
	For(i, 1, n)
	For(j, 1, n)
	{
		pros_white[i][j] = pros_white[i-1][j] + pros_white[i][j-1] - pros_white[i-1][j-1] + white[i][j];
		pros_black[i][j] = pros_black[i-1][j] + pros_black[i][j-1] - pros_black[i-1][j-1] + black[i][j];
	}
	cin >> q;
	For(i, 1, q)
	{
		ll a, b, u, v;
		cin >> a >> b >> u >> v;
		ll cnt_white = (pros_white[u][v] - pros_white[a-1][v] - pros_white[u][b-1]) + pros_white[a-1][b-1];
		ll cnt_black = (pros_black[u][v] - pros_black[a-1][v] - pros_black[u][b-1]) + pros_black[a-1][b-1];
		cout << abs(cnt_black - cnt_white) << endl;
	}
}