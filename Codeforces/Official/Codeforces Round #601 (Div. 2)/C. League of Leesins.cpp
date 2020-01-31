#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, st = 1e9, ed = -1e9, cnt[100010], db[100010][5], res[100010];

void process()
{
	For(i, 1, n)
	if (cnt[i] == 1) 
	res[1] = min(st, i), res[n] = max(ed, i);
	
}

void input()
{
	cin >> n;
	For(i, 1, n-2)
	{
		cin >> db[i][1] >> db[i][2] >> db[i][3];
		cnt[db[i][1]]++,
		cnt[db[i][2]]++,
		cnt[db[i][3]]++;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}