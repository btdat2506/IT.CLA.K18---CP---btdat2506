#include <bits/stdc++.h>

using namespace std;
int64_t n, t, kq = 1e15;
#define For(i, a, b) for(int64_t i = a; i < b; i++)

int64_t total(int64_t a_xuli[])
{
    int64_t t = 0;
    a_xuli[2] += a_xuli[0];
    For(i, 3, n) a_xuli[i] += max(a_xuli[i-3], a_xuli[i-2]);
    For(i, 0, n) t = max(t, a_xuli[i]);
    return t;
}

int main()
{
    int64_t a[100];
    memset(a, 0, sizeof(a));
    cin >> n;
    For(i, 0, n) cin >> a[i];
    sort(a, a+n);
    do
    {
        int64_t b[100];
        memset(b, 0, sizeof(b));
        For(i, 0, n) b[i] = a[i];
        kq = min(kq, total(b));
    } while (next_permutation(a, a + n));
    cout << kq*2 << endl;
    //system("pause");
    return 0;
}