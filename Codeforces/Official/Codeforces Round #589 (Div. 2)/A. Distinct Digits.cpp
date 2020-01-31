#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	bool ck1 = 0;
	ll l, r;
	cin >> l >> r;
	while (l <= r)
	{
		bool ck = 1;
		ll tmp = l, cnt[11];
		memset(cnt, 0, sizeof(cnt));
		while (tmp != 0)
		{
			cnt[tmp % 10]++;
			if (cnt[tmp % 10] > 1)
			{
				ck = 0;
				break;
			}
			tmp /= 10;
		}
		if (ck)
		{
			cout << l << "\n";
			return 0;
		}
		l++;
	}
	cout << -1 << "\n";
}