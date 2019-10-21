#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)
 
vector <int32_t> prime;
ll x, y;
 
void sieve()
{
	ll N = 50000000;
	vector <bool> notPrime (N + 2);
	notPrime[0] = notPrime[1] = 1;
	For(i, 2, N)
	for(ll j = i*i; j <= N; j += i)
	notPrime[j] = 1;
	For(i, 2, N)
	if (!notPrime[i]) prime.push_back(i);
}

bool isPrime(ll k)
{
	For(i, 2, sqrt(k))
	if (k % i == 0) return 0;
	return 1;
}
 
void process()
{
	if (x - y < 2)
	{
		cout << "NO" << "\n";
		return;
	}
	else
	{
		for(ll k: prime)
		if ((x-y) % k == 0)
		{
			cout << "YES" << "\n";
			return;
		}
		For(k, prime[prime.size()-1], x-y)
		if (isPrime(k) && (x-y) % k == 0)
		{
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	sieve();
	while (t--)
	{
		cin >> x >> y;
		process();
	}
}