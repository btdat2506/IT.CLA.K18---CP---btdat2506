#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans, db[100010];
vector <ll> endof;

void process()
{
	For(i, 1, n)
	{
		auto p = lower_bound(endof.begin(), endof.end(), db[i], greater<ll>());
		if (p == endof.end()) endof.push_back(db[i]); else endof[p-endof.begin()] = db[i];
	}
	cout << endof.size() << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}