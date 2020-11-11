#include <bits/stdc++.h>
using namespace std;
int64_t a, b;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("GEARS.INP", "r", stdin);
	freopen("GEARS.OUT", "w", stdout);
	cin >> a >> b;
	cout << ((a*b/__gcd(a, b) - a - b < 0) ? 2*(a*b/__gcd(a, b)) - a - b : a*b/__gcd(a, b) - a - b) << "\n";
}