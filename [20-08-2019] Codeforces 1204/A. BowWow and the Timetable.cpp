#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
ll n = 0, ans = 0;
string st;
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> st;
	n = st.length();
	reverse(st.begin(), st.end());
	For(i, 0, n)
	if (st[i] == '1') ans += i;
	if (ans % 2 == 1) ans /= 2;
	else ans /= 2;
	cout << ans << endl;
}