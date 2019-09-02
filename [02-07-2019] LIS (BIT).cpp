#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, db[30010];

ll getleng(ll idx)
{
	ll res = 0;
	while (idx > 0)
	{
		res = max(res, bit[idx]);
		idx -= idx & (-idx);
	}
	return res;
}

void update()
{
	
}

void compress()
{
	ll temp[30010];
	For(i, 1, n) temp[i] = db[i];
	sort(temp+1, temp+1+n);
	For(i, 1, n)
	db[i] = lower_bound(temp+1, temp+1+n, db[i]) - (temp+1) + 1;
	For(i, 1, n) cout << db[i] << endl;
}

void process()
{
	compress();
	For(i, 1, n)
	{
		ans += getsum(db[i]);
		update(db[i]);
	}
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}