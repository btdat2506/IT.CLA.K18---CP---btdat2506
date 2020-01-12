#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, res;
bool Remove[200000];
string st;

void process()
{
	memset(Remove, 0, sizeof(Remove));
	res = 0;
	n = st.length();
	st = ' ' + st;
	For(i, 1, n-2)
	if (!Remove[i] && !Remove[i+1] && !Remove[i+2])
	{
		if (st.substr(i, 5) == "twone")
		Remove[i+2] = 1; else
		if (st.substr(i, 3) == "one" || st.substr(i, 3) == "two")
		Remove[i+1] = 1;
	}
	For(i, 1, n)
	if (Remove[i]) res++;
	cout << res << "\n";
	For(i, 1, n) if (Remove[i]) cout << i << " ";
	cout << "\n";
}	

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> st;
		process();
	}
}