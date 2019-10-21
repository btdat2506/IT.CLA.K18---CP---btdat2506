#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll x = 0, y = 0;
};

Data db[10000];
ll n;

void process()
{
	ll a = 0, b = 0;
	For(i, 2, n)
	{
		a += (db[i].x - db[i-1].x)*(db[i].y + db[i-1].y);
		b += __gcd(abs(db[i].x - db[i-1].x), abs(db[i].y - db[i-1].y));
	}
	a += (db[1].x - db[n].x)*(db[1].y + db[n].y);
	b += __gcd(abs(db[1].x - db[n].x), abs(db[1].y - db[n].y));
	cout << abs(a/2) + b/2 + 1;
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> db[i].x >> db[i].y;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}