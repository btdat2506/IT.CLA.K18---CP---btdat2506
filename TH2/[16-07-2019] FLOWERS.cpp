#include <bits/stdc++.h>

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

using namespace std;

ll n, l, r, db[200010], temp[200010], cnt[200010];

void process()
{
	l = r = 1;
	while (l <= n && r <= n)
	{
		while (db[l] != db[l+1] && l + 1 <= n) l++;
		r = l+1;
		while (db[l] == db[r] && r + 1 <= n) r++;
		r = max(l, r-1);
		For(i, l, r)
		cnt[i] = r - l + 1;
		l = r = r + 1;
	}
	For(i, 1, n) cout << cnt[i] << ' ';
	l = r = 1;
	/*while (l <= n && r <= n)
	{
		while (cnt[r] < 3) r++;
		r += 2;

		while (cnt[r] >= 3) r++;
		l = r-2;
	}*/
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}