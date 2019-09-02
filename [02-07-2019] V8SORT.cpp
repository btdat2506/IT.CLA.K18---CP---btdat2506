#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

string start = "", finish = "";
ll n = 1, db[10], cost[10][10];
vector <ll> d;

typedef pair<ll, string> ii;

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

ll gethash(string inp)
{
	ll res = 0;
	For(i, 1, n)
	res = res * 10 + (inp[i] - '0');
	return res;
}

void dj()
{
	priority_queue<ii, vector<ii>, cmp> pq;
	pq.push(ii(0, start));
	d[gethash(start)] = 0;
	while (!pq.empty())
	{
		ll du = pq.top().x; string u = pq.top().y;
		pq.pop();
		if (u == finish) break;
		For(i, 1, n)
		For(j, 1, n)
		if (i != j)
		{
			string v = u;
			swap(v[i], v[j]);
			ll hash_u = gethash(u),
			   hash_v = gethash(v);
			if (d[hash_v] > d[hash_u] + cost[i][j])
			{
				d[hash_v] = d[hash_u] + cost[i][j];
				pq.push(ii(d[hash_v], v));
			}
		}
	}
	cout << d[gethash(finish)] << endl;
}

void process()
{
	ll temp[20];
	For(i, 1, n) temp[i] = db[i];
	sort(temp+1, temp+1+n);
	For(i, 1, n)
	db[i] = lower_bound(temp+1, temp+n+1, db[i]) - (temp+1) + 1;
	d.resize(20000000);
	For(i, 1, 20000000) d[i] = INT64_MAX;
	start = finish = " ";
	For(i, 1, n) 
	{
		start.push_back(db[i] + '0');
		finish.push_back(i + '0');
	}
	dj();
}

void input()
{
	while (cin >> db[n], db[n] != 0) n++;
	if (!db[n]) n--;
	For(j, 2, n)
	cin >> cost[1][j];
	For(i, 2, n)
	For(j, 1, n)
	cin >> cost[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}