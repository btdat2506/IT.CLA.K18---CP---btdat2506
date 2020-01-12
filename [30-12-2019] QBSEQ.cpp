#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, f[1010][1010], arr[1010];
//array <ll> arr (1010, 0);

void define_value()
{
	For(j, 0, m) 	
	f[0][j] = -1e9;
	f[0][0] = 0;
}

void process()
{
	define_value();
	For(i, 1, n)
	For(j, 0, m-1)
	{
		f[i][j] = max(f[i-1][j], f[i-1][(j-arr[i]+m) % m] + 1);
	}
	cout << f[n][0] << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) 
	{
		cin >> arr[i];
		arr[i] %= m;
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}