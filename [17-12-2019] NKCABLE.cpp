#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, f[25010], a[25010];

void process()
{
	f[1] = 1e9;
	For(i, 2, n)
	f[i] = min(f[i-2] + a[i], f[i-1] + a[i]);
	cout << ((n == 1) ? a[1] : f[n]) << "\n";
}

void input()
{
	cin >> n;
	For(i, 2, n)
	cin >> a[i];
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}