#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, valid, cnt, num[100010], low[100010];
vector <ll> edge[100010], res;
stack <ll> st;

void PrintResult()
{
    valid = 1;
    cout << res.size() + 1 << "\n";
    for(ll v: res)
        cout << v << ' ';
    cout << res[0];
}

void dfs(ll u)
{
    num[u] = low[u] = ++cnt;
    st.push(u);
    for(ll v: edge[u])
    if (!num[v])
    {
        dfs(v);
        low[u] = min(low[u], low[v]);
    }
    else
        low[u] = min(low[u], num[v]);
    if (num[u] == low[u])
    {
        ll v;
        do
        {
            v = st.top();
            st.pop();
            res.push_back(v);
            low[v] = num[v] = 1e12; //remove node v
        } while (v != u);
        if (res.size() > 2) 
        {
            PrintResult();
            return;            
        }   
        else
            res = vector <ll> ();
    }
}

void process()
{
    For(i, 1, n)
    if (!num[i] && !valid)
        dfs(i);
    if (!valid)
        cout << "IMPOSSIBLE" << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}