#include <bits/stdc++.h>

using namespace std;
int64_t n, a[100010], t = 0;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)
int main()
{
    cin >> n;
    fill(a, a+n+10, 0);
    For(i, 1, n) cin >> a[i];
    For(i, 3, n+3) a[i] += max(a[i-3], a[i-2]);
    For(i, 1, n) t = max(t, a[i]);
    cout << t*2;
    return 0;
}