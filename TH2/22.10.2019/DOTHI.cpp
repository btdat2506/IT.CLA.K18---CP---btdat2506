#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

ll m, n, s, q_size, trace[100010], d[100010], q[100010];
vector <ll> edge[100010], cost[100010];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void dijisktra()
{
	priority_queue<ii, vector<ii>, cmp> pq;
	trace[s] = d[s] = 0;
	pq.push(ii(0, s));
	while (!pq.empty())
	{
		ll u = pq.top().y, du = pq.top().x;
		pq.pop();
		if (du != d[u]) continue;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > d[u] + cost[u][i])
			{
				d[v] = d[u] + cost[u][i];
				trace[v] = u;
				pq.push(ii(d[v], v));
			}
		}
	}
}

void process()
{
	For(i, 0, 100009)
	d[i] = INT64_MAX,
	trace[i] = 0;
	dijisktra();
	For(i, 1, n) cout << ((d[i] == INT64_MAX) ? -1 : d[i]) << ' ';
	cout << "\n";
	For(i, 1, q_size)
	{
		cout << "TU DINH " << s << " to " << q[i] << ": ";
		if (d[i] == INT64_MAX)
		{
			cout << -1 << "\n";
			continue;
		}
		ll track = q[i];
		stack <ll> st;
		while (track != 0)
		{
			st.push(track);
			track = trace[track];
		}
		while (!st.empty())
		{
			cout << st.top() << ' ';
			st.pop();
		}
		cout << "\n";
	}
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll a, b, r;
		cin >> a >> b >> r;
		edge[a].push_back(b);
		cost[a].push_back(r);
		edge[b].push_back(a);
		cost[b].push_back(r);
	}
	cin >> s >> q_size;
	For(i, 1, q_size) cin >> q[i];
}

int main()
{
	freopen("DOTHI.INP", "r", stdin);
	freopen("DOTHI.OUT", "w", stdout);
	input();
	process();
}