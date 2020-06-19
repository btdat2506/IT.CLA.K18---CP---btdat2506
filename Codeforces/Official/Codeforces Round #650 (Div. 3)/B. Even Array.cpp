#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

//về cơ bản, đÂy là bài xếp chỗ số chẵn là chẵn, số lẻ là lẻ

ll n, cnt[2], a[50];

void process()
{
    memset(cnt, 0, sizeof(cnt));
    For(i, 0, n)
    if (a[i] % 2 != i % 2)
        cnt[a[i] % 2]++;
    if (cnt[0] == cnt[1])
        cout << cnt[0] << "\n";
    else
        cout << -1 << "\n";
}

void input()
{
    cin >> n;
    For(i, 0, n)
    cin >> a[i];
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