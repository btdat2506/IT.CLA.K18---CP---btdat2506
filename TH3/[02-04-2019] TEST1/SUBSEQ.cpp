#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k;
vector <ll> xuli (1100000, 0), db(1100000, 0);

void process()
{
	xuli[0] = 0;
	For(i, 1, n) xuli[i] = xuli[i-1] + db[i];
	
}

void input()
{
	cin >> n >> k;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}