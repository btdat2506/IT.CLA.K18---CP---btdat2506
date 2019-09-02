#include <bits/stdc++.h>

using namespace std;

#define idx first
#define value second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair <ll, ll> ii;

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.value < R.value;
	}
};

ll n, s1 = 0, s2 = 0;
bool visited[40000] = {};
priority_queue <ii, vector<ii>, cmp> pq1, pq2;

void process()
{
	bool i = 1;
	ll z = n;
	while (z > 0)
	if (i)
	{
		ll vt = pq1.top().idx, gt = pq1.top().value;
		pq1.pop();
		if (!visited[vt])
			visited[vt] = 1,
		 	i = 0,
		 	z--,
			s1 += gt;
		if (pq1.empty() && pq2.empty()) break;
	}
	else 
	if (!i)
	{
		ll vt = pq2.top().idx, gt = pq2.top().value;
		pq2.pop();
		if (!visited[vt])
			visited[vt] = 1,
		 	i = 1,
		 	z--,
			s2 += gt;
		if (pq1.empty() && pq2.empty()) break;
	}
	cout << s1 - s2 << endl;	
}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		ll x, y;
		cin >> x >> y;
		pq1.push(ii(i, x));
		pq2.push(ii(i, y));
	}
}

int main()
{
	freopen("DELCOL.INP", "r", stdin);
	freopen("DELCOL.OUT", "w", stdout);
	input();
	process();	
}