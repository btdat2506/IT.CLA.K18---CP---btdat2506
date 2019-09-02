#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

struct dt
{
	ll u = 0, v = 0, c = 0;
};

ll n, m, ans = 0, parent[11000];
dt db[16000];

bool cmp (const dt &L, const dt &R)
{
	return L.c < R.c;
}

ll find_v(ll i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void kruskal()
{
	For(i, 0, n+1) parent[i] = i;
	For(i, 1, m+1)
	{
		ll u = find_v(db[i].u), v = find_v(db[i].v);
		if (u != v)
		{
			ans += db[i].c;
			parent[u] = v; //union
		}
	}
}

void process()
{
	sort(db+1, db+m+1, cmp);
	kruskal();
	cout << ans << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m+1)
	cin >> db[i].u >> db[i].v >> db[i].c;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
}