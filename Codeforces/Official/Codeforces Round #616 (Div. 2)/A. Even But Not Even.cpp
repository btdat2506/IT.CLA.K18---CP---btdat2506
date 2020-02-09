#include <bits/stdc++.h>

using namespace std;

//begin: 21:15 Feb 02 Sunday
//end: 16:55 Feb 04 Tuesday

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, cnt, pre;
string st;

void process()
{
    cnt = 0;
    st = ' ' + st;
    For(i, 1, n)
    {
        if ((st[i] - '0') % 2 == 1) 
        {
            cnt++;
            if (cnt == 1) pre = st[i] - '0';
        }
        if (cnt == 2)
        {
            cout << pre << st[i] << "\n";
            return;
        }
    }
    cout << "-1" << "\n";
}

void input()
{
    cin >> n >> st;
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
        input();
        process();
    }
}