#include <bits/stdc++.h>

using namespace std;
const string filename = "CHANGE";

long long a, b;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> a >> b;
	int cnt = __builtin_popcountll(a ^ b);
	cout << ((cnt % 2) ? -1 : cnt / 2);
}