#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll v, e, visited[10000], ck = 0;
vector <ll> a[10000];
queue <ll> process;


void bfs(ll s)
{
    memset(visited, 0, sizeof(visited));
    process.push(s);
    visited[s] = 1;
    while(process.size() != 0)
    {
        s = process.front();
        cout << s << endl;
        process.pop();
        For(i, 0, a[s].size()-1)
        if (!visited[i])
        {
            visited[i] = 1;
            process.push(i);
        }
    }
}

void input()
{
    cin >> v >> e;
    For(i, 0, e)
    {
        ll u, x;
        cin >> u >> x;
        a[u].push_back(x);
    }
}

int main()
{
    input();
    bfs(0);
}