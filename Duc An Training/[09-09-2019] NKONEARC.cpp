#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool ck = 1;
ll x = -1, y = -1, n, m, in_deg[2010], out_deg[2010];

void process()
{
	For(i, 1, n)
	{
		if (y != -1 && !in_deg[i]) ck = 0;
		else
		if (!in_deg[i]) y = i;

		if (x != -1 && !out_deg[i]) ck = 0;
		else
		if (!out_deg[i]) x = i;
	}
	if (!ck) cout << "NO" << "\n";
	else
	cout << "YES" << "\n" << x << ' ' << y << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		in_deg[y]++;
		out_deg[x]++;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}