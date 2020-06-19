#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, a, b;
bool sorted, both_state, state;

void process()
{
    if (sorted || both_state)
        cout << "Yes" << "\n";
    else
    {
        cout << "No" << "\n";
    }
    
}

void input()
{
    cin >> n;
    For(i, 1, n) 
    {
        cin >> b;
        if (a > b) sorted = 0;
        a = b;
    }
    For(i, 1, n)
    {
        cin >> state;
        if (i == 1) 
            both_state = state;
        else
            if (both_state != state) both_state = 1;
    }
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
        a = 0;
        sorted = 1;
        input();
        process();
    }
}
