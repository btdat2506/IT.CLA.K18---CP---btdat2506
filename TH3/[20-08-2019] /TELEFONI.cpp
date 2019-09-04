#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll idx = 0, val = 0;
};

ll n, d, siz, ans;
dt db[300010];

void process()
{
	For(i, 2, siz)
		if (db[i].idx - db[i-1].idx > d)
		ans += (db[i].idx - db[i-1].idx - 1) / d;
	cout << ans << endl;
}

void input()
{
	cin >> n >> d;
	For(i, 1, n)
	{
		ll val;
		cin >> val;
		if (val == 1)
			siz++,
			db[siz].idx = i,
			db[siz].val = val;
	}
}

int main()
{
	freopen("TELEFONI.INP", "r", stdin);
	freopen("TELEFONI.OUT", "w", stdout);
	input();
	process();
}