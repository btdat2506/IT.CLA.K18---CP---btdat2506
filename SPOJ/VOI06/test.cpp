#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)

bool getBit(ll k, ll pos)
{
	return (k >> pos) & 1;
}

bool isValid(ll j, ll k)
{
	//Kiểm tra nếu có 2 bit liền kề
	ll tmp = j << 1;
	while (tmp >>= 1)
	{
		if (getBit(tmp, 0) && getBit(tmp, 1))
		return false;
	}
	/* tmp = k << 1;
	while (tmp >> 1)
	{
		if (getBit(tmp, 0) && getBit(tmp, 1))
		return false;
	} */
	return true;
}

int main()
{
	cout << isValid(10, 8) << isValid(14, 9) << "\n";
}