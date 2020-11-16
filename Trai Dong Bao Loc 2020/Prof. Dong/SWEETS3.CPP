#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n[33], a[33], b[33], c[33], f[32][92]; //f[i][nho]: at position i, how many numbers are left to remember

ll get_res(ll i, ll carry)
{
	if (f[i][carry]) > -1) return f[i][carry];
	if (i == 0) return (carry == 0);
	ll cnt = 0;
	f0(i, 1)
	f0(j, 1)
	f0(k, 1)
	if ((i*a[i] + j*b[i] + k*c[i] + carry) % 2 == n[i])
		cnt += get_res(i-1, )
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n >> a >> b >> c;
		memset(f, -1, sizeof(f));
		cout << res(0, 0) << "\n";
	}
}