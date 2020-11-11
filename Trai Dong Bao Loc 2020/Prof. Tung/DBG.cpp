#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

ll n;

void process()
{
	ll cnt = log2(n);
	vector <ll> res[65];
	For(i, 0, n-1)
	For(j, 0, cnt-1)
	if (1 & (j >> i))
	res[j].push_back(i);
	cout << cnt << "\n";
	f0(i, cnt)
	{
		cout << res[i].size() << "\n";
		for(ll t: res[i])
		cout << t+1 << ' ';
		cout << '\n';
	}
}

void input()
{
	cin >> n;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("DBG.INP", "r", stdin);
	freopen("DBG.OUT", "w", stdout);
	input();
	process();
}