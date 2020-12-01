#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
typedef pair<ll, ll> ii;
 
struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};
 
ll m, n, k, d[110], trace[110];
vector <ll> edge[11000], cost[11000];
 
void dj(ll start, ll endd, bool query)
{
	For(i, 0, 102)
		d[i] = INT64_MAX,
		trace[i] = 0;
	priority_queue<ii, vector<ii>, cmp> pq;
	pq.push(ii(0, start));
	d[start] = trace[start] = 0;
	while (!pq.empty())
	{
		ll du = pq.top().x, u = pq.top().y;
		pq.pop();
		if (du != d[u]) continue;
		if (u == endd) break;
		for (ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > d[u] + cost[u][i])
			{
				d[v] = d[u] + cost[u][i];
				pq.push(ii(d[v], v));
				trace[v] = u;
			}
		}
	}
	if (!query) cout << d[endd] << endl;
	else
	{
		stack <ll> st;
		st.push(endd);
		while (st.top() != start)
		st.push(trace[st.top()]);
		cout << st.size();
		while (!st.empty())
		{
			cout << ' ' << st.top();
			st.pop();
		}
		cout << endl;
	}
}
 
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> n >> m >> k;
	For(i, 1, m)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back(v);
		edge[v].push_back(u);
		cost[u].push_back(c);
		cost[v].push_back(c);
	}
	For(i, 1, k)
	{
		ll query, u, v;
		cin >> query >> u >> v;
		dj(u, v, query);
	}
} 