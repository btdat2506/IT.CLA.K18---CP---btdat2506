#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << (abs(a - b) / 5) + (abs(a - b) % 5) / 2 + (abs(a - b) % 5) % 2 << '\n';
	}
}