#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int64_t i=a; i<=b; i++)
int64_t m, n, t1 = 0, t2 = 0, p1 = 0, p2 = 0, res = -1e9;
int64_t a[1000][1000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("CHOOSE.INP", "r", stdin);
    freopen("CHOOSE.OUT", "w", stdout);
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    For(i, 1, m)
    For(j, 1, n)
    cin >> a[i][j];
    For(i, 1, n-1)
    For(j, i+1, n)
    {
        t1 = 0;
        For(k, 1, m)
        if (a[k][i] + a[k][j] > t1)
        t2 = t1, t1 = a[k][i] + a[k][j];
        else
        t2 = max(t2, a[k][i] + a[k][j]);
        res = max(res, t1 + t2);
    }
    cout << res;
}