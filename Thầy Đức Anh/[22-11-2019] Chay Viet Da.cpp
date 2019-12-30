#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll idx = 0, val = 0;
	bool operator < (const Data &T)
	{
		return idx < T.idx;
	}
};

ll n, k, res[30];
Data enemy[30], team[30];

void process()
{
	sort(team+1, team+1+k);
	For(i, 1, k)
	For(j, 1, k)
	if (team[j] <= enemy[i])
		res[j] = max(res[j], res[i] + 1);
}

void input()
{
	For(i, 0, 25)
	team[i].idx = enemy[i].idx = i,
	enemy[i].val = INT64_MAX;
	cin >> n >> k;
	For(i, 1, n-1)
	For(j, 1, k)
	{
		ll x;
		cin >> x;
		enemy[j].val = min(enemy[j].val, x);
	}
	For(i, 1, k)
	cin >> team[i].val;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}