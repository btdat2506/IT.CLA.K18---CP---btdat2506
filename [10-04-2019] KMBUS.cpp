#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll b, l, c[200], f[11000];

void process()
{
	
	For(i, 1, l)
	{
		f[i] = INT_MAX;
		For(j, 0, i)
		f[i] = min(f[i], f[j] + c[i-j]);
	}
	cout << f[l] << endl;
	For(i, 1, l) cout << f[i] << endl;
}

void input()
{
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	cin >> b >> l;
	For(i, 1, b) cin >> c[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}