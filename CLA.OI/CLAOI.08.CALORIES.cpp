#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)

int main()
{
    int64_t n, res = 1e15, a[100010], b[100010], ans = INT64_MAX, maxx = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    For(i, 2, n) b[i] += b[i-1];
    For(i, 1, n)
    {
        ans = min(ans, b[i] - maxx);
        maxx = max(maxx, b[i]);
    }
    cout << ans;
    system("pause");
    return 0;
}
 // voi so minh dang co o hien tai minh tru cho so lon nhat thi minh se duoc so nho nhat