#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

ll last_non_zero_digit(ll n)
{
	if (n < 10) return dig[n];
	if (((n / 10) % 10) % 2 == 0)
		return (6*last_non_zero_digit(n/5)*dig[n%10]) % 10;
	else
		return (4*last_non_zero_digit(n/5)*dig[n%10]) % 10;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	cout << last_non_zero_digit(n);
}