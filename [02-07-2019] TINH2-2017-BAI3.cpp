#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll num = 0, start = 0, finish = 0;
};

vector < vector <bool> > res;
dt x[63000], y[63000];
ll ans, siz_x, siz_y, m, n, db[250][250], trace[63000], matchX[63000], matchY[63000];

void precalc()
{
	For(i, 1, m)
	{
		ll j_pre = 1, j = 1;
		while (j < n)
		{
			while (db[i][j_pre] == 2 && j_pre < n) j_pre++; j = j_pre;
			while (db[i][j+1] != 2 && j < n) j++;
			bool kt = 1;
			For(k, j_pre, j) 
			if (db[i][k] == 2) 
			{
				kt = 0; 
				break;
			}
			if (kt)
			{
				siz_x++,
				x[siz_x].num = i;
				x[siz_x].start = j_pre,
				x[siz_x].finish = j,
				j_pre = j+1;
			}
		}
	}
	For(j, 1, n)
	{
		ll i_pre = 1, i = 1;
		while (i < m)
		{
			while (db[i_pre][j] == 2 && i_pre < m) i_pre++; i = i_pre;
			while (db[i+1][j] != 2 && i < m) i++;
			bool kt = 1;
			For(k, i_pre, i) 
			if (db[k][j] == 2) 
			{
				kt = 0; 
				break;
			}
			if (kt)
			{
				siz_y++,
				y[siz_y].num = j;
				y[siz_y].start = i_pre,
				y[siz_y].finish = i,
				i_pre = i+1;
			}
		}
	}
	res.resize(siz_x + 10);
	For(i, 0, siz_x+9)
	res[i].resize(siz_y + 10);
	For(i, 0, siz_x+2)
	For(j, 0, siz_y+2)
	res[i][j] = 0;
}

ll bfs()
{
	queue <ll> q;
	For(i, 1, siz_x)
	if (!matchX[i]) q.push(i);
	memset(trace, 0, sizeof(trace));
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		for(ll i = 1; i <= siz_y; i++)
		{
			if (trace[i] == 0 && res[u][i] == 1)
			{
				trace[i] = u;
				if (matchY[i] == 0) return i;
				else q.push(matchY[i]);
			}
		}
	}
	return 0;
}

void enlarge(ll v)
{
	ll next = 0, u = 0;
	for(; v; v = next)
	{
		u = trace[v],
		next = matchX[u],
		matchX[u] = v,
		matchY[v] = u;
	}
}

void process()
{
	precalc();
	For(i, 1, siz_x)
	For(j, 1, siz_y)
	if (x[i].num >= y[j].start && 
		x[i].num <= y[j].finish && 
		y[j].num >= x[i].start && 
		y[j].num <= x[i].finish)
	{
		if (db[x[i].num][y[j].num] != 1)
			res[i][j] = 1;
	}
	while (ll u = bfs()) enlarge(u);
	For(i, 1, siz_x)
	if (matchX[i] != 0) ans++;
	cout << ans << endl;
}

void input()
{
	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}