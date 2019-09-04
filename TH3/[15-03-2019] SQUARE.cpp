#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll siz, maxx = 0, db[300][300], plus_down[300][300], plus_up[300][300];

ll Cal(ll x1, ll x2, ll y2)
{
    ll y1 = y2 - (x2 - x1);
    return plus_down[y2][x2] - plus_down[y1-1][x1 -1] - (plus_up[y2][x1] - plus_up[y1 - 1][x2 + 1]); 
}

void test()
{
    For(i, 1, siz)
    {
        For(j, 1, siz)
        cout << plus_up[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    For(i, 1, siz)
    {
        For(j, 1, siz)
        cout << plus_down[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void process()
{
    
    For(i, 1, siz)
    For(j, 1, siz)
        plus_down[i][j] = db[i][j] + plus_down[i-1][j-1],
        plus_up[i][j] = db[i][j] + plus_up[i-1][j+1];
    /*Fod(i, siz, 1)
    Fod(j, siz, 1)
    plus_up[i][j] = db[i][j] + plus_up[i-1][j-1];*/
    test();
    For(i, 1, siz-1)
    For(j, i+1, siz)
    For(k, j-i+1, siz)
    xmaxx = max(maxx, Cal(i, j, k));
    cout << maxx << endl;
}

void input()
{
    memset(db, 0, sizeof(db));
    memset(plus_down, 0, sizeof(plus_down));
    memset(plus_up, 0, sizeof(plus_up));
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);
    cin >> siz;
    For(i, 1, siz)
    For(j, 1, siz)
    cin >> db[i][j];
}

int main()
{
    input();
    process();
}