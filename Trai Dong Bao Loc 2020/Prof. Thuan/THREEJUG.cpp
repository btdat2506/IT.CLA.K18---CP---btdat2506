#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define INF 1e12
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll d, T;

ll valid(ll A, ll B, ll C, ll a, ll b, ll c)
{
	ll cnt = (ll) (b/d) + (ll) (c/d);
	if ((T - a) <= cnt*d && (T - a) % d == 0 && T - a >= 0 && T <= A && T > a)
	return (T - a)/d;
	return INF;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll A, B, C, a, b, c, res;
	cin >> A >> B >> C >> a >> b >> c >> d >> T;
	if (a == T || b == T || c == T)
	{
		cout << 0 << "\n";
		return 0;
	}
	if (!d)
	{
		cout << -1 << "\n";
		return 0;
	}
	res = valid(A, B, C, a, b, c);
	res = min(res, valid(B, A, C, b, a, c));
	res = min(res, valid(C, A, B, c, a, b));
	if (res == INF)
		cout << -1 << '\n';
	else
		cout << res << "\n";
}