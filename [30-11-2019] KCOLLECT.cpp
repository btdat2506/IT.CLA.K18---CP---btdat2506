#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++) 

ll m, n, cnt, ComponentCnt, freed[110][110], num[110][110], low[110][110];
char db[110][110];
stack <ii> st;

void mark(ll x, ll y, ll i, ll j)
{
	if (1 <= x && x <= m)
	if (1 <= y && y <= n)
	if (!freed[x][y] && db[x][y] != '#')
	{
		if (!num[x][y])
			low[i][j] = min(low[i][j], num[x][y]);
		else
		{
			low[i][j] = min(low[i][j], low[x][y]);
			visit(x, y);
		}
	}
}

void visit(ll x, ll y)
{
	cnt++;
	num[x][y] = low[x][y] = cnt;
	st.push(ii(x, y));
	visit(x, y + 1, x, y);
	visit(x + 1, y, x, y);
	if (db[x][y] == 'W') mark(x, y - 1, x, y);
	if (db[x][y] == 'N') mark(x - 1, y, x, y);
	if (low[x][y] == num[x][y])
	{
		ComponentCnt++;
		do
		{
			/* code */
		} while (/* condition */);
		
	}
}


void process()
{
	For(i, 1, m)
	For(j, 1, n)
	if (!num[i][j] && db[i][j] != '#') visit(i, j);
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