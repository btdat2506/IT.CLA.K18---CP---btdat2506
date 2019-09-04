#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int64_t i=a; i<=b; i++)
int64_t m, n, q, a[1000]={}, arr[1000][4]={}, d[1000]={};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("INCMAT.INP", "r", stdin);
    freopen("INCMAT.OUT", "w", stdout);
    cin >> n;
    For(j, 1, n)
    cin >> a[j];
    cin >> q;
    For(i, 1, q)
    cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    For(i, 1, q)
    {
        d[arr[i][2]+1] -= arr[i][3];
        d[arr[i][1]] += arr[i][3]; 
    }
    For(i, 2, n) d[i] += d[i-1];
    For(i, 1, n) cout << a[i]+d[i] << ' ';
    return 0;
}