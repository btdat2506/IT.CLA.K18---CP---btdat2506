#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

string st;

void process()
{
	ll n = st.length();
	st = ' ' + st;
	map <char, ll> cnt;
	For(i, 1, n)
	cnt[st[i]]++;
	ll u = cnt['U'], d = cnt['D'], l = cnt['L'], r = cnt['R'];
	ll h = min(u, d), v = min(l, r);
	if (min(h, v) == 0)
	{
		if (h) cout << "2 \nUD"; else
		if (v) cout << "2 \nLR"; else
		cout << 0;
	}
	else
	{
		cout << (v + h) * 2 << "\n";
		cout << string(v, 'L');
		cout << string(h, 'U');
		cout << string(v, 'R');
		cout << string(h, 'D');
	}
	cout << "\n";

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> st;
		process();
	}
}