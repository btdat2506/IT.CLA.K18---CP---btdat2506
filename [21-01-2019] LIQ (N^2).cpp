#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int i = a; i <= b; i++)
#define Ford(i, a, b) for(int i = a; i >= b; i--)

int n, a[1010], dem[1010], t = 0;

void process()
{
    For(i, 2, n)
    For(j, 1, i-1)
    if (a[j] < a[i]) dem[i] = max(dem[i], dem[j]+1);
}

void input()
{
    cin >> n;
    For(i, 1, n) cin >> a[i];
}

int main()
{
    fill(dem, dem+1010, 1);
    input();
    process();
    For(i, 1, n) t= max(t, dem[i]);
    cout << t;
    return 0;
}
