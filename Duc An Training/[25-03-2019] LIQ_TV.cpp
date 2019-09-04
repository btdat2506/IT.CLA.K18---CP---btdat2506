#include <bits/stdc++.h>
 
using namespace std;

int n, a[1010], dem[1010], T[1010], t = 0,  vt = 0;

#define For(i, a, b) for(int i = a; i <= b; i++)
#define Fod(i, a, b) for(int i = a; i >= b; i--) 
 
void process()
{
    For(i, 2, n)
    For(j, 1, i-1)
    {
        if (a[j] < a[i] && dem[j]+1 > dem[i]) 
        {
            dem[i] = max(dem[i], dem[j]+1);
            T[i] = j;
        }
    }
}
 
void input()
{
    cin >> n;
    For(i, 1, n) cin >> a[i];
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fill(dem, dem+1010, 1);
    input();
    process();
    For(i, 1, n) 
    {
        t = max(t, dem[i]);
        vt = i;
    }
    cout << t << endl;
    while (vt != 0)
    {
        cout << a[T[vt]] << ' ';
        vt = T[vt];
    }
    return 0;
}
 