#include <bits/stdc++.h>

using namespace std;
int n, m, u, v, data[10000][2], kc[100000][4], kq[100000];

int khoangcach(int x1, int y1, int x2, int y2)
{
    return ceil(sqrt(sqr(x1-x2)+sqr(y1-y2)));
}

int next_one(int daohientai, int dodai, int road[])
{
    for (int i = 0; i < n; i++)
    if (i != daohientai && kc[daohientai][i] <= m && kc[i][v] <= kc[daohientai][v])
    {
        next_one(i, )
    }
}

int main()
{
    freopen("Dao.inp", "r", stdin);
    cin >> n >> m >> u >> v;
    for (int i = 0; i < n; i++)
    cin >> data[i][0] >> data[i][1];
    for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
    kc[i][j] = khoangcach(data[i][0], data[i][1], data[j][0], data[j][1]);
    for (int i = 0; i < n; i++)

    return 0;
}
