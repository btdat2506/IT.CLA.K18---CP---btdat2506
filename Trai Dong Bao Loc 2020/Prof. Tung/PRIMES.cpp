#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll a, b;
map <ll, bool> visited;
vector <ll> res, tmp, v;

bool Prime(ll n)
{
    if (n < 2) return 0;
    For(i, 2, sqrt(n))
    if (n % i == 0) return 0;
    return 1;
}

void dfs(ll u)
{
	visited[u] = 1;
	tmp.push_back(v[u]);
	if (v[u] == b)
	{
		if (res.empty() || res.size() > tmp.size()) res = tmp;
		tmp.pop_back();
		return;
	}
	f0(i, v.size())
	if (!visited[i] && Prime(max(v[i] - v[u], v[u] - v[i])))
	{
		dfs(i);
		visited[i] = 0;
	}
	tmp.pop_back();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("PRIMES.INP", "r", stdin);
	freopen("PRIMES.OUT", "w", stdout);
	cin >> a >> b;
	set <ll> got;
	got.insert(2);
	For(i, -2, 2)
	{
		if (Prime(a + i)) got.insert(a + i);
		if (Prime(b + i)) got.insert(b + i);
	}
	for(ll t: got) v.push_back(t);
	f0(i, v.size()) 
	if (v[i] == a) dfs(i);
	if (res.empty())
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << res.size() << "\n";
	for(ll t: res)
	cout << t << " ";
}