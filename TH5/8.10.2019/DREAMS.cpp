#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll a = 0, b = 0;
};

ll n;
Data db[1000010];

bool cmp(const Data &L, const Data &R)
{
	if (L.a == R.a) return L.b > R.b;
	return L.a > R.a;
}

ll bSearch(ll l, ll r, ll x)
{
	ll mid = (l + r) / 2;
	while (l != r)
	{
		
	}
	return mid;
}

void process()
{
	sort(db+1, db+1+n, cmp);
	{

	}
}

void input()
{
	cin >> n >> p >> q;
	For(i, 1, n)
	cin >> db[i].a >> db[i].b;
}

int main()
{
	freopen("DREAMS.INP", "r", stdin);
	freopen("DREAMS.OUT", "w", stdout);
	input();
	process();
}