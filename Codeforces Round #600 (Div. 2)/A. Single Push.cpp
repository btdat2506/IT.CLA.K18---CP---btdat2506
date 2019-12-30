#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, a[100000], b[100000];

void process()
{
    bool kt = 0;
    ll pos1 = 1;
    while (pos1 != n && a[pos1] == b[pos1]) pos1++;
    ll pos2 = pos1 + 1;
    while (pos2 != n && pos2 != -1 && 
            a[pos2] + b[pos2-1] - a[pos2-1] == b[pos2] && 
                      b[pos2-1] - a[pos2-1] == b[pos2-2] - a[pos2-2]) 
    pos2 = (b[pos2-1] - a[pos2-1] > 0) ? pos2++ : -1;
    cout << pos1 << ' ' << pos2 << "\n";
    For(i, pos2, n) 
    if (a[i] != b[i])
    {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> a[i];
    For(i, 1, n)
    cin >> b[i];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        input();
        process();
    }
}