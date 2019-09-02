#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)
#define x first
#define y second

typedef pair<ll, ll> ii;

ii db[10010];
ll dem[10010], ans = 0, n;

bool cmp(const ii &L, const ii &R)
{
	return L.y < R.y;
}

void process()
{
	For(i, 2, n+1)
	For(j, 1, i)
	if (db[j].y <= db[i].x) dem[i] = max(dem[i], dem[j] + 1);
	For(i, 1, n+1) ans = max(ans, dem[i]);
	cout << ans << endl; 
}

void input()
{
	cin >> n;
	For(i, 1, n+1)
	cin >> db[i].x >> db[i].y;
	sort(db+1, db+n+1, cmp);
	For(i, 1, n+1) dem[i] = 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}