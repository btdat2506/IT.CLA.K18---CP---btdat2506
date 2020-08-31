#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("DELGCD.INP", "r", stdin);
    freopen("DELGCD.OUT", "w", stdout);

    int n, g = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x, g = __gcd(x, g);

    cout << ((g == 1) ? 0 : -1);
	return 0;
}
