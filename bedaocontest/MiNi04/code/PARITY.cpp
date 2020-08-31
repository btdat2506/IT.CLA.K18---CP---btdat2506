#include <bits/stdc++.h>

using namespace std;
const string filename = "PARITY";

int n;
int a[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> n;                    
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << ((accumulate(a + 1, a + 1 + n, 0LL) % 2) ? "NO" : "YES");
}