#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, a, b, ans, mark[10];
pair <ll, ll> pt[200010];

ll max(ll a, ll b, ll c, ll d)
{
	return max(max(a, b), max(c, d));
}

void process()
{
	For(i, 1, n)
	{
		if (pt[i].x < a) mark[1]++; else mark[2]++;
		if (pt[i].y < b) mark[3]++; else mark[4]++;
	}
	ans = max(mark[1], mark[2], mark[3], mark[4]);
	cout << ans << "\n";
	if (ans == mark[2])
		cout << a+1 << ' ' << b << "\n"; else
	if (ans == mark[4])
		cout << a << ' ' << b+1 << "\n"; else
	if (ans == mark[1]) 
		cout << a-1 << ' ' << b << "\n"; else
	if (ans == mark[3])
		cout << a << ' ' << b-1 << "\n";

}

void input()
{	
	cin >> n >> a >> b;
	For(i, 1, n)
	{
		cin >> pt[i].x >> pt[i].y;
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}