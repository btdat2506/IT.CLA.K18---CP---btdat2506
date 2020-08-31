#include <bits/stdc++.h>

using namespace std;
const string filename = "CTABLE";

int m, n;
string a[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int ans = 1e9;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			for (int x = i; x < min(m, i + 27); x++)
				for (int y = j; y < min(n, i + 27); y++)
					if ((x != i || y != j) && a[i][j] == a[x][y])
						ans = min(ans, x - i + y - j);
	cout << ans;
}