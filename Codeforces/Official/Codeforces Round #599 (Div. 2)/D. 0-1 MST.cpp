#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)


ll n, m;
map <ll, bool> g;
set <ll> st;

void process()
{
    For(i, 1, n) st.push(i);
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    process();
}