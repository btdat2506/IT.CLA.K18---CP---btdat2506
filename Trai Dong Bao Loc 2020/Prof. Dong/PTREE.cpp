//f[i]: số lượng nút lớn nhất bị mất đi + 1 (rank)
#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

const ll N = 1e6+5;
ll n, P[N], f[N];
vector <ll> child[N];
ll spec[N]; //specification of node (max or min)

ll sum(ll i)
{
	if (f[i] > -1) return f[i];
	if (child[i].size() == 0)
	return 1;
	ll m = n + 1, sum = 0;
	for(ll j = 0; j < child[i].size(); j++)
	{
		if (m > f[j]) m = f[j];
		sum += f[j];
	}
	if (spec[i] == 1) 
		return m;
	else
		return sum;
}

void process()
{
	memset(f, -1, sizeof(f));
	ll ans = 0;
	For(i, 2, n)
	ans = max(ans, sum(P[i]));
	cout << ans << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		cin >> spec[i];
	}
	For(i, 2, n)
	{
		cin >> P[i];
		child[P[i]].push_back(i);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}