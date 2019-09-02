#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair <ll, ll> ii;

ll n, a[400], p[400][400], d[400], ans = 0;

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void process()
{
	priority_queue <ii, vector<ii>, cmp> pq;
	For(i, 1, n) 
	{
		d[i] = a[i];
		pq.push(ii(d[i], i));
	}
	while (!pq.empty())
	{
		ll u = pq.top().y, du = pq.top().x;
		pq.pop();
		if (du > d[u]) continue;
		ans += d[u],
		d[u] = -1;
		For(i, 1, n)
		{
			if (u != i && d[i] != -1 && d[i] > p[u][i]) 
			{
				d[i] = p[u][i];
				pq.push(ii(d[i], i));
			}
		}
	}
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> a[i];
	For(i, 1, n)
	For(j, 1, n)
	cin >> p[i][j];
	For(i, 1, n) p[i][i] = INT64_MIN;
}

int main()
{
	freopen("EPS.INP", "r", stdin);
	freopen("EPS.OUT", "w", stdout);
	input();
	process();	
}