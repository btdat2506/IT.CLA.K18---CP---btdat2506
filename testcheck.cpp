#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long a, b, c, minn = INT64_MAX, maxx = INT64_MIN;
	while (cin >> a >> b >> c)
	{
		minn = min(minn, min(a, b));
		maxx = max(maxx, max(a, b));
	}
	cout << minn << ' ' << maxx << endl;
}