#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define mp make_pair
#define For(i, a, b) for(ll i = a; i <= b; i++)

pair <ll, ll> fNode;
ll r, c, st_i, st_j, maxCnt;
bool db[1010][1010], visited[1010][1010];
int cd_x[5] = {0, 0, 1, 0, -1}, cd_y[5] = {0, 1, 0, -1, 0};

void dfs(ll u, ll v, ll cnt)
{
	visited[u][v] = 1;
	cnt++;
	For(i, 1, 4)
	{
		ll x = u + cd_x[i], 
		   y = v + cd_y[i];
		if (db[x][y] && !visited[x][y])
		{
			if (cnt >= maxCnt) 
				maxCnt = cnt,
				fNode = mp(x, y);
			dfs(x, y, cnt);
		}
	}
}

void process()
{
	maxCnt = 0;
	memset(visited, 0, sizeof(visited));
	dfs(st_i, st_j, 0);
	memset(visited, 0, sizeof(visited));
	dfs(fNode.first, fNode.second, 0);
	cout << "Maximum rope length is " << maxCnt << ". \n";
}

void input()
{
	cin >> c >> r;
	For(i, 1, r)
	For(j, 1, c)
	{
		char x;
		cin >> x;
		if (x == '.') db[i][j] = 1, st_i = i, st_j = j; else db[i][j] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		input();
		process();
	}
}