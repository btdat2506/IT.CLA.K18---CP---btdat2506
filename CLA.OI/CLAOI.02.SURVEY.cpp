#include <bits/stdc++.h>

using namespace std;
int64_t m, n, sltv; //sltv == so luong truy van
vector <vector <int64_t>> data, hang, cot, tv, tt; // tt == the tich
#define For(i, a, b) for(int64_t i = a; i <= b; i++)

void init() //tao thanh tong hang, tong cot, va tong the tich tu (0,0) den (i,j)
{
    cin >> m >> n;
    data.resize(m+10);
    For(i, 0, m+5) data[i].resize(n+10);
    For(i, 0, m+5)
    For(j, 0, n+5) data[i][j] = 0;
    For(i, 1, m)
    For(j, 1, n)
    cin >> data[i][j];
    cin >> sltv;
    tv.resize(sltv+10);
    For(i, 1, sltv)
    {
        tv[i].resize(10);
        cin >> tv[i][1] >> tv[i][2] >> tv[i][3] >> tv[i][4];
        // truy van, 1 == x, 2 == y, 3 == u, 4 == v, voi (x, y), (u, v)
    }
    tt = hang = cot = data;
    //cot == tong cac cot tren 1 hang, tuong tu
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

void test()
{
    cout << endl << "Hang:" << endl;
    For(i, 1, m)
    {
        For(j, 1, n)
        cout << hang[i][j] << ' ';
        cout << endl;
    }
    cout << endl << "Cot: " << endl;
    For(i, 1, m)
    {
        For(j, 1, n)
        cout << cot[i][j] << ' ';
        cout << endl;
    }
    cout << endl << "The tich: " << endl;
    For(i, 1, m)
    {
        For(j, 1, n)
        cout << tt[i][j] << ' ';
        cout << endl;
    }
}

void xuli()
{
    For(i, 1, sltv)
    cout << tt[tv[i][3]][tv[i][4]] - tt[tv[i][1]-1][tv[i][4]]
    - tt[tv[i][3]][tv[i][2]-1] + tt[tv[i][1]-1][tv[i][2]-1] << endl;
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
