#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans;
string burles;

void process()
{
    //thuật toán ban đầu có bug: do là mỗi lần lấy ra 1 số rồi mới tính chứ không tính vào dư liền nên là có lỗi
    /* 
    
    n = burles.length();
    ans = 0, odd = 0;
    burles = ' ' + burles;
    Fod(i, n, 1)
    {
        For(j, 0, n-i)
        ans += (burles[i] - '0') * pow(10, j);
        odd += (burles[i] - '0');
    }
    //chuyển odd về burles
    //fix lỗi mỗi lần xong lấy ban đầu trừ ra cộng vào phần dư rồi xét (xem ví dụ)
    ans += (double) ((double) (odd / 10) + (double) 0.5); */
    ans = 0;
    ll odd, cash_back, total = n;
    while (total >= 10)
    {
        odd = total % 10;
        ans += total - odd;
        cash_back = (total - odd) / 10;
        total = odd + cash_back;
    }
    ans += total;
    cout << ans << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
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