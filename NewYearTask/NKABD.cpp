#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)
int64_t a, b, s = 0;

bool sophongphu(int64_t kt)
{
    int64_t dem = 1;
    For(i, 2, sqrt(kt))
    if (kt % i == 0)
    {
        dem += kt / i;
        if (kt / i != i) dem += i; 
        if (dem > kt) return 1;
    }
    return dem > kt;
}

int main()
{
    cin >> a >> b;
    For(i, a, b) s += sophongphu(i);
    cout << s;
}