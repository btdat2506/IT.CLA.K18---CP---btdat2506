#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, a[20000];

void input()
{
	memset(a, 0, sizeof(a));
	cin >> n;
	For(i, 1, n) cin >> a[i];
}

void process()
{
	Fod(i, n, 2) cout << a[i] << ' ';
	cout << a[1];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	input();
	process();
}