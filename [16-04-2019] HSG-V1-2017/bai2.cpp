#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

priority_queue <ii, vector<ii>> pq[300];

ll m, n;
char db[300][300];

void process()
{
	queue <ii> q;
	For(i, 1, m)
	For(j, 1, n)
	if (hangt[i] && cott[j] && db[i][j] == '+') pq.push(ii(i, j));
}

void input()
{
	For(i, 0, 210)
	For(j, 0, 210)
	db[i][j] = '.';
	For(i, 0, 210) hangt[i] = 1;
	For(j, 0, 210) cott[j] = 1;

	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	{
		cin >> db[i][j];
		if (db[i][j] == '*') hangt[i] = cott[j] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}