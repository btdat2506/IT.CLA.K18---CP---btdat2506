#include <bits/stdc++.h>

using namespace std;

//begin: 20:07
//end: 8:14

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, cnt[20][20], ans;

int fir(ll i)
{
    ll tmp;
    while (i != 0)
    {
        tmp = i;
        i /= 10;
    }
    return tmp;
}

int las(ll i)
{
    return i % 10;
}

void process()
{
    For(i, 1, n)
    cnt[fir(i)][las(i)]++;
    For(i, 1, 9)
    For(j, 1, 9)
    ans += cnt[fir(i)][las(j)]*cnt[las(j)][fir(i)];
    cout << ans << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}