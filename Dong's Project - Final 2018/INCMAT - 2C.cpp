#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int64_t i=a; i<=b; i++)
int64_t m, n, q, a[10000][10000]={}, arr[100010][4]={}, d[100010][100010]={};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("INCMAT.INP", "r", stdin);
    freopen("INCMAT.OUT", "w", stdout);
    cin >> m >> n;
    For(i, 1, m)
    For(j, 1, n)
    cin >> a[i][j];
    cin >> q;
    For(i, 1, q)
    cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4] >> arr[i][5];
    For(i, 1, q)
    {
        d[arr[i][1]][arr[i][2]] += arr[i][5];
        d[arr[i][3]][arr[i][2]] += arr[i][5];
        d[arr[i][1]][arr[i][5]+1] -= arr[i][5];
        d[arr[i][3]][arr[i][5]+1] -= arr[i][5];
        d[arr[i][1]+1][arr[i][5]] -= arr[i][5];
        d[arr[i][3]+1][arr[i][5]] -= arr[i][5];
    }
    For(i, 2, n) d[i] += d[i-1];
    
    return 0;
}