#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
ll n, t[70000], r[70000], xuli[70000]; 

void input()
{
	memset(t, 0, sizeof(t));
	memset(r, 0, sizeof(r));
	memset(xuli, 0, sizeof(xuli));
	cin >> n;
	For(i, 1, n) cin >> t[i];
	for(ll i = 1; i < n; i++) cin >> r[i];
}
 
void process()
{
	xuli[1] = t[1], xuli[2] = min(t[1] + t[2], r[1]);
	For(i, 3, n) xuli[i] = min(xuli[i-1] + t[i], xuli[i-2] + r[i-1]);
	cout << xuli[n] << endl;
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}