#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
typedef pair<ll, ll> ii;
 
clock_t start = clock();
 
ll n, m, favour[15000], C[200][200];
 
void floyd()
{
	For(k, 1, n)
	For(i, 1, n)
	For(j, 1, n)
	if (C[i][j] > C[i][k] + C[k][j])
	C[i][j] = C[i][k] + C[k][j];
}
 
void process()
{
	floyd();
	ll ans = 0;
	for(ll i = 1; i < m; i++)
		ans += C[favour[i]][favour[i+1]];
	cout << ans << endl;
}
 
void input()
{
	memset(favour, 0, sizeof(favour));
	For(i, 0, 150)
	For(j, 0, 150) C[i][j] = INT64_MAX;
	cin >> n >> m;
	For(i, 1, m) cin >> favour[i];
	For(i, 1, n)
	For(j, 1, n)
	{
		ll cost; cin >> cost;
		C[i][j] = cost;
	}
}
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	input();
	process();
	//cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
} 