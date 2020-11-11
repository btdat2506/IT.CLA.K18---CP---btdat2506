#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, a1, b1;
double ans = 1e5;
ii a[1010];

ll sqr(ll a)
{
	return a*a;
}

void process()
{
	/* //cout << setprecision(4);
	//cout << fixed; */
	For(i, 1, n-1)
	{
		ans = min(ans, (double) ((a[i].y - a[i+1].y)*a1 + 
								(a[i+1].x - a[i].x)*b1 + 
								a[i].x*a[i+1].y - a[i+1].x*a[i].y) / 
								sqrt(sqr(a[i].y - a[i+1].y) + sqr((a[i+1].x - a[i].x))));
	}
	For(i, 1, n)
	ans = min(ans, (double) sqrt(sqr(a[i].x - a1) + sqr(a[i].y - b1)));
	cout << ans << "\n";
}

void input()
{
	cin >> n;
	cin >> a1 >> b1;
	For(i, 1, n)
	cin >> a[i].x >> a[i].y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}