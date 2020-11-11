#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
//ifstream (NAME);
//ofstream (NAME);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("TOPIC.INP", "r", stdin);
	freopen("TOPIC.OUT", "w", stdout);
	ll n, t, cnt = 0;
	string st = "";
	cin >> n;
	f0(i, n)
	{
		cin >> t;
		if (!t && !cnt)
		st[i] = '-'; else
		{
			cnt += t - 1;
			st[i] = '*';
		}
	}
	cout << st << "\n";
}