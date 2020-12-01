#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, res, a[10010], f[10010];

bool isValid(ll u)
{
	ll k = sqrt(u);
	if (k*(k+1) == u) return 1;
	return 0;
}

void process()
{
	For(i, 1, n) f[i] = 1;
	For(i, 2, n)
	For(j, 1, i-1)
	if (isValid(a[i]) && isValid(a[j]) && a[i] >= a[j])
	{
		f[i] = max(f[i], f[j] + 1);
	}
	For(i, 1, n)
	res = max(res, f[i]);
	cout << res << '\n';
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> a[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}