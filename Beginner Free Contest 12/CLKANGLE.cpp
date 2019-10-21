#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

double dg_m, dg_h, ans, h, m;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> h >> m;
	cout << fixed << setprecision(1);
	ans = abs(6*m - 0.5 * (h * 60 + m));
	cout << min(360-ans, ans) << "\n";
	return 0;
}