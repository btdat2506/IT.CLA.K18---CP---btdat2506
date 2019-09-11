#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll k;

void process()
{
	queue <ll> st;
	For(i, k+1, 2*k)
	if ((k*i) % (i-k) == 0)
	st.push(i);
	cout << st.size() << "\n";
	while (!st.empty())
	{
		ll x = st.front();
		st.pop();
		cout << "1/" << k << " = 1/" << (ll) ((k*x)/(x-k)) << " + 1/" << x << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(cin >> k)
	process();
}