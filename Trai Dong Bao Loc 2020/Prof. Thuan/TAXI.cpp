#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define INF (ll)1e12
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)
#define f0(i, n) for(ll i = 0; i <= n; i++)

ll n, m, c[22][22], nxt[22][22], f[22][(1 << 20) + 20];
vector <ll> road;

/* 
- Input sai
- define sai (<=, <)
- Xác định vị trí trong bitset sai
 */

void optimize_road()
{
	f0(i, n)
	f0(j, n)
		nxt[i][j] = j;
	f0(i, n)
		nxt[i][i] = i;
	f0(k, n)
	f0(i, n)
	f0(j, n)
	if (c[i][j] > c[i][k] + c[k][j])
		c[i][j] = c[i][k] + c[k][j],
		nxt[i][j] = nxt[i][k];
}

ll TSP(ll u, ll msk)
{	
	if (f[u][msk] > -1) return f[u][msk];
	if (msk == 0) return c[u][0];

	f[u][msk] = INF;
	For(i, 1, n)
	if (msk & (1 << (i - 1)) && (i <= m || !(msk & (1 << (i - m - 1)))))
	{
		ll tmsk = msk ^ (1 << (i - 1));
		f[u][msk] = min(f[u][msk], c[u][i] + TSP(i, tmsk));
	}
	return f[u][msk];
}

bool findRoad(ll u, ll msk)
{
	road.push_back(u);

	if (msk == 0) 
	{
		road.push_back(0);
		return 1;
	}

	For(i, 1, n)
	{
		ll tmsk = msk ^ (1 << (i - 1));
		if (msk & (1 << (i - 1)))
		if (i <= m || !(msk & (1 << (i - m - 1))))
		if (f[u][msk] == c[u][i] + f[i][tmsk])
		if (f[i][tmsk] != -1)
		{
			if (findRoad(i, tmsk)) return 1;
		}
	}
	return 0;
}

vector <ll> remake_road()
{
	vector <ll> t;
	f0(i, road.size()-1)
	{
		t.push_back(road[i]);
		for(ll tmp = nxt[road[i]][road[i+1]]; tmp != road[i+1]; tmp = nxt[tmp][road[i + 1]])
			t.push_back(tmp);
		//t.push_back(road[i+1]);
	}
	return t;
}

void process()
{
	optimize_road();
	ll MSK = (1 << n) - 1;
	f0(i, n)
	f0(j, MSK)
	f[i][j] = -1;
	ll res = INF;
	For(i, 1, m)
	res = min(res, c[0][i] + TSP(i, MSK ^ (1 << (i - 1))));
	cout << res << "\n";
	road.push_back(0);
	For(i, 1, m)
	if (res == c[0][i] + f[i][MSK ^ (1 << (i - 1))])
	{
		if (findRoad(i, MSK ^ (1 << (i - 1)))) break;
	}
	road.push_back(0);
	road = remake_road();
	cout << road.size() << "\n";
	for(ll v: road)
	cout << v << ' ';
}

void input()
{
	cin >> n;
	m = n; n = m << 1;
	f0(i, n)
	f0(j, n)
	cin >> c[i][j];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("TAXI.INP", "r", stdin);
	freopen("TAXI.OUT", "w", stdout);
	input();
	process();
}