#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int64_t i=a; i<=b; i++)
int64_t m, n, k, t, maxx = 0, land[1000][1000], sum[1000][1000], sl = 0;

int64_t Tong(int64_t x, int64_t y, int64_t u, int64_t v)
{
    return sum[u][v] - sum[x-1][v] - sum[u][y-1] + sum[x-1][y-1];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("LAND.INP", "r", stdin);
    freopen("LAND.OUT", "w", stdout);
    cin >> m >> n >> k >> t;
    memset(land, 0, sizeof(land));
    memset(sum, 0, sizeof(sum));
    For(i, 1, m)
    For(j, 1, n)
    {
        cin >> land[i][j];
        sum[i][j] += land[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }
    For(i, 1, m)
    For(j, 1, n)
    For(k, maxx + 1, min(m-i+1, n-j+1))
    if (Tong(i, j, i+k-1, j+k-1) <= t) maxx = max(maxx, k); else break;
    cout << maxx*maxx;
}
