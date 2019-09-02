#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

const ll base = 28,
		 siz = 1000010;
string st;
ll n, ans = 0, hashT[siz], power[siz];

ll gethash(ll i, ll j)
{
	return hashT[j] - hashT[i-1] * power[j - i + 1];
}

void precalc()
{
	memset(power, 0, sizeof(power));
	memset(hashT, 0, sizeof(hashT));
	n = st.length();
	st = ' ' + st;
	power[0] = 1;
	For(i, 1, n)
	power[i] = power[i-1] * base,
	hashT[i] = hashT[i-1] * base + (st[i] - 'a' + 1);
}

void process(ll idx)
{
	ans = 0;
	precalc();
	For(i, 1, max(n-1, (ll) 0))
	if (gethash(1, i) == gethash(n - i + 1, n)) ans++;
	cout << "Case " << idx << ": " << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	For(i, 1, t)
	{
		cin >> st;
		process(i);
	}
}