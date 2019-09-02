#include <bits/stdc++.h>

using namespace std;
int64_t n, k;

int64_t xuli(int64_t a, int64_t b)
{
    if (a - b <= 1 || (a + b) % 2) return 1;
    return xuli((a + b) / 2, b) + xuli((a - b) / 2, b);
}

int main()
{
    cin >> n >> k;
    cout << xuli(n, k);
}