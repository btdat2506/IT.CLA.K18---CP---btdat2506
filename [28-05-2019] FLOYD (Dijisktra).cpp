#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair<ll, ll> ii;

clock_t start = clock();

bool freed[200], req[1100];
ll n, m, k, st[1100], ed[1100], d[200], trace[200];
vector <ll> edge[5000], cost[5000];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void dj(ll start, ll finish, bool query)
{
	memset(freed, 0, sizeof(freed));
	priority_queue <ii, vector<ii>, cmp> pq;
	pq.push(ii(0, start));
	freed[start] = 1; trace[start] = 0;
	while (pq.size() != 0)
	{
		ll u = pq.top().y, v = pq.top().x;
		pq.pop();
		if (d[u] != v) continue;
		if (u == finish) break;
		for(ll i = 0; i < edge[u].size(); i++)
		if (d[i] > d[u] + cost[u][i])
		{
			trace[i] = u;
			d[i] = d[u] + cost[u][i];
			pq.push(ii(d[i], i));
		}
	}
	if (query)
	{
		stack<ll> route;
		ll track = finish;
		while (track != 0)
		{
			route.push(track);
			track = trace[track];
		}
		cout << route.size();
		while (route.size() != 0)
		{
			cout << ' ' << route.top();
			route.pop();
		}
		cout << endl;
	}
	else cout << d[finish] << endl;
}

void process()
{
	For(i, 1, k)
	dj(st[i], ed[i], req[i]);
}

void input()
{
	For(i, 0, 150)
	{
		freed[i] = 1;
		d[i] = INT64_MAX;
		trace[i] = 0;
	}
	cin >> n >> m >> k;
	For(i, 1, m)
	{
		ll u = 0, v = 0, c = 0;
		cin >> u >> v >> c;
		edge[u].push_back(v);
		edge[v].push_back(u);
		cost[u].push_back(c);
		cost[v].push_back(c);
	}

	For(i, 1, k)
	cin >> req[i] >> st[i] >> ed[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
}