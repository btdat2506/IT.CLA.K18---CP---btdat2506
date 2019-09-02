#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)

int main()
{
    int64_t n;
    cin >> n;
    int64_t a[n+n];
    For(i, 1, n) a[i] = i;
    int64_t dem = n;
    do
    {
        For(i, 1, n) cout << a[i];
        cout << endl;
        dem = n - 1;
        while (dem > 0 && a[dem] > a[dem+1]) dem--;
        if (dem > 0)
        {
            int k = n;
            while (a[k] < a[dem]) k--;
            swap(a[k], a[dem]);
            int x = dem + 1, y = n;
            while (x < y)
            {
                swap(a[x], a[y]);
                x++;
                y--;

            }
        }
    } while (dem > 0);
}
