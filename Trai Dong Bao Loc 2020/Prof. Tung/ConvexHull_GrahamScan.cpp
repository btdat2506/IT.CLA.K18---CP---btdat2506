#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define f0(i, n) for(ll i = 0; i < n; i++)
typedef pair<double, double> pdd;

//Kattis: Convex Hull

const int N = 10010;
int n;
pdd a[N];

bool cw(pdd p1, pdd p2, pdd p3)
{
	return p1.x*(p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) < 0;
}

bool ccw(pdd p1, pdd p2, pdd p3)
{
	return p1.x*(p2.y-p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y) > 0;
}

void process()
{
	sort(a, a+n);
	pdd p1 = a[0], p2 = a[n-1];
	vector <pdd> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for(int i = 1; i < n; i++)
	{
		if (i == n - 1 || cw(p1, a[i], p2))
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
		}
	}
}

void input()
{
	cin >> n;
	f0(i, n)
	cin > a[i].x >> a[i].y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	while (cin >> n)
	{
		input();
		process();
	}
}