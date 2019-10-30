#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
};

ll n;
dt db[3010];

struct cmp
{
	bool operator () (const dt &L, const dt &R)
	{
		return abs((L.x2 - L.x1) * (L.y2 - L.y1)) > abs((R.x2 - R.x1) * (R.y2 - R.y1));
	}
};

int main()
{
	freopen("HCN.INP", "r", stdin);
	freopen("HCN.OUT", "w", stdout);
	cin >> n;
	For(i, 1, n) cin >> db[i].x1 >> db[i].y1 >> db[i].x2 >> db[i].y2;
	priority_queue <dt, vector<dt>, cmp> pq;
	For(i, 1, n) pq.push(db[i]);
	while (!pq.empty())
	{
		cout << pq.top().x1 << ' ' << pq.top().y1 << ' ' << pq.top().x2 << ' ' << pq.top().y2 << "\n";
		pq.pop();
	}
}