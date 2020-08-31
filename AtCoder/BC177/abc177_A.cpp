#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll d, t, s;

void process()
{
    if (d / s < t || (d / s == t && d % s == 0))
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
}

void input()
{
    cin >> d >> t >> s;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}