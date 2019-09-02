#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int64_t i = a; i <= b; i++)

int64_t n, a[100010], q, trace[100010];

int64_t bSearch(int64_t xuli[], int64_t l, int64_t r, int64_t x)
{
    int64_t mid = (l + r) / 2;
    if (l >= r) 
    if (xuli[l] <= x) return l; else return l-1;
    if (xuli[mid] > x) return bSearch(xuli, l, mid - 1, x);
    return bSearch(xuli, mid + 1, r, x);
}

void run()
{
    int64_t xuli[100010];
    memset(xuli, 0, sizeof(xuli));
    sort(a+1, a+n+1);
    For(i, 1, n) xuli[i] = a[i] + xuli[i-1];
    For(dem, 1, q)
    {
        int64_t temp = bSearch(a, 1, n, trace[dem]);
        //cout << temp << endl;
        cout << (trace[dem]*temp - xuli[temp]) + (xuli[n] - xuli[temp] - trace[dem]*(n - temp)) << endl;
    }
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(trace, 0, sizeof(trace));
    cin >> n;
    For(i, 1, n) cin >> a[i];
    cin >> q;
    For(i, 1, q) cin >> trace[i];
    run();
   // system("pause");
    return 0;
}