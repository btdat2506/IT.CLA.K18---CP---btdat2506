#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll lca()
{

}

void process()
{

}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		ll cnt;
		For(j, 1, cnt)
		{
			ll x;
			cin >> x;
			db[i].push_back(x);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	For(i, 1, t)
	{
		cout << "Case " << i << ":" << endl;
		input();
		process();
	}
}