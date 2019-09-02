#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll mul11[1000], mul10[1000];

void process(ll x)
{
	memset(mul11, 0, sizeof(mul11));
	memset(mul10, 0, sizeof(mul10));
	mul10[0] = 1,
	mul11[0] = 0;
	For(i, 1, 300)
		mul10[i] = (mul10[i-1] * 10) % x,
		mul11[i] = (mul11[i-1] * 10 + 1) % x;
	ll ans_i = 300,
	   ans_j = 300;
	For(i, 0, 210)
	For(j, 0, 210)
	if (i + j <= 200 && i + j > 0)
	{
		if (((8 * mul11[i] * mul10[j]) + (6 * mul11[j])) % x != 0) continue;
		if (i + j > ans_i + ans_j) continue;
		if ((i + j == ans_i + ans_j && i < ans_i) || (i + j < ans_i + ans_j))
		{
			ans_i = i,
			ans_j = j;
			continue;
		}
	}
	if (ans_i + ans_j <= 200)
	{
		For(i, 1, ans_i) cout << '8';
		For(j, 1, ans_j) cout << '6';
		cout << endl;
		return;
	}
	cout << -1 << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	For(i, 1, n)
	{
		ll x;
		cin >> x;
		process(x);
	}
	return 0;
}