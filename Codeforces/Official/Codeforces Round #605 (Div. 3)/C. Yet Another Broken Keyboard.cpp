#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, cnt, ans;
bool isValid[30], validChar[1000000];
char st[1000000];

void process()
{
    For(i, 1, n)
    if (isValid[st[i] - 'a' + 1])
        cnt++;
    else
    if (cnt > 0)
    {
        ans += (cnt * (cnt + 1)) / 2;
        cnt = 0;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> k;
    For(i, 1, n) cin >> st[i];
    For(i, 1, k)
    {
        char ch;
        cin >> ch;
        isValid[ch - 'a' + 1] = 1;
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}