#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, xuli[26000];

void process()
{
	xuli[3] += xuli[2];
	For(i, 4, n) xuli[i] += min(xuli[i-1], xuli[i-2]);
	cout << xuli[n] << endl;
}

void input()
{
	memset(xuli, 0, sizeof(xuli));
	cin >> n;
	For(i, 2, n) cin >> xuli[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}