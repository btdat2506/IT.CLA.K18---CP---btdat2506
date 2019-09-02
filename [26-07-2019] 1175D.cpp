#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, k, ans = 0, db[1000000], pros[1000000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> k;
	For(i, 1, n) cin >> db[i];
	Fod(i, n, 1) pros[i] = pros[i+1] + db[i];
	ans = pros[1];
	pros[1] = INT64_MIN;
	sort(pros+2, pros+n+1);
	Fod(i, n, n-k+2) ans += pros[i];
	cout << ans << endl;
}