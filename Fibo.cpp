#include <bits/stdc++.h>

using namespace std;

int n, ans, f[1000];

int main()
{
	cin >> n;
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= n; i++)
	f[i] = f[i-1] + f[i-2];
	for(int i = 1; i <= n; i++) ans += f[i];
	cout << ans << endl;
}