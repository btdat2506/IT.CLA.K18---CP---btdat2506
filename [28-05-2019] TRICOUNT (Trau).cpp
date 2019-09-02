//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, a[10000], ans = 0;

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	for(int i = 1; i <= n-2; i++)
	for(int j = i+1; j <= n-1; j++)
	for(int k = j+1; k <= n; k++)
	if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]) ans++;
	cout << ans << endl;
}
