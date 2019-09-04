#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans, db[100010];

void process()
{
	sort(db+1, db+1+n);
	ll i = 1, j = n;
	while (i < j)
		ans += db[i] + db[j] + (db[j] - db[i]),
		i++,
		j--;
	if (n % 2 != 0) ans += db[n/2 + 1];
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}