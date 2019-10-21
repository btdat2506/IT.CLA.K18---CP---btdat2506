#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct point
{
	ll a = 0, b = 0, c = 0;
};

ll n;
point db[2000];

void process()
{
	For(i, 1, n) cout << db[i].a << ' ' << db[i].b << ' ' << db[i].c << "\n";
	For(i, 1, i-1)
	For(j, 2, n)
	if (i != j)
	{
		if (db[i].a * db[j].a + db[i].b * db[j].b + db[i].c * db[j].c < 0)
		cout << i << ' ' << j << "\n";
	}
}

void input()
{
	ll a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		n++;
		db[n].a = d - b,
		db[n].b = c - a;
		db[n].c = b*c - a*d;
	}
}

int main()
{
	freopen("dl.inp", "r", stdin);
	freopen("kq.out", "w", stdout);
	input();
	process();
}