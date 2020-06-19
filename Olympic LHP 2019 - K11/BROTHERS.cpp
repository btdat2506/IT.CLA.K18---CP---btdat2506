#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, cost[210][210], f[500][210][210];

void process()
{
    For(s, 0, n-1+m-1)
    For(x1, 1, n)
    For(x2, 1, n)
    //if (x1 > x2)
    {
        ll y1 = s - x1 + 2,
           y2 = s - x2 + 2;
        f[s+1][x1][x2] = max(f[s+1][x1][x2], f[s][x1][x2] + cost[x1][y1+1] + cost[x2][y2+1]);
        f[s+1][x1+1][x2] = max(f[s+1][x1+1][x2], f[s][x1][x2] + cost[x1+1][y1] + cost[x2][y2+1]);
        f[s+1][x1+1][x2+1] = max(f[s+1][x1+1][x2+1], f[s][x1][x2] + cost[x1+1][y1] + cost[x2+1][y2]);
        if (x2 + 1 < x1)
        f[s+1][x1][x2+1] = max(f[s+1][x1][x2], f[s][x1][x2] + cost[x1][y1+1] + cost[x2+1][y2]);
    }
    cout << f[n-1+m-1][n][n] << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, n) 
    For(j, 1, m)
    cin >> cost[i][j];
}

int main()
{
    freopen("BROTHERS.INP", "r", stdin);
    freopen("BROTHERS.OUT", "w", stdout);
    input();
    process();
}