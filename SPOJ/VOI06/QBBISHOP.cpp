#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
typedef tuple<ll, ll, ll> iii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

const ll INF = (ll)1e12;
bool visited[210][210], poor[210][210];
ll n, m, p, q, s, t, d[210][210], inQueue[210][210], path[2] = {-1, 1};

ll get_state(ll a, ll b)
{
	if (a == -1)
	{
		if (b == -1) return 1;
		if (b == 1) return 2;
	}
	if (a == 1)
	{
		if (b == -1) return 3;
		if (b == 1) return 4;
	}
	return -1; //error
}

void process()
{
	f0(i, n+3)
	f0(j, n+3)
	d[i][j] = INF;
	queue <iii> qu;
	qu.push(make_tuple(((ll) 0), p, q));
	d[p][q] = 0;
	inQueue[p][q] = 1;
	while (!qu.empty())
	{
		ll state; ii u;
		tie(state, u.x, u.y) = qu.front(); qu.pop(); inQueue[u.x][u.y] = 0;
		if (u.x == s && u.y == t) break;
		f0(i, 2)
		f0(j, 2)
		{
			ll a = u.x + path[i],
			   b = u.y + path[j];
			if (a > 0 && b > 0 && a <= n && b <= n && !poor[a][b])
			{
				if (get_state(path[i], path[j]) == state)
				{
					d[a][b] = d[u.x][u.y];
					//cout << a << ' ' << b << "\n";	
					if (!inQueue[a][b])
					{
						inQueue[a][b] = 1;
						qu.push(make_tuple(get_state(path[i], path[j]), a, b));
					}
				}
				else
				if (d[a][b] > d[u.x][u.y] + 1)
				{
					d[a][b] = d[u.x][u.y] + 1;
					//cout << d[a][b] << ' ' << a << ' ' << b << '\n';
					if (!inQueue[a][b])
					{
						inQueue[a][b] = 1;
						qu.push(make_tuple(get_state(path[i], path[j]), a, b));
					}
				}
			}
		}
	}
	if (d[s][t] != INF)
		cout << d[s][t] << "\n";
	else
		cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> n >> m >> p >> q >> s >> t;
	ll r, c;
	while (m--)
	{
		cin >> r >> c;
		poor[r][c] = 1;
	}
	process();
	//cout << (double) ((double)clock()/(double)(CLOCKS_PER_SEC)) << "\n";
}