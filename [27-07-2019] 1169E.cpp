#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, query, arr[400000], recent[20], next_pos[400000][20];

void getans()
{
	while (query--)
	{
		ll x, y;
		cin >> x >> y;
		bool ck = 0;
		For(bit, 0, 18)
		if (arr[y] & (1 << bit) && next_pos[x][bit] <= y)
		{
			ck = 1;
			break;
		}
		cout << (ck ? "Shi" : "Fou") << endl;
	}
}

void process()
{
	For(i, 0, 19) recent[i] = INT64_MAX;
	Fod(i, n, 1)
	{
		For(bit, 0, 18)
		next_pos[i][bit] = INT64_MAX;
		For(bit, 0, 18)
		if (arr[i] & (1 << bit))
		{
			ll where = recent[bit];
			if (where != INT64_MAX)
			{
				next_pos[i][bit] = min(next_pos[i][bit], where);
				For(bit2, 0, 18)
				 	next_pos[i][bit2] = min(next_pos[i][bit2], next_pos[where][bit2]);
			}
			recent[bit] = i;
		}
	}
}

void input()
{
	cin >> n >> query;
	For(i, 1, n) cin >> arr[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	getans();
}