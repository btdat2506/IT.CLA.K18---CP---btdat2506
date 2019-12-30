#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

ll n, k, m, a[260], b[260];

void process()
{
	{
		short int ans[n], mark[n+22];
		ll res = 0;
		iota(ans, ans+n, 1);
		do
		{
			bool ok = 1;
			For(i, 1, m)
			if (ans[a[i]-1] > ans[b[i]-1]) ok = 0;
			if (ok)
			{
				res++;
				if (res == k)
				{
					f0(i, n)
					cout << ans[i] << ' ';
					return;
				}
			}
		}
		while (next_permutation(ans, ans+n));
		cout << "poor professor" << "\n";
	}
}

void input()
{
	cin >> n >> k >> m;
	For(i, 1, m)
	cin >> a[i] >> b[i];
}

int main()
{
	freopen("CHOCOLATE.INP", "r", stdin);
	freopen("CHOCOLATE.OUT", "w", stdout);
	input();
	process();
}