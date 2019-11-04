#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, res, a[200010], maxx[200010], minn[200010];

void process()
{
	maxx[0] = INT64_MIN;
	minn[n+1] = INT64_MAX;
	For(i, 1, n)
	maxx[i] = max(a[i], maxx[i-1]);
	Fod(i, n, 1)
	minn[i] = min(a[i], minn[i+1]);
	For(i, 1, n)
	if (maxx[i] <= minn[i+1]) res++;
	cout << res;
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> a[i];
}

int main()
{
	freopen("SORT.INP", "r", stdin);
	freopen("SORT.OUT", "w", stdout);
	input();
	process();
}