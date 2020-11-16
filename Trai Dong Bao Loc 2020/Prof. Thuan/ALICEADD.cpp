#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

string plus_bignum(ll a, ll b)
{
	string t1 = to_string(a),
		   t2 = to_string(b),
		   t3 = "";
	if (t1.size() > t2.size()) swap(t1, t2);
	while (t1.size() < t2.size())
	t1 = '0' + t1;
	ll n = t1.size(), num = 0, borrow = 0;
	while (n > 0)
	{
		n--;
		num = t1[n] - '0' + t2[n] - '0' + borrow;
		if (num >= 10)
		{
			num %= 10;
			borrow = 1;
		}
		else
			borrow = 0;
		t3 = to_string(num) + t3;
	}
	if (borrow > 0)
	t3 = to_string(borrow) + t3;
	return t3;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	ll a, b;
	while (t--)
	{
		cin >> a >> b;
		cout << plus_bignum(a, b)  << "\n";
	}
}