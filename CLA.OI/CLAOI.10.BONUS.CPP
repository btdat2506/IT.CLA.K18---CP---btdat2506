#include <bits/stdc++.h>

using namespace std;
int64_t m, n, sltv; //sltv == so luong truy van
vector <vector <int64_t>> database, hang, cot, tv, tt; // tt == the tich
#define For(i, a, b) for(int64_t i = a; i <= b; i++)

void init() //tao thanh tong hang, tong cot, va tong the tich tu (0,0) den (i,j)
{
    cin >> m >> n >> sltv;
    database.resize(m+10);
    For(i, 0, m+5) database[i].resize(n+10);
    For(i, 0, m+5)
    For(j, 0, n+5) database[i][j] = 0;
    For(i, 1, m)
    For(j, 1, n)
    cin >> database[i][j];
    tv.resize(sltv+10);
    For(i, 1, sltv)
    {
        tv[i].resize(10);
        For(j, 1, 8) cin >> tv[i][j];
    }
    tt = hang = cot = database;
    For(i, 1, m)
    For(j, 1, n)
    hang[i][j] += hang[i][j-1];
    For(j, 1, n)
    For(i, 1, m)
    cot[i][j] += cot[i-1][j];
    For(i, 1, m)
    For(j, 1, n)
    tt[i][j] += hang[i][j-1] + cot[i-1][j] + tt[i-1][j-1]; //cong voi o tren va o ben trai
}

void xuli()
{
    For(i, 1, sltv)
    {
        int64_t x = max(tv[i][1], tv[i][5]), y = max(tv[i][2], tv[i][6]), u = min(tv[i][3], tv[i][7]), v = min(tv[i][4], tv[i][8]);
        if (x > u || y > v) cout << 0 << endl; else cout << tt[u][v] - tt[x-1][v] - tt[u][y-1] + tt[x-1][y-1] << endl;
        //cout << tt[tv[i][3]][tv[i][4]] - tt[tv[i][1]-1][tv[i][4]] - tt[tv[i][3]][tv[i][2]-1] + tt[tv[i][1]-1][tv[i][2]-1] << endl;
    }
}

int main()
{
    init();
    xuli();
    return 0;
}


/*

   tt[tv[i][3]][tv[i][4]] - tt[tv[i][1]-1][tv[i][4]]
    - tt[tv[i][3]][tv[i][2]-1] + tt[tv[i][1]-1][tv[i][2]-1]


*/
