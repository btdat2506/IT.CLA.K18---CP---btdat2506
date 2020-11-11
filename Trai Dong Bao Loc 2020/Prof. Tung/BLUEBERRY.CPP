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
	freopen("BLUEBERRY.INP", "r", stdin);
	freopen("BLUEBERRY.OUT", "w", stdout);
	ll ans, n, k;
	cin >> n >> k;
	ans = (n + k - 1) / k;
	if (n != k && n > 2*k) ans++;
	cout << ans << "\n";
}