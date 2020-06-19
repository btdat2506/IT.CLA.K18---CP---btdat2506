#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m;
bool row[60], column[60];

void process()
{
    ll cnt = 0, x = 0, y = 0;
    For(i, 1, n) if (row[i]) x++;
    For(i, 1, m) if (column[i]) y++;
     
    if (min(x, y) % 2 == 0)
        cout << "Vivek" << "\n";
    else
        cout << "Ashish" << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, n)
    For(j, 1, m)
    {
        bool state;
        cin >> state;
        if (state == 1) row[i] = column[j] = !state;
    }
}

void init()
{
    memset(row, true, sizeof(row));
    memset(column, true, sizeof(column));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        input();
        process();
    }
}