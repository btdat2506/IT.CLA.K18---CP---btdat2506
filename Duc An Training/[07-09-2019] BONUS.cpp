#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, ans, db[1010][1010], pros[1010][1010];

void process()
{
	For(i, 1, n)
	For(j, 1, n)
	db[i][j] += (db[i-1][j] + db[i][j-1]) - db[i-1][j-1];
	For(i, k, n)
	For(j, k, n)
	ans = max(ans, db[i][j] - (db[i][j-k] + db[i-k][j]) + db[i-k][j-k]);
	cout << ans << endl;
}

void input()
{
	cin >> n >> k;
	For(i, 1, n)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}