//Sub đầu là dành cho các thuật toán tìm đường đi ngắn nhất thông thường, sẽ bị TLE vì độ phức tạp là N*(NlogN + MlogN)
//Chính vì vậy, để giải quyết subtask 2, cần phải có 1 cách làm khác đó là chuyển đồ thị có trọng số về đồ thị không trong số
//Lưu ý, phần process_dj và dịisktra hiện tại đang bị lỗi, và không có dự định sẽ fix

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.first > R.first;
	}
};

ll n, m, r1, r2, res_g, res_y, trace[10], g_path[1010], y_path[1010], d[1010];
char st[1010] = {'0'};
vector <ll> edge[6010];
bool visited[1010];

void dijisktra(ll node_start)
{
	priority_queue <ii, vector <ii>, cmp> pq;
	For(i, 0, n+5) d[i] = 1e9;
	d[node_start] = 0;
	pq.push(ii(0, node_start));
	while (!pq.empty())
	{
		ll du = pq.top().first,
		   u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for(ll v: edge[u])
		if (d[v] > d[u] + ((st[v] == st[u]) ? 1 : 3))
		{
			d[v] = d[u] + ((st[v] == st[u]) ? 1 : 3);
			pq.push(ii(d[v], v));
		}
	}
}

void process_dj()
{
	ll r1 = 0, r2 = 0;
	For(i, 1, n)
	if (st[i] == 'G') g_path[++r1] = i; else y_path[++r2] = i;
	For(i, 1, n)
	{
		dijisktra(i);
		For(j, 1, n) cout << d[j] << ' '; cout << "\n";
		if (st[i] == 'G')
			For(j, 1, r1) res_g += d[g_path[j]];
		else
			For(j, 1, r2) res_y += d[y_path[j]];
	}
	cout << (res_g >> 1) << ' ' << (res_y >> 1);
}

void process() //ý tưởng là dùng bfs chuyển đồ thị có trọng số về đồ thị không trọng số
{
	ll r1 = 0, r2 = 0;
	For(i, 1, n)
	if (st[i] == 'G') g_path[++r1] = i; else y_path[++r2] = i;
	queue <ii> qu;
	For(i, 1, n)
	{
		memset(visited, 0, sizeof(visited));
		memset(d, 0, sizeof(d));
		//cout << endl << i << endl;
		qu.push(ii(i, 0));
		visited[i] = 1;
		while (!qu.empty())
		{
			ll u = qu.front().first, cnt = qu.front().second;
			//cout << u << ' ' << cnt << endl;
			qu.pop();
			if (cnt > 0)
			{
				qu.push(ii(u, --cnt));
				continue;
			}
			for(ll v: edge[u])
			if (!visited[v])
			{
				visited[v] = 1;
				if (st[v] != st[u])
					d[v] = d[u] + 4;
				else
					d[v] = d[u] + 1;
				qu.push(ii(v, d[v]));
			}
		}
		if (st[i] == 'G')
			For(j, 1, r1) res_g += d[g_path[j]];
		else
			For(j, 1, r2) res_y += d[y_path[j]];
	}
	cout << (res_g >> 1) << ' ' << (res_y >> 1);
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) cin >> st[i];
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("GYALPHA.INP", "r", stdin);
	freopen("GYALPHA.OUT", "r", stdin);
	input();
	process();
}
