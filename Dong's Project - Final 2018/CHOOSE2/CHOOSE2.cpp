#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int64_t i=a; i<=b; i++)
int64_t m, n, t1 = 0, t2 = 0, p1 = 0, p2 = 0;
int64_t a[1000][1000], hang[1000][1000], cot[1000][1000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("CHOOSE2.INP", "r", stdin);
    freopen("CHOOSE2.OUT", "w", stdout);
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    For(i, 1, m)
    For(j, 1, n)
    cin >> a[i][j];
    For(i, 1, m)
    For(j, 1, n)
    hang[i][1] = a[i][1];
    For(i, 1, m)
    For(j, 1, n)
    cot[1][j] = a[1][j];
    For(i, 1, m)
    For(j, 1, n)
    hang[i][j] += hang[i][j-1];
    For(j, 1, n)
    For(i, 1, m)
    cot[i][j] += cot[i][j-1];
    int64_t maxx = -1e9, tmp, minn = 1e9, tmp2;
    For(c1, 1, n-1)
    For(c2, c1+1, n)
    {
        //minn = 1e9;
        For(j, 1, m)
        {
            tmp = cot[j][c1-1] + cot[j][c2] + ((hang[j][c1+1] + hang[j][c2-1]) - hang[j][c1]);
            if (tmp - minn > maxx) maxx = tmp - minn;
            tmp2 = hang[j][c1] + (hang[c2][c2] - hang[c2][j]) - ((hang[c1+1][c1] + hang[c1+1][c2]) - 2 * hang[j+1][c1-1]);
            minn = min(minn, tmp2);
        }
    }
    cout << maxx << endl;
    }
