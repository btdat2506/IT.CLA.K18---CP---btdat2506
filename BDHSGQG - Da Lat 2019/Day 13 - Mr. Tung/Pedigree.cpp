#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, generation[100010];
bool children[100010], visited[100010];
array <string, 100010> d;
string st1, st2;
map <string, ll> mp1;
vector <ll> edge[100010];

void dfs(ll gen, ll pos)
{
    visited[pos] = 1;
    generation[pos] = gen;
    for(ll v: edge[pos])
    if (!visited[v]) dfs(gen+1, v);
}

void process()
{
    For(i, 1, m)
    if (!children[i] && !visited[i]) dfs(0, i);
    For(i, 1, m)
    for(auto x: mp1)
    cout << x.first << ' ' << generation[x.second] << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        cin >> st1 >> st2;
        mp1[st1] = ++m; d[m] = st1; children[m] = 1;
        mp1[st2] = ++m; d[m] = st2;
        edge[m-1].push_back(m);
    }
}

int main()
{
    freopen("PEDIGREE.INP", "r", stdin);
    freopen("PEDIGREE.OUT", "w", stdout);
    input();
    process();
}