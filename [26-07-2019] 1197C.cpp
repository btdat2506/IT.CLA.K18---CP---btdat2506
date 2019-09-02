#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, ans = 0, db[1000000], pros[1000000];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	For(i, 1, n) cin >> db[i];
	For(i, 1, n-1) pros[i] = db[i] - db[i+1];
	sort(pros+1, pros+n);
	ans = db[n] - db[1];
	For(i, 1, k-1) ans += pros[i];
	cout << ans << endl;
}