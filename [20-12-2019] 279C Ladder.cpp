#include <bits/stdc++.h>

using namespace std;
//start 5h37
typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int n, m;
ll arr1[1010], arr2[1010], lcs[1010][1010];
bool isPrime[(ll) (2e6 + 2e5)];

void sieve()
{
	For(i, 0, 1e6) isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	for(ll i = 2; i * i <= 2e6 + 2e5; i++)
	for(ll j = i * i; j <= 2e6 + 2e5; j += i)
	isPrime[j] = 0;
}

ll cube(ll num)
{
	return num*num*num;
}

ll sqr(ll num)
{
	return num*num;
}

bool isValid(ll i, ll j)
{
	ll val_sqrt = (ll) (sqrt(arr1[i]) + 0.5),
	   val_cbrt = (ll) (cbrt(arr1[i]) + 0.5);
	if (arr1[i] == arr2[j] &&
	   (sqr(val_sqrt) == arr1[i]|| 
	   (cube(val_cbrt) == arr1[i] && isPrime[val_cbrt])))
		return 1;
	else
		return 0;
}

void process()
{
	sieve();
	For(i, 1, n)
	For(j, 1, m)
	if (isValid(i, j))
		lcs[i][j] = lcs[i-1][j-1] + 1;
	else
		lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	cout << lcs[n][m] << "\n";
}

void input()
{
	string st;
	while (getline(cin, st))
	{
		stringstream ss;
		ss << st;
		if (!n)
		for(n = 1; ss >> arr1[n]; n++);
		else
		for(m = 1; ss >> arr2[m]; m++);
	}
	n--, m--;
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.ok", "w", stdout);
	input();
	process();
}