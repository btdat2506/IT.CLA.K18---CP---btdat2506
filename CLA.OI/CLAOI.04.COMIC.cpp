#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int64_t i = a; i <= b; i++)
vector <int64_t> a, b, xuli;
int64_t n, q;

int64_t bSearch(int64_t l, int64_t r, int64_t x)
{
    int64_t mid = (l + r) / 2;
    if (xuli[mid] == x) return mid;
    if (l >= r)
    {
        if (xuli[mid] < x) return mid;
        if (xuli[mid] > x) return mid-1;
    }
    if (xuli[mid] > x) return bSearch(l, mid - 1, x);
    return bSearch(mid + 1, r, x);
}

int main()
{
    cin >> n;
    a.resize(n+10);
    For(i, 1, n) cin >> a[i]; //a == gia tien
    cin >> q;
    b.resize(q+10);
    For(i, 1, q) cin >> b[i]; //b == truy van
    xuli = a;
    For(i, 2, n) xuli[i] += xuli[i-1];
    For(i, 1, q) cout << bSearch(1, n, b[i]) << endl;
    return 0;
}
