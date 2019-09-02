#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, r, d[10010];
vector <ll> edge[10010], cost[10010], leng[10010];

struct node
{
	ll v, l, c;
	node (ll _v = 0, ll _l = 0, ll _c = 0) 
	{
		v = _v, l = _l, c = _c;
	}
};

struct cmp
{
	bool operator () (const node &L, const node &R)
	{
		return L.c > R.c;
	}
};

void dj()
{
	priority_queue <node, vector<node>, cmp> pq;
	pq.push(node(1, 0, 0));
	while (pq.size() != 0)
	{
		ll u = pq.top().v, 
		   du = pq.top().l, 
		   w = pq.top().c;
		pq.pop();
		if (du >= d[u]) continue;
		d[u] = du;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i],
			   l = leng[u][i],
			   c = cost[u][i]; 
			if (w + c > k) continue;
			pq.push(node(v, l + d[u], w + c));
		}
	}
}

void process()
{
	dj();
	if (d[n] == INT64_MAX)
		cout << -1 << endl;
	else
		cout << d[n] << endl;
}

void input()
{
	cin >> k >> n >> r;
	For(i, 1, r)
	{
		ll s, d, l, t;
		cin >> s >> d >> l >> t;
		edge[s].push_back(d);
		cost[s].push_back(t);
		leng[s].push_back(l);
	}
}

void init()
{
	k = n = r = 0;
	For(i, 0, 10009)
	{
		edge[i].clear();
		cost[i].clear();
		leng[i].clear();
		d[i] = INT64_MAX;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	For(i, 1, t)
	{
		init();
		input();
		process();
	}
}