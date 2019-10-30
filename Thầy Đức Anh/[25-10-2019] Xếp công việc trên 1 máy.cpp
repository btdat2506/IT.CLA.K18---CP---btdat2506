#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair<ll, ll> ii;

struct Data
{
	ll idx = 0, t = 0, c = 0;
};

bool cmp (const Data &L, const Data &R)
{
	if (L.t == R.t) return L.c > R.c;
	return L.t > R.t;
}

struct cmp1
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

ll n;
Data db[8010];

int main()
{
	freopen("WORK.INP", "r", stdin);
	freopen("WORK.OUT", "w", stdout);
	while (cin >> db[n].t >> db[n].c) 
		db[n].idx = n,
		n++;
		n--;
	sort(db+1, db+1+n, cmp);
	priority_queue <ii, vector <ii>, cmp1> pq;
	For(i, 1, n)
	{
		ll j = i, val = db[i].val, idx = db[i].idx;
		while (db[j+1].t == db[i].t)
		{
			j++;
			db[j].t--;
			if (db[j].val > val)
			{
				val = db[j].val;
				idx = db[j].idx;
			}
		}
		pq.push(ii(idx, val));
	}
	while (!pq.empty())
	{
		cout << "Gio thu " << pq.top().first << " thuc hien viec " << pq.top().second << "\n";
		res += pq.top().second;
		pq.pop();
	}
	cout << "Tong so tien thu duoc: " << res << "\n";
}