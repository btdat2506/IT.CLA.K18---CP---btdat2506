#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;
string t;

ll mod()
{
	ll r = 0;
	for(ll i = 0; i < t.length(); i++)
	{
		r = r * 10 + (t[i] - '0');
		r %= n;
	}
	return r;
}

void process()
{
	queue <string> qu;
	set <int> visit;
	qu.push("1");
	while (!qu.empty())
	{
		t = qu.front();
		qu.pop();
		ll rem = mod();
		if (!rem) break;
		else
		if (visit.find(rem) == visit.end())
		{
			visit.insert(rem);
			qu.push(t + '0');
			qu.push(t + '1');
		}
	}
	cout << t << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		process();
	}
}