#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define x first
#define y second
#define mp make_pair
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

ll n, db[210][210];
queue <ii> qu;
bool inq [210][210];
vector <ii> a[50000];

void process()
{
	while (!qu.empty())
	{
		ii u = qu.front();
		qu.pop();
		ll du = db[u.x][u.y];
		inq[u.x][u.y] = 0;
		for(ii k: a[u.y])
		if (db[u.x][k.x] > du + k.y)
		{
			db[u.x][k.x] = du + k.y;
			if (!inq[u.x][k.x])
			{
				inq[u.x][k.x] = 1;
				qu.push(mp(u.x, k.x));
			}
		}
	}
	For(i, 1, n)
	/*if (db[i][i] >= db[0][0])
		cout << -1 << "\n";
	else*/
		cout << db[i][i] << "\n";
}


void input()
{
	cin >> n;
	ll u, v, c;
	while (cin >> u >> v >> c)
	{
		db[u][v] = c,
		a[u].push_back(mp(v, c)),
		inq[u][v] = 1;
		qu.push(mp(u, v));
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}