#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define MOD 14062008

ll n, k;
ll xuli[110000];

void process()
{
	xuli[1] = 1;
	For(i, 2, n)
	if (xuli[i] != 0)
	{
		xuli[i] = (xuli[i-1] + xuli[i-2]) % MOD;
		//cout << xuli[i-2] << ' ' << xuli[i-1] << ' ' << xuli[i] << endl;
	} else xuli[i] = 0;
	//For(i, 1, n+1) cout << xuli[i] << endl;
	cout << xuli[n+1] << endl;
}

void input()
{
	cin >> n >> k;
	For(i, 0, 101000) xuli[i] = 1;
	xuli[n+1] = xuli[0] = 0;
	For(i, 1, k) 
	{
		ll hong = 0;
		cin >> hong;
		//cout << hong << endl;
		xuli[hong] = 0;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input();
	process();
}