#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int i = a; i <= b; i++)
#define x first
#define y second
#define ft front
#define mp make_pair

queue <pair<int, int>> al; //analyze
pair <int, int> p[5], trace[10000][10000];
vector <vector<int>> db; //database
int m, n, xx, uu, yy, vv;
bool freed[10000][10000];
stack <pair<int, int>> result;

void cResult()
{
    pair <int, int> temp = make_pair(uu, vv);
    result.push(temp);
    while (temp != make_pair(xx, yy))
    {
        result.push(trace[temp.x][temp.y]);
        temp = result.top();
    }
}

void PrintResult()
{
    while (result.size() != 0)
    {
        cout << result.top().x << ' ' << result.top().y << endl;
        result.pop();
    }
}

void init(int i, int j)
{
    freed[i][j] = 1;

    if (!db[i][j+1] && !freed[i][j+1])
    {
        al.push(mp(i+0, j+1));
        trace[i][j+1] = mp(i, j);
        if (al.ft() == mp(uu, vv)) return;
    }

    if (!db[i][j-1]  && !freed[i][j-1])
    {
        al.push(mp(i+0, j-1));
        trace[i][j-1] = mp(i, j);
        if (al.ft() == mp(uu, vv)) return;
    }

    if (!db[i+1][j]  && !freed[i+1][j])
    {
        al.push(mp(i+1, j+0));
        trace[i+1][j] = mp(i, j);
        if (al.ft() == mp(uu, vv)) return;
    }

    if (!db[i-1][j]  && !freed[i-1][j])
    {
        al.push(mp(i-1, j+0));
        trace[i-1][j] = mp(i, j);
    }
}

void process()
{
    while (al.ft() != mp(uu, vv))
    {
        init(al.ft().x, al.ft().y);
        al.pop();
    }
    cResult();
}

void input()
{
	memset(freed, 0, sizeof(freed));
    cin >> m >> n;
    db.resize(m+10);
    For(i, 0, m+7) db[i].resize(n+10);
    For(i, 0, m) db[i][0] = 1;
    For(i, 0, n) db[0][i] = 1;
    For(i, 0, m) db[i][n+1] = 1;
    For(i, 0, n) db[m+1][i] = 1;
    For(i, 1, m)
    For(j, 1, n) cin >> db[i][j];
    cin >> xx >> yy >> uu >> vv;
    al.push(mp(xx, yy));
}

int main()
{
   // freopen("input.txt", "r", stdin);
    input();
    process();
    PrintResult();
    return 0;
}



/*
0 0 1 0
1 0 0 1
0 0 1 0
0 0 0 0 xuong duoi, sang phai, sang trai, len tren

dua vao queue nhung phan tu co kha nang di
dua vao mang trace - 2 chieu, pair int int - cac phan tu dang duoc di
dua vao mang freed nhung phan tu da di, khong duoc di

*/
