#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll bSearch(ll s1, ll l, ll r)
{
	ll ans = -1;
	while (l >= r)
	{
		ll mid = (l + r) / 2;
		if (subarr[mid] - s1 >= 0)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		l = mid + 1;
	}
}

void process()
{
	
}

void input()
{
	
}

int main()
{
	input();
	process();
}