#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll arr[6][6] = {
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
	};
};

typedef pair<dt, ll> ii;

dt start;
ll finish = 0;
ll move_x[] = {0, -1, 1, 0, 0},
   move_y[] = {0, 0, 0, -1, 1}; //len, xuong, trai, phai
ll d[100000]; 

ll getnum(dt ar)
{
	ll num = 0;
	For(i, 1, 4)
	For(j, 1, 4)
	num = num * 2 + ar.arr[i][j];
	return num;
}

void process() //bfs
{
	d[getnum(start)] = 1;
	queue <ii> st;
	st.push(ii(start, 1));
	while (!st.empty())
	{
		ll step = st.front().y;
		dt db = st.front().x;
		st.pop();
		if (getnum(db) == finish) break;
		For(i, 1, 4)
		For(j, 1, 4)
		if (db.arr[i][j] == 1)
		{
			For(k, 1, 4)
			{
				ll x_temp = i + move_x[k],
				   y_temp = j + move_y[k];
				if (x_temp != 0 && x_temp != 5 &&
					y_temp != 0 && y_temp != 5 &&
					db.arr[x_temp][y_temp] == 0)
				{
					swap(db.arr[x_temp][y_temp], db.arr[i][j]);
					ll num_temp = getnum(db);
					if (d[num_temp] == 0)
					{
						st.push(ii(db, step + 1));
						d[num_temp] = step + 1;
					}
					swap(db.arr[x_temp][y_temp], db.arr[i][j]);
				}
			}
		}
	}
	cout << d[finish] - 1 << endl;
}	

void input()
{
	For(i, 1, 4)
	For(j, 1, 4)
	{
		char ch;
		cin >> ch;
		start.arr[i][j] = (ll) (ch - '0');
	}
	For(i, 1, 4)
	For(j, 1, 4)
	{
		char ch;
		cin >> ch;
		finish = (finish * 2) + (ll) (ch - '0');
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}