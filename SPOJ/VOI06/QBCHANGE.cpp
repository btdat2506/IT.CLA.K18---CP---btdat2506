#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n, state[12][12];
queue <iii> qu;
char db[12][12];

/* 
- state = 0: còn nguyên
- state = 1: đang đi, nhưng chưa đi xong
- state = 2: đã xoá
*/

void process()
{
	For(i, 1, m)
	For(j, 1, n)
	if (!state)
	{
		qu.push(make_tuple(0, i, j));
		while (!qu.empty())
		{
			ll u, x, y;
			tie(u, x, y) = qu.front();
			

		}
	}
}

void input()
{
	For(i, 1, 11)
	For(j, 1, 11)
	db[i][j] = ' ';
	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}