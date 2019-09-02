#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll c, n, ans = 0, db[100];

bool getbit(ll x, ll y)
{
	return (x >> y) & 1;
}

void process()
{
	For(state, 0, (1 << n))
	{
		ll sum = 0;
		For(i, 0, n)
		if (getbit(state, i)) sum += db[i];
		if (sum <= c)
			ans = max(ans, sum);
	}
	cout << ans;
}

void input()
{
	cin >> c >> n;
	For(i, 0, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}