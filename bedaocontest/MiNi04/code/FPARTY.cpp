#include <bits/stdc++.h>

using namespace std;
const string filename = "FPARTY";

const int mod = 1e9 + 7;

int n, k;
int a[100001];
int fact[100001], re_fact[100001];

int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b/2);
	if (b % 2 == 0) return (1LL * tmp * tmp)%mod;
	return ((1LL * tmp * tmp)%mod * a)%mod;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	fact[0] = 1;
	for (int i = 1; i <= 100000;i++)
		fact[i] = (1LL * fact[i - 1] * i)%mod;
	re_fact[100000] = p(fact[100000], mod - 2);
	for (int i = 100000; i >= 1; i--)
		re_fact[i - 1] = (1LL * re_fact[i] * i)%mod;

	cin >> n >> k;
	int ans = fact[n];
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
		ans = (1LL * ans * re_fact[a[i]])%mod;
	}
	cout << ans;
}