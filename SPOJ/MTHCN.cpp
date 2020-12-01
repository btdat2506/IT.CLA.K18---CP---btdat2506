#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans, calc[2010], l[2010], r[2010];
bool isPrime[2010], db[2010][2010];
vector <vector <ll>> t;

void Sieve()
{
	For(i, 0, 2000) isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	For(i, 2, 2000)
	for(ll j = i*i; j <= 2000; j += i)
	isPrime[j] = 0;
}

bool check(ll val)
{
	ll tmp2 = sqrt(val), tmp3 = cbrt(val);
	if (tmp2 * tmp2 == val)
		return true;
	if (tmp3 * tmp3 * tmp3 == val && isPrime[tmp3])
		return true;
	return false;
}

void reformat_data()
{
	For(i, 1, n)
	For(j, 1, n)
	t[i][j] = t[i][j-1] + t[i][j],
	db[i][j] = check(t[i][j]);
}

void get_res()
{
	stack <ll> st;
	calc[0] = calc[n + 1] = INT64_MIN;
	st.push(0);
	For(i, 1, n)
	{
		while (!st.empty() && calc[i] <= calc[st.top()]) st.pop();
		l[i] = st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n + 1);
	Fod(i, n, 1)
	{
		while (!st.empty() && calc[i] <= calc[st.top()]) st.pop();
		r[i] = st.top() - 1;
		st.push(i);
	}
	For(i, 1, n)
	ans = max(ans, calc[i] * (r[i] - l[i] + 1));
}

void process()
{
	Sieve();
	reformat_data();
	For(i, 1, n)
	{
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		For(j, 1, n)
		if (db[i][j]) calc[j]++; else calc[j] = 0;
		get_res();
	}
	cout << ans << "\n";
}

void input()
{
	ll m, x, u, v, k;
	cin >> n >> m;
	t.resize(n+2);
	For(i, 1, n) t[i] = vector <ll> (n+2, 0);
	For(i, 1, m)
	{
		cin >> x >> u >> v >> k;
		t[x][u] += k;
		t[x][v + 1] -= k;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}