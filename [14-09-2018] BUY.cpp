#include <bits/stdc++.h>

using namespace std;

int m, n, total = 0;

struct a
{
    int sl, cost, stt;
};

a in[10000];
a out[10000];

bool Comparison(const a &l, const a &r)
{
    return l.cost < r.cost;
}

bool Comparison1(const a &l, const a &r)
{
    return l.stt < r.stt;
}

void analyze(int i)
{
    int qtt = 0;
    if (in[i].sl <= m) qtt = in[i].sl; else qtt = m;
    total +=  in[i].cost * qtt;
    m -= qtt;
    out[i].sl = qtt;
    out[i].cost = in[i].cost;
    out[i].stt = in[i].stt;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i].sl >> in[i].cost;
        in[i].stt = i;
    }
    sort(in, in + n, Comparison);
    for (int i=0; i<=n-1; i++) analyze(i);
    sort(out, out + n, Comparison1);
    cout << total << endl;
    for (int i = 0; i < n; i++) cout << out[i].sl << " ";
    return 0;
}
