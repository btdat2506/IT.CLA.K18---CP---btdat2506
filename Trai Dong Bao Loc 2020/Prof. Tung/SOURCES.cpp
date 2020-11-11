#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll a, b, t, pos = 0;
	cin >> a >> b;
	t = (b-a+1)*a+((b-a)*(b-a+1))/2;
	string st = to_string(t);
	sort(st.begin(), st.end());
	while (st[pos] == '0') pos++;
	for(; pos < st.length(); pos++)
	cout << st[pos];
}