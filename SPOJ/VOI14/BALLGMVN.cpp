#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define x first
#define y second
#define fi first
#define se second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n;
double dx, dy;
pair <double, ll> a[1010];
ii pt1[1010], pt2[1010];

//quên tắt debug

void process()
{
	//cout << setprecision(6) << fixed;
	For(k, 1, n)
	{
		//2 điểm bên tập dưới
		For(i, 1, n)
		{
			a[i].se = i;
			dx = pt1[k].x - pt2[i].x;
			dy = pt1[k].y - pt2[i].y;
			if (dy == 0) 
				a[i].fi = 1e14; 
			else 
				a[i].fi = dx / dy;
		}
		sort(a+1, a+1+n);
		For(i, 2, n)
		if (!(a[i].fi != a[i-1].fi))
		{
			cout << k << ' ' << n+a[i-1].se << ' ' << n+a[i].se << "\n";
			return;
		}

		//2 điểm ở tập trên
		For(i, 1, n)
		{
			a[i].se = i;
			dx = pt2[k].x - pt1[i].x;
			dy = pt2[k].y - pt1[i].y;
			if (dy == 0) 
				a[i].fi = 1e14; 
			else 
				a[i].fi = dx / dy;
		}
		sort(a+1, a+1+n);
		For(i, 2, n)
		if (!(a[i].fi != a[i-1].fi))
		{
			cout << n+k << ' ' << a[i-1].se << ' ' << a[i].se << "\n";
			return;
		}
	}
	//quên in -1
	cout << -1 << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> pt1[i].x >> pt1[i].y;
	For(i, 1, n)
	cin >> pt2[i].x >> pt2[i].y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}