#include <bits/stdc++.h>
using namespace std;
int x, y;
int SoCachDi(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    x = SoCachDi(n-1);
    y = SoCachDi(n-2);
    return x + y + SoCachDi(n-3);
}

int main()
{
    int n = 0;
    cin >> n;
    cout << SoCachDi(n) << endl;
}
