#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a ; i <= b; i++)

ll n, leng, db[30010], endof[30010];

ll bSearch(ll l, ll r, ll x)
{
	while (r - l > 1)
	{
		ll mid = (l + r) / 2;
		if (endof[mid] >= x) r = mid; else l = mid;
	}
	return r;
}

void process()
{
	endof[1] = db[1];
	leng++; //length
	For(i, 2, n)
	{
		if (db[i] > endof[leng]) endof[++leng] = db[i];
		else
		endof[bSearch(0, leng, db[i])] = db[i];
	}
	cout << leng << endl;
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