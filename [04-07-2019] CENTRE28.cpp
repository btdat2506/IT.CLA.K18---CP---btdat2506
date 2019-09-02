#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fore(i, a, b) for(ll i = a; i < b; i++)
 
typedef pair<ll, ll> ii;
 
clock_t start = clock();
 
bool visited[40000];
ll n, m, siz, d[40000];
vector <ll> edge[100010], cost[100010], trace[40000];
 
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
	d[1] = 0;
	trace[1].push_back(0);
	while (!pq.empty())
	{
		ll du = pq.top().x, u = pq.top().y;
		pq.pop();
		if (du > d[u]) continue;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > d[u] + cost[u][i])
			{
				trace[v].clear();
				trace[v].push_back(u);
				d[v] = d[u] + cost[u][i];
				pq.push(ii(d[v], v));
			}
			if (d[v] == d[u] + cost[u][i]) trace[v].push_back(u);
		}
	}
}
 
void process()
{
	For(i, 1, 35000) d[i] = INT64_MAX;
	dj();
	queue <ll> q;
	visited[n] = visited[1] = 1;
	q.push(n);
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		if (u == 1) continue;
		Fore(i, 0, trace[u].size()) 
		{
			q.push(trace[u][i]);
			visited[trace[u][i]] = 1;
		}
	}
	priority_queue <ll, vector<ll>, greater<ll> > pq;
	For(i, 1, n)
	if (!visited[i]) 
	{
		pq.push(i);
		siz++;
	}
	cout << siz << endl;
	while (pq.size() != 0)
	{
		cout << pq.top() << endl;
		pq.pop();
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
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input();
	process();
	//cout << "time: " << double(clock() - start) / CLOCKS_PER_SEC << endl;
}