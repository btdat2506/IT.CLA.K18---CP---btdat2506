#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, db[1000000];

void process()
{
	unordered_map <ll, ll> freq;
	ll cnt = 0, l = 1, left = 1, right = 1;
	For(i, 1, n)
	{
		freq[db[i]]++;
		if (freq[db[i]] == 1) cnt++;
		if (cnt > k)
		{
			freq[db[l]]--;
			if (freq[db[l]] == 0) cnt--;
			l++;
		}
		if (i - l + 1 > right - left + 1)
			right = i,
			left = l;
	}
	cout << left << ' ' << right << "\n";
}

void input()
{
	cin >> n >> k;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("KGOOD.INP", "r", stdin);
	freopen("KGOOD.OUT", "w", stdout);
	input();
	process();
}