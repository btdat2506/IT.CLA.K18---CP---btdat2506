#include <bits/stdc++.h>

using namespace std;
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n;
vector <vector <ll>> dat, a;

void init()
{
    a = dat;
    For(i, 1, m)
    For(j, 1, n)
    {
        if (a[i][j] >= 1 && a[i][j-1] >= 1) a[i][j] += a[i][j-1]; //tổng theo hàng ngang
    }
    For(j, 1, n)
    For(i, 1, m)
    {
        //tổng dọc xuống theo từng hàng dọc
        a[i][j] += a[i-1][j];
    }
    For(i, 1, m)
    For(j, 1, n)
    {

        if (dat[i][j] && dat[i-1][j] && dat[i][j-1])
    }
    /* 1 0 0 0 1
       0 1 2 3 5
       0 2 4 6 0
       0 3 0 10 0 */
}

void input()
{
    cin >> m >> n;
    dat.resize(m+10);
    For(i, 1, m) dat[i].resize(n+10);
    For(i, 0, m) dat[i][0] = 0;
    For(i, 0, n) dat[0][i] = 0;
    For(i, 1, m)
    For(j, 1, n)
    cin >> dat[i][j];
}

int main()
{
    input();
    init();
}