#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define MOD (int64_t) 1000000007
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans, power[50010];
ll H[50010]; //hash string up (from left to right)
ll R[50010]; //hash string down (from right to left)
string st;

// Chú ý rằng `- hashT[i - 1] * pow[j - i + 1]` có thể âm.
// Với 1 số ngôn ngữ như C++, toán tử mod sẽ trả kết quả sai với số âm.
// Do đó ta cần thêm "+ MOD * MOD" để đảm bảo kết quả luôn chính xác.

ll getHashUp(ll i, ll j)
{
    return (H[j] - H[i - 1] * power[j - i + 1] + MOD * MOD) % MOD;
}

ll getHashDown(ll i, ll j)
{
    return (R[i] - R[j + 1] * power[j - i + 1] + MOD * MOD) % MOD;
}

ll isPalin(ll i, ll j)
{
    return getHashUp(i, j) == getHashDown(i, j);
}

void oddLengCase(ll l, ll r, ll pos)
{
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (isPalin(pos - mid, pos + mid))
            ans = max(ans, mid << 1 | 1), l = mid + 1;
        else
            r = mid - 1;
    }
}

void evenLengCase(ll l, ll r, ll pos)
{
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (isPalin(pos - mid + 1, pos + mid))
            ans = max(ans, mid << 1), l = mid + 1;
        else
            r = mid - 1;        
    }
}

void process()
{
    st = ' ' + st;
    power[0] = 1;
    For(i, 1, n)
    power[i] = (power[i-1] * 32) % MOD;
    For(i, 1, n)
    H[i] = (H[i-1] * 32 + st[i] - 'a' + 1) % MOD;
    Fod(i, n, 1)
    R[i] = (R[i+1] * 32 + st[i] - 'a' + 1) % MOD;

    For(i, 1, n)
    {
        oddLengCase(0, min(i, n - i), i);
        evenLengCase(0, min(i - 1, n - i), i);
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> st;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}