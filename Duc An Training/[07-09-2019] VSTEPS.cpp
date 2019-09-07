#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define MOD 14062008
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, db[100010];

void process()
{
	if (db[1] != -1) db[1] = 1;
	For(i, 2, n)
	if (db[i] != -1)
	{
		if (db[i-1] != -1) db[i] = db[i-1] % MOD;
		if (db[i-2] != -1) (db[i] += db[i-2] % MOD) %= MOD;
	}
	cout << db[n] << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> k;
	For(i, 1, k)
	{
		ll x;
		cin >> x;
		db[x] = -1;
	}
	process();
}