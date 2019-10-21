#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define For(i, a, b) for(int i = a; i <= b; i++)

typedef pair <int, int> ii;

int m, n, db[500][500], d[500][500], visited[500][500], 
cd_x[5] = {0, 0, 1, 0, -1}, cd_y[5] = {0, 1, 0, -1, 0};

void process()
{
	queue <ii> qu;
	qu.push(ii(1, 1));
	For(i, 1, m)
	For(j, 1, n) d[i][j] = INT_MAX;
	d[1][1] = 0;
	while (!qu.empty())
	{
		int u = qu.front().x,
		    v = qu.front().y;
		qu.pop();
		For(i, 1, 4)
		{
			int u1 = u + cd_x[i] * db[u][v],
			    v1 = v + cd_y[i] * db[u][v];
			if (u1 >= 1 && u1 <= m && v1 >= 1 && v1 <= n)
			if (d[u1][v1] > d[u][v] + 1)
			{	
				qu.push(ii(u1, v1));
				d[u1][v1] = d[u][v] + 1;
			}
		}
	}
	if (d[m][n] != INT_MAX) 
		cout << d[m][n] << "\n";
	else
		cout << -1 << "\n";
}

void input()
{
	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	{
		char x;
		cin >> x;
		db[i][j] = x - '0';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}