#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("STOPWATCH.INP", "r", stdin);
	freopen("STOPWATCH.OUT", "w", stdout);
	int m, a, b;
	cin >> m >> a >> b;
	cout << ((a < b) ? b - a : m - a + b) << "\n";
}