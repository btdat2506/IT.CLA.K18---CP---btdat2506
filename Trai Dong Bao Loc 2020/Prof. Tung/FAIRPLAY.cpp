#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll k, n;
	cin >> k;
	n = k;
	if (k == 1)
	{
		cout << "1\n0";
		return 0;
	}
	ll a = 2;
	while (a*a <= k)
	if (k % a == 0)
		{
			k /= a;
			break;
		}
	else
		a++;
	if (a == k)
	{
		cout << "1\n0";
		return 0;
	}
	ll b = 2;
	while (b*b <= k)
	if (k % b == 0)
		break;
	if (a*b == n)
	{
		cout << 2;
		return 0;
	}
	else
	{
		cout << "1\n" << a*b;
		return 0;
	}
}