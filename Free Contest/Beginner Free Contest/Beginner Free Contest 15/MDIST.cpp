#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x[200], y[200], res;

void process()
{
	For(i, 1, n-1)
	For(j, i+1, n)
	res = max(res, abs(x[i] - x[j]) + abs(y[i] - y[j]));
	cout << res << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> x[i] >> y[i];
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.ok", "w", stdout);
	input();
	process();
}