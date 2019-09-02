#include <bits/stdc++.h>
using namespace std;
#define For(x, y, z) for(int64_t x = y; x <= z; x++)
using namespace std;
int64_t m, n, s = 0, in[100010], out[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("GRTRAVEL.INP", "r", stdin);
    freopen("GRTRAVEL.OUT", "w", stdout);
    cin >> n >> m;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    For(i, 1, n)
    {
        in[i] = n - i;
        out[i] = i - 1;
    }
    For(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        in[x]--, in[y]++,
        out[x]++, out[y]--;
    }
    For(i, 1, n) s += (out[i]-1)*out[i]/2+(in[i]-1)*in[i]/2;
    int64_t res = n *(n-1)*(n-2) / 6; //cong thuc to hop chap 3
    cout << res - s / 2;
    return 0;
}