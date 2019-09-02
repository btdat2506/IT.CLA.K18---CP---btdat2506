 #include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

clock_t start = clock();

bool visited[40000];
ll n, m, cnt = 0, d[40000], trace[40000];
vector <ll> edge[100010], cost[100010];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void dj()
{
	priority_queue <ii, vector<ii>, cmp> pq;
	pq.push(ii(0, 1));
	d[1] = trace[1] = 0;
	while (pq.size() != 0)
	{
		ll u = pq.top().y,
		   du = pq.top().x;
		pq.pop();
		if (du != d[u]) continue;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > d[u] + cost[u][i])
			{
				trace[v] = u;
				d[v] = d[u] + cost[u][i];
				pq.push(ii(d[v], v));
			}
		}
	}
}

void process()
{
	dj();
	ll z = trace[n];
	visited[n] = 1;
	while (z != 0)
	{
		visited[z] = 1;
		z = trace[z];
	}
	queue <ll> q;
	For(i, 1, n)
	if (!visited[i]) 
	q.push(i);
	cout << q.size() << endl;
	while (q.size() != 0)
	{
		cout << q.front() << endl;
		q.pop();
	}
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y, c;
		cin >> x >> y >> c;
		edge[x].push_back(y);
		edge[y].push_back(x);
		cost[x].push_back(c);
		cost[y].push_back(c);
	}
}

void init()
{
	For(i, 1, 10009)
	{
		d[i] = INT64_MAX;
		trace[i] = 0;
		visited[i] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	input();
	process();
}