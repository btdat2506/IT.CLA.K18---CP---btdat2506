#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll x = 0, y = 0;
};

Data m, db[20010];
ll n;

bool case1()
{
	For(i, 2, n)
	{
		ll a = db[i].x - db[i-1].x,
		   b = db[i].y - db[i-1].y,
		   c = db[i].x * db[i-1].y - db[i-1].x * db[i].y;
		if (a*m.x + b*m.y + c != 0) return 0;
	}
	return 1;
}

bool case2()
{
	For(i, 1, n) N.x = max(N.x, db[i].x);
	N.y = m.y;
}

void process()
{
	

}

void input()
{
	cin >> n >> m.x >> m.y;
	For(i, 1, n)
	cin >> db[i].x >> db[i].y;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}