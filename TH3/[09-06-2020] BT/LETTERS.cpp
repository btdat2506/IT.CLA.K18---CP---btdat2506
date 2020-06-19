#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, k, ans, sum[410][410];
char db[410][410];

ll cnt(ll r1, ll r2, ll c1, ll c2)
{
    return sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
}

void process()
{
    ll ts[100];

    //pre process
    For(i, 1, n)
    For(j, 1, m)
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + int(db[i][j] == 'a');

    //process
    For(r1, 1, n)
    For(r2, r1+1, n)
    {
        memset(ts, 0, sizeof(ts));
        unsigned int c1 = 1;
        For(c2, 1, m)
        {
            while (c1 < c2 && cnt(r1, r2, c1, c2) > k)
            {
                if (db[r1][c1] == db[r2][c2]) ts[db[r1][c1] - 'a' + 1]--;
                c1++;
            }
            if (db[r1][c2] == db[r2][c2])
            {
                ans += ts[db[r1][c2] - 'a' + 1];
                ts[db[r1][c2] - 'a' + 1]++;
            }
        }
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> m >> k;
    For(i, 1, n)
    For(j, 1, m)
    cin >> db[i][j];
}

int main()
{
    freopen("LETTERS.INP", "r", stdin);
    freopen("LETTERS.OUT", "w", stdout);
    input();
    process();
}