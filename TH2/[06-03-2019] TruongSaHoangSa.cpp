#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define pr pair<ll, ll>
#define mp make_pair
#define x first
#define y second

ll n, res = 0, vtx[] = {0, 0, 0, 1, -1}, vty[] = {0, 1, -1, 0, 0};
bool db[1000][1000];

void bfs(ll i, ll j)
{
    queue <pr> process;
    process.push(mp(i, j));
    while (process.size() != 0)
    {
        i = process.front().x, j = process.front().y;
        db[i][j] = 0;
        For(dem, 1, 4)
        if (db[i + vtx[dem]][j + vty[dem]])
        {
            process.push(mp(i + vtx[dem], j + vty[dem]));
            db[i + vtx[dem]][j + vty[dem]] = 0;
        }
    }
    res++;
}

void input()
{
    memset(db, 0, sizeof(db));
    cin >> n;
    For(i, 1, n)
    For(j, 1, n) cin >> db[i][j];
}

int main()
{
    ll truyvan;
    cin >> truyvan;
    For(dem, 0, truyvan)
    {
        input();
        res = 0;
        For(i, 1, n)
        For(j, 1, n) if (db[i][j]) bfs(i, j);
        cout << res << endl;
    }
}