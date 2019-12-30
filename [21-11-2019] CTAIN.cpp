#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, res, capacity[5], need[5], state[52][52][52][52];

queue <ii> qu;


void bfs()
{

}

void process()
{
	bfs()
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
		For(i, 1, n)
		cin >> capacity[i];
		For(i, 1, n)
		cin >> need[i];
		process();
	}
}