#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

string st = "";

ll leng(ll n)
{
	if (n < 10) return n;
	ll d = 10, m = 0, i = 1;
	do
		m += (d - d / 10) * i,
		d *= 10,
		i++;
	while (d <= n);
	d /= 10;
	m += (n - d + 1) * i;
	return m;
}

ll cnt(ll m)
{
	ll u = m, d = 0;
	for(d = 1; u > 1; d++)
	{
		if (d % 2 == 0) 
			u = u/2 + u%2;
		else
			u /= 2;
	}
	return d;
}

ll idx(ll d)
{
	ll k = 1;
	Fod(i, d, 1)
	if (i % 2 == 0)
		(k *= 2) -= 1;
	else
		k *= 2;
	return k;
}

ll digit(ll nx, ll d)
{
	ll tmp = nx;
	For(i, 1, d)
	tmp /= 10;
	return tmp % 10;
}

ll num(ll k)
{
	ll d = 1, m = 0, i = 0, nx = 0, j = 0;
	do
	{
		d *= 10,
		++i,
		m += (d - d/10) * i;
	}
	while (m <= k);
	m -= (d - d/10) * i;
	d /= 10;
	nx = d + (k - m - 1) / i;
	j = (k - m - 1) % i + 1;
	return digit(nx, i-j);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k;
	cin >> k;
	For(j, 1, k)
	{
		ll n, m, d, k, x;
		cin >> n;
		m = leng(n);
		d = cnt(m);
		k = idx(d),
		x = num(k);
		cout << x;
	}
}