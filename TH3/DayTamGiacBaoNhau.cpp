#include <bits/stdc++.h>

using namespace std;

struct dat
{
    double dt = 0; // dien tich
    int stt = 0; //so thu tu
    pair <int, int> a;
    pair <int, int> b;
    pair <int, int> c;
};

double dientich(pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
    return abs((b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second)) / 2;
}

bool Comparison(const dat &l, const dat &r)
{
    return l.dt < r.dt;
}

bool kiemtra(dat data[], int i, int j)
{
    if (
    data[i].dt == dientich(data[i].a, data[i].b, data[j].a)
                + dientich(data[i].a, data[i].c, data[j].a)
                + dientich(data[i].b, data[i].c, data[j].a)
    &&
    data[i].dt == dientich(data[i].a, data[i].b, data[j].b)
                + dientich(data[i].a, data[i].c, data[j].b)
                + dientich(data[i].b, data[i].c, data[j].b) 
    &&
    data[i].dt == dientich(data[i].a, data[i].b, data[j].c)
                + dientich(data[i].a, data[i].c, data[j].c)
                + dientich(data[i].b, data[i].c, data[j].c)
    ) return 1; else return 0;
}

int main()
{
    int n, res = 0;
    cin >> n;
    dat data[n+100];
    for (int i = 0; i < n; i++)
    cin >> data[i].a.first >> data[i].a.second >> data[i].b.first >> data[i].b.second >> data[i].c.first >> data[i].c.second;
    for (int i = 0; i < n; i++)
    {
        data[i].dt = dientich(data[i].a, data[i].b, data[i].c); 
        data[i].stt = i;
    }
    sort(data, data+n, Comparison);
    int c[100000];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++) 
        if (kiemtra(data, i, j)) c[i]++;
        res = max(res, c[i]);
    }
    cout << res << endl;
    system("pause");
    return 0;
}