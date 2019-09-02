#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, m;
string a, b;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> a >> b;
	ll j = 0;
	For(i, 0, a.length())
	if (a[i] == b[j]) j++; else j = 0;
	cout << a + b.substr(j, b.length()-j);
}