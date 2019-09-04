#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool notPrime[2000000];
ll n, ans;

void sieve()
{
	notPrime[0] = notPrime[1] = 1;
	For(i, 2, sqrt(2000000) + 1)
	for(ll j = i * i; j <= 2000000; j += i)
	notPrime[j] = 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	sieve();
	For(i, 0, 2000000)
	if (!notPrime[i]) ans++;
	cout << ans << endl;
}