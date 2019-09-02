#include <bits/stdc++.h>

using namespace std;
#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)


const int nmax = 500;
ll v, e, visited[nmax], ck = 0, dem = 0;
vector <ll> db[nmax];
queue <ll> process;

void bfs()
{
    memset(visited, 0, sizeof(visited));
    process.push(1);
    visited[1] = 1;
    while(process.size() != 0)
    {
        ll s = process.front();
        process.pop();
        For(i, 0, db[s].size())
        if (!visited[db[s][i]])
        {
            visited[db[s][i]] = 1;
            process.push(db[s][i]);
        }
    }
    For(i, 1, v+1)
    if (!visited[i])
    {
        cout << i << endl;
        dem++;
    }
    if (dem == 0) cout << 0 << endl;
}


void input()
{
    cin >> v >> e;
    For(i, 0, e)
    {
        ll u, x;
        cin >> u >> x;
        db[u].push_back(x);
        db[x].push_back(u);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    input();
    bfs();
}
