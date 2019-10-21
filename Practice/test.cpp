#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	map <ll, bool> mp;
	mp[10] = 1;
	cout << mp[10] << ' ' << mp[5] << "\n";
}