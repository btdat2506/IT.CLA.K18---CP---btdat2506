#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, t[600010], r[600010];

void process()
{

}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> t[i];
	For(i, 1, n) cin >> r[i];
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}