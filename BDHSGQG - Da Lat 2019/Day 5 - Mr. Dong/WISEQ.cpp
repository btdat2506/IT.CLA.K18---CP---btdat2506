#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, w, res, a[50010], endof[50010];
ll f[1001][1001];

void process_equals()
{
	For(i, 0, n+5) endof[i] = INT64_MAX;
	endof[0] = INT64_MIN;
	For(i, 2, n)
	{
		ll pos = lower_bound(endof, endof+n, a[i]) - endof;
		endof[pos] = a[i];
		res = max(res, pos);
	}
	cout << res;
}

void process_sub4() //n <= 500
{
	For(i, 0, 1000)
	For(j, 0, 1000)
	f[i][j] = 1e9;
	f[0][0] = 0;
	For(i, 1, n)
	For(l, 1, n)
	For(j, 0, i-1)
	if (a[j] < a[i])
		f[i][l] = min(f[i][l], f[j][l-1] + a[i]);
	For(i, 1, n)
	For(l, 1, n)
	if (f[i][l] <= w)
		res = max(res, l);
	cout << res;
}

void input()
{
	cin >> n >> w;
	For(i, 1, n)
	cin >> a[i];
}

int main()
{
	freopen("WISEQ.INP", "r", stdin);
	freopen("WISEQ.OUT", "w", stdout);
	input();
	if (n <= 500) 
		process_sub4();
	else
		process_equals();
	return 0;
}