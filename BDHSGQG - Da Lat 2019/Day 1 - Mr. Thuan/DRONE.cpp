#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Data
{
	ll val = 0, cnt = 0;
};

ll n, k, a[3010], c[3010];
Data f[3010];

void process()
{
	f[1].val = c[1];
	f[1].cnt = 1;
	For(i, 1, n)
	For(j, i+1, min(i+a[i], n))
	{
		 
	}
}

void input()
{
	cin >> n >> k;
	For(i, 1, n) cin >> c[i];
	For(i, 1, n) cin >> a[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}