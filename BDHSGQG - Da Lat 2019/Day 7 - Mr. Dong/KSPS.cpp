#include <bits/stdc++.h>

using namespace std;

#define ll int32_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool kt = 0;
ll p, q, m, n;
string st, st1, st2;

string to_str(ll x)
{
	st2 = "";
	kt = 1;
	while (x != 0 || kt == 1)
	{
		st2 += (char) ((x % 10) + '0');
		x /= 10;
		if (x == 0) kt = 0;
	}
	reverse(st2.begin(), st2.end());
	return st2;
}

int main()
{
	freopen("KSPS.INP", "r", stdin);
	freopen("KSPS.OUT", "w", stdout);
	cin >> p >> q >> st1;
	st = to_str((ll) (p/q));
	p %= q;
	For(i, 1, 2*(1e6))
	{
		st += to_str((p * 10) / q);
		p = (p * 10) % q;
	}
	ll res = st.find(st1);
	if (res == -1) res = 0; else res++;
	cout << res << "\n";
}