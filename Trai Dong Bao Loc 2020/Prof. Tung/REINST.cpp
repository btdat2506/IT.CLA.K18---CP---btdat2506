#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll a, b, res;
string st;

void process()
{
	if (count(st.begin(), st.end(), '(') != count(st.begin(), st.end(), ')'))
	{
		cout << -1 << "\n";
		return;
	}
	for(auto ch: st)
	{
		a = b;
		b += (ch == '(') ? 1 : -1;
		res += (a <= 0) && (b <= 0);
	}
	cout << res << "\n";
}

void input()
{
	ll n; cin >> n;
	cin >> st;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("REINST.INP", "r", stdin);
	freopen("REINST.OUT", "w", stdout);
	input();
	process();
}