#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans = 0, db[100010];
bool suff[100010], pre[100010];

void process()
{
	ll mink = db[n];
	Fod(i, n, 1) //db[k] > db[i-1]
	{
		if (mink > db[i-1]) pre[i] = 1;
		mink = min(mink, db[i-1]);
	}
	mink = db[n] + db[0];
	For(i, 1, n) //db[k] + db[n] > db[i-1]
	{
		if (mink > db[i-1]) suff[i] = 1;
		mink = min(mink, db[n] + db[i]);
	}
	For(i, 1, n)
	if (pre[i] && suff[i]) ans++;
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		cin >> db[i];
		db[i] += db[i-1];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}