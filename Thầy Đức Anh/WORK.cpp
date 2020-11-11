#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool db[101][101], used[101];
ll n, k, t, Visited[101], Assigned[101], d, cnt;
vector <ll> a[101];

bool visit(int u) {
    if (Visited[u] != t)
        Visited[u] = t;
    else
        return false;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
		if (!used[v])
        if (!Assigned[v] || visit(Assigned[v])) {
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}

void process()
{
	while (cnt <= n)
	{
		For(i, 1, n)
		{
			t++; 
			cnt += visit(i);
		}
		cout << ++d << '\n';
		For(i, 1, n)
		if (int j = Assigned[i])
		{
			cout << i << " " << j << "\n"; 
			used[j] = 1;
		}
		t = 0;
		memset(Assigned, 0, sizeof(Assigned));
		memset(Visited, 0, sizeof(Visited));
	}
}

void input()
{
	cin >> n >> k;
	For(i, 1, n)
	For(j, 1, k)
	{
		cin >> db[i][j];
		if (db[i][j] == 1) a[i].push_back(j);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}