#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, a, b, c;

ll cb(ll t)
{
	return t*t*t;
}

ll f1(ll &k)
{
	ll t = 3;
	while (k >= cb(t)) k -= cb(t++);
	return t;
}

ll f2(ll &k)
{
	
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> l >> r;
	l--, r--;
	ll tmp = l;
	n = f1(tmp);
	a = f2(tmp);
	b = f3(tmp);
	c = f4(tmp);

}