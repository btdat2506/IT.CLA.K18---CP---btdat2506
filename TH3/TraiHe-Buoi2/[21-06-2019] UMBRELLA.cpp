#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, m, locate[5010], cost[100010], l[100010];

void process()
{
	sort(locate+1, locate+n+1);
	cost[m+1] = INT64_MAX;
	Fod(i, m, 1) cost[i] = min(cost[i], cost[i+1]);
	l[0] = 0;
	l[1] = cost[locate[1]];
	For(i, 2, m)
	For(j, 2, i)
	{
		l[i] = min(l[i], l[j-1] + cost[locate[i] - locate[j]+1]);
	}
	cout << l[m] << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, n)
	cin >> locate[i];
	For(i, 1, m)
	cin >> cost[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}