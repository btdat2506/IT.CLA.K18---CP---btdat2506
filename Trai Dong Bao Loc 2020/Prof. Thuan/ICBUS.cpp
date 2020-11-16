#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
typedef tuple<ll, ll, ll, ll> iiii;
#define INF (ll)1e12
#define c first
#define di second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

const ll N = 5010;
ll n, k, d[N], cnt[N], f[N][N];
ii a[N];
vector <ll> edge[N];

void bfs_time_count(ll u)
{
	bool inQueue[N]; memset(inQueue, false, sizeof(inQueue));
	f0(i, n+5) cnt[i] = INF;
	queue <ll> qu;
	qu.push(u);
	cnt[u] = 0;
	inQueue[u] = 1;
	while (!qu.empty())
	{
		ll u = qu.front(); qu.pop(); inQueue[u] = 0;
		for(ll v: edge[u])
		if (cnt[v] > cnt[u] + 1)
		{
			cnt[v] = cnt[u] + 1;
			if (!inQueue[v])
			{
				inQueue[v] = 1;
				qu.push(v);
			}
		}
	}
}

struct cmp 
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.first > R.first;
	}
};

void dj()
{
	priority_queue <ii, vector<ii>, cmp> pq;
	//pq.push(ii(a[1].di, 1));
	f0(i, n+5) f[i][a[i].di] = INF;
	f[1][a[1].di] = a[1].c;
	while (!pq.empty())
	{
		ll u = pq.top().second, du = pq.top().first;
		pq.pop();
		for(ll v: edge[u])
		{
			
			f[v][du-1] = min(f[v][du-1], f[u][du]);
			f[v][du-1] = f[v][a[v].di] = min(f[v][du-1], f[u][du] + a[v].c);
			f[v][a[v].di] = min(f[v][a[v].di], f[u][du] + a[v].c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	For(i, 1, n)
	cin >> a[i].c >> a[i].di;
	For(i, 1, k)
	{
		ll u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dj();
}