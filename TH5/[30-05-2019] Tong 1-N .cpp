#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

ll Tong(ll n)
{
	if (n == 0) return 0;
	return Tong(n-1) + n;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n = 0;
	cin >> n;
	cout << Tong(n) << endl;
}