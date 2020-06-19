#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i += 2)

string st;

void process()
{
    if (st.length() == 2)
    {
        cout << st << "\n";
        return;
    }
    cout << st[0];
    For(i, 1, st.length()-2)
    cout << st[i];
    cout << st[st.length()-1] << "\n";
}

void input()
{
    cin >> st;
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