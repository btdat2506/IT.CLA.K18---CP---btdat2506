#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

vector <ll> fi;

ll Fibo(ll n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	return Fibo(n-1) + Fibo(n-2);
	//if (fi[n-1] != INT64_MAX) fi[n-1] = Fibo(n-1);
	//if (fi[n-2] != INT64_MAX) fi[n-2] = Fibo(n-2);
	//return fi[n-1] + fi[n-2];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n = 0;
	cin >> n;
	//For(i, 0, n+10) fi.push_back(INT64_MAX);
	cout << Fibo(n) << endl;
	ll x = 1, y = 1, z = 0;
	For(i, 2, n)
	z = x + y,
	x = y,
	y = z;
	cout << z << endl;
}