#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b ; i++)
#define x first
#define y second

ll n, p[500][500], w[500], d[500], freed[500];

typedef pair<ll, ll> ii;

void prim(ll u)
{
	priority_queue <ii, vector<ii>, cmp> pq;
	d[u] = 0, freed[u] = 0;
	pq.push(ii(0, u));
	while (!pq.empty())
	{
		ll du = pq.top().x;
		u = pq.top.y;
		pq.pop();
		if (du != d[u]) continue;
		For(i, 0, n)
		{
			ll v1 = p[]
		}
	}
}

void process()
{

}

void input()
{
	cin >> n;
	For(i, 1, n+1)
	cin >> w[i];
	For(i, 1, n+1)
	For(j, 1, n+1)
	cin >> p[i][j];
}

int main()
{
	input();
	process();
}