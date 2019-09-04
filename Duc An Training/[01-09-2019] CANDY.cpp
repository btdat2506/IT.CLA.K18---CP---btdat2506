#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, db[10010];

void process()
{
	ll sum = 0;
	For(i, 1, n)
	sum += db[i];
	if (sum % n == 0)
	{
		ll avg = sum / n, inn = 0;
		For(i, 1, n)
		if (avg > db[i]) inn += (avg - db[i]);
		cout << inn << endl;
	}
	else
		cout << -1 << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (cin >> n, n != -1)
	{
		memset(db, 0, sizeof(db));
		For(i, 1, n)
		cin >> db[i];
		process();
	}
}