#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll get_res(ll t)
{
	return t - t/2;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if (b < c) 
	{
		cout << get_res(b - a) << "\n";
		return 0;
	}
	ll l = a / c, r = b / c;
	if (l * c <= a) l++;
	cout << get_res(l*c-1 - a) + (r-l)*get_res(c) + get_res(b - (r*c - 1)) << '\n';
}