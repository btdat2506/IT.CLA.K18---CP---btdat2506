#include <bits/stdc++.h>

using namespace std;

//start: 15h42 14/04/2020
//end:

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll b, c, ans, db[2510][510], top[510][510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("CW.INP", "r", stdin);
    freopen("CW.OUT", "w", stdout);
    while (cin >> b >> c)
    {
        memset(db, 0, sizeof(db));
        memset(top, 0, sizeof(top));
        ans = -1;
        if (b == 0 && c == 0) break;
        For(i, 1, b)
        {
            For(j, 1, c)
            {
                cin >> db[i][j];
                For(k, 1, j-1)
                top[db[i][k]][db[i][j]]++;
            }
        }
        For(i, 0, c-1)
        {
            bool ck = 1;
            For(j, 0, c-1)
            {
                if (i == j) continue;
                if (top[i][j] <= top[j][i]) 
                {
                    ck = 0;
                    break;
                }
            }
            if (ck == 1)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1) 
            cout << "No Condorcet winner" << "\n";
        else
        {
            cout << ans << "\n";
        }
    }
    
}