#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll a = 0, b = 0, c = 0;
};

ll n;
Data db[100010];

bool cmp1(const Data &L, const Data &R)
{
	if (L.a == R.a) 
		if (L.b == R.b) return L.c < R.c;
		else
		if (L.c == R.c) return L.b < R.b;
	return L.a < R.a;
}

ll res(bool a, bool b, bool c)
{

}

void process()
{
	sort(db+1, db+1+n, cmp1);
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i].a >> db[i].b >> db[i].c;
}

int main()
{
	freopen("ONLYONE.INP", "r", stdin);
	freopen("ONLYONE.OUT", "w", stdout);
	input();
	process();
}