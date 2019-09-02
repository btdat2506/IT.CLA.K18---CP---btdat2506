#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second

typedef pair<ll, ll> ii;

ll n;
unordered_set <ll> th; //tap hop cac phan tu

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	queue <ii> q;
	For(i, 1, sqrt(n))
	if (n % i == 0) q.push(ii(i, n/i));
	while(q.size() != 0)
	{
		ll a = q.front().x, b = q.front().y;
		q.pop();
		ll c = (a-1) * (b+1);
		th.insert(c);
		if (c != 0)
		For(i, 1, sqrt(c))
		if (c % i == 0) q.push(ii(i, c/i));
	}
	cout << th.size() << endl;
}