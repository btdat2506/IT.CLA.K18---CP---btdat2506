#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ii a, b, c;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	ll k = (b.x - a.x)*(c.y - b.y) - (b.y - a.y)*(c.x - b.x);
	if (k == 0) 
		cout << "TOWARDS" << "\n";
	if (k < 0)
		cout << "RIGHT" << "\n";
	if (k > 0)
		cout << "LEFT" << "\n";
}