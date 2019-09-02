#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, stop;

ll lt(ll a, ll t)
{
	if (t == 1) return a;
	if (t % 2 == 0) 
	return ((lt(a, t/2) % 100) * (lt(a, t/2) % 100)) % 100;
	return ((lt(a, t/2) % 100) * (lt(a, t/2) % 100) * (a % 100)) % 100; 
}

void process()
{
	stop = lt(n, m);
	cout << stop << ' ';
	n = lt(stop, m);
	cout << n << ' ';
	for(;;)
	{
		n = lt(n, m);
		if (n != stop) 
			if (n / 10 == 0) cout << 0 << n << ' '; else
			cout << n << ' ';
		else break;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	process();
}