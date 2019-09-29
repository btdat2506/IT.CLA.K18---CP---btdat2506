#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll t;

ll visit(ll u)
{
	if (visited[u] != t)
		visited[u] = t;
	else
		return 0;
	for(ll v: db[u])
	if (!Assigned[v] || visit(Assigned[v]))
	{
		Assigned[v] = u;
		return 1;
	}
	return 0;
}

void process()
{
	ll cnt = 0;
	For(i, 1, m)
	{
		t++;
		cnt += visit(i);
	}
	cout << cnt << "\n";
	For(i, 1, n)
	if (Assigned[i])
		cout << Assigned[i] << ' ' << i << "\n";
}

void input()
{
	cin >> m >> n;
	ll x, y;
	while (cin >> x >> y)
		db[x].push_back(y);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}