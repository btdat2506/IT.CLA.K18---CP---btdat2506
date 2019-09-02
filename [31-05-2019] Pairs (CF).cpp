#include <bits/stdc++.h>

using namespace std;

//https://codeforces.com/contest/1169/problem/B

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair <ll, ll> ii;

ll n, m;
ii db[300010];

bool process(ll z)
{
	ll cnt[300010];
	For(i, 1, 300010) cnt[i] = 0;
	ll cntx = 0;
	For(i, 1, m)
	if (z == db[i].x || z == db[i].y)
		cntx++;
	else
		cnt[db[i].x]++,
		cnt[db[i].y]++;
	For(i, 1, n)
		if (cntx + cnt[i] == m)
	return 1;
	return 0;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	cin >> db[i].x >> db[i].y;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	if (process(db[1].x) or process(db[1].y)) 
		cout << "YES"; else cout << "NO";
	return 0;
}