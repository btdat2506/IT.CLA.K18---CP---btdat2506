#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define x first
#define y second
#define INF 1e12
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, m, k, d[110][110];
char db[110][110];
ii source, final, t[110], direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


bool check(ll x1, ll y1)
{
	return x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && db[x1][y1] != '#';
}

void bfs(ll x1, ll y1)
{
	//bool inqueue[110][110];
	f0(i, n+4)
	f0(j, m+4)
	d[i][j] = INF;
	queue <ii> qu;
	qu.push({x1, y1});
	d[x1][y1] = 0;
	while (!qu.empty())
	{
		ll u1 = qu.front().x, v1 = qu.front().y;
		//inqueue[u1][v1] = 0;
		qu.pop();
		f0(i, 4)
		if (check(u1 + direction[i].x, v1 + direction[i].y) && 
			d[u1 + direction[i].x][v1 + direction[i].y] > d[u1][v1] + 1)
		{
			d[u1 + direction[i].x][v1 + direction[i].y] = d[u1][v1] + 1;
			//if (!inqueue[u1 + direction[i].x][v1 + direction[i].y])
			//{
			//	inqueue[u1 + direction[i].x][v1 + direction[i].y] = 1;
				qu.push({u1 + direction[i].x, v1 + direction[i].y});
			//}
		}

	}
}

void process()
{
	bfs(source.x, source.y);
	vector < vector<ll> > dp(k, vector <ll> (4, INF));
	f0(i, 4)
	if (check(t[0].x + direction[i].x, t[0].y + direction[i].y))
		dp[0][i] = d[t[0].x + direction[i].x][t[0].y + direction[i].y];
	f0(i, k - 1)
	f0(j, 4)
	if (check(t[i].x + direction[j].x, t[i].y + direction[j].y))
	{
		bfs(t[i].x + direction[j].x, t[i].y + direction[j].y);
		f0(q, 4)
		if (check(t[i + 1].x + direction[q].x, t[i + 1].y + direction[q].y))
		dp[i + 1][q] = min(dp[i + 1][q], dp[i][j] + d[t[i + 1].x + direction[q].x][t[i + 1].y + direction[q].y]);
	}
	bfs(final.x, final.y);
	ll ans = INF;
	f0(i, 4)
	if (check(t[k - 1].x + direction[i].x, t[k - 1].y + direction[i].y))
	ans = min(ans, dp[k - 1][i] + d[t[k - 1].x + direction[i].x][t[k - 1].y + direction[i].y]);
	if (ans == INF) 
		ans = -1;
	cout << ans << "\n";
}

void input()
{
	cin >> n >> m >> k;
	f0(i, n)
	f0(j, m)
	{
		cin >> db[i][j];
		if (db[i][j] == 'S') source.x = i, source.y = j;
		if (db[i][j] == 'F') final.x = i, final.y = j;
	}
	f0(i, k)
	cin >> t[i].x >> t[i].y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}