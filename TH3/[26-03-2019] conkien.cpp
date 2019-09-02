#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second

typedef pair <ll, ll> ii;

clock_t start = clock();

vector <vector <ll> > db, xuli;
ll m, n, ans = INT64_MIN;

void test()
{
	For(i, 1, m)
	{
		For(j, 1, n)
		cout << xuli[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void makesize()
{
	db.resize(m+10);
	For(i, 0, m+9) db[i].resize(n+10);
	For(i, 0, m) db[i][0] = 0;
	For(j, 0, n) db[0][j] = 0;
}

void PrintResult()
{
	For(j, 1, n)
	ans = max(ans, xuli[m][j]);
	cout << ans << endl;
}

void qhd()
{
	For(i, 2, m-1)
	{
		For(j, 1, n)
		xuli[i][j] += max(xuli[i][j-1], xuli[i-1][j]);
	}
	For(j, 1, n) xuli[m][j] += xuli[m-1][j];
}

void bfs()
{
	queue <ii> hangdoi;
	hangdoi.push(ii(2, 1));
	ll u = 2, v = 1;
	while (hangdoi.size() != 0)
	{
		u = hangdoi.front().x, v = hangdoi.front().y;
		hangdoi.pop();
		//tinh tong
		if (u != m) xuli[u][v] += max(xuli[u][v-1], xuli[u-1][v]);
		if (u == m) xuli[u][v] += xuli[u-1][v];
		//push vi tri
		if (v != n && u != m) hangdoi.push(ii(u, v+1));
		if (u != m) hangdoi.push(ii(u+1, v));
		//test();
	}
}

void process()
{
	xuli = db;
	//qhd();
	bfs();
	PrintResult();
}

void input()
{
	cin >> m >> n;
	makesize();
	For(i, 1, m)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	freopen("CONKIEN.INP", "r", stdin);
	freopen("CONKIEN.OUT", "w", stdout);
	input();
	process();
	cout << "TIME: " << double(clock() - start) / CLOCKS_PER_SEC << endl;
}