#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll idx = 0, x = 0, y = 0;
};

dt db[20000];
ll n, days, ans;

bool cmp(const dt &L, const dt &R)
{
	return (double) L.x / (double) L.y > (double) R.x / (double) R.y;
}
 
void process()
{
	sort(db+1, db+n+1, cmp);
	For(i, 1, n)
	{
		days += db[i].y;
		ans += days * db[i].x;
	}
	cout << ans << endl;
	For(i, 1, n) cout << db[i].idx << ' ';
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> db[i].x;
	For(i, 1, n) cin >> db[i].y;
	For(i, 1, n) db[i].idx = i;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}