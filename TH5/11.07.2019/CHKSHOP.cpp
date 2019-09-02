#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, db[100010];
map <ll, bool> ck;

void process()
{
	bool ans = 1;
	For(i, 1, n)
	if (!ck[db[i]])
	{
		ans = 0;
		break;
	}
	cout << (ans ? "YES" : "NO") << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i];
	For(i, 1, n)
	{
		ll x;
		cin >> x;
		ck[x] = 1;
	}
}

int main()
{
	freopen("CHKSHOP.INP", "r", stdin);
	freopen("CHKSHOP.OUT", "w", stdout);
	input();
	process();
}