#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
struct dt
{
	ll a = 0, b = 0;
};
 
bool cmp (const dt &L, const dt &R)
{
	if (L.a == R.a) return L.b < R.b;
	return L.a > R.a;
}

 
dt db[20010];
ll n;
 
void process()
{
	sort(db+1, db+1+n, cmp);
	vector <ll> endof;
	For(i, 1, n)
	{
		ll itr = upper_bound(endof.begin(), endof.end(), db[i].b) - endof.begin();
		if (itr == endof.size()) endof.push_back(db[i].b); else
		endof[itr] = db[i].b;
	}
	cout << endof.size() << "\n";
}
 
void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i].a >> db[i].b;
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		input();
		process();
	}
}  