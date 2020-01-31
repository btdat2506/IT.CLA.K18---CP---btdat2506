#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, s, k;

void process(map <ll, bool> &notValid)
{
    For(i, 0, n)
    {
        if (s - i > 0)
        if (!notValid[s-i])
        {
            cout << i << "\n";
            return;
        }
        if (s + i <= n)
        if (!notValid[s+i])
        {
            cout << i << "\n";
            return;
        }
    }
}

void input(map <ll, bool> &notValid)
{
    cin >> n >> s >> k;
    For(i, 1, k)
    {
        ll tmp;
        cin >> tmp;
        notValid[tmp] = 1;
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        map <ll, bool> notValid;
        input(notValid);
        process(notValid);
    }
}