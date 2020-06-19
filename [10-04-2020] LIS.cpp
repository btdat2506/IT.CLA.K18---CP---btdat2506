#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, leng, db[30010], endof[30010];

void process()
{
    endof[1] = db[1];
    leng = 1;
    For(i, 1, n)
    {
        if (db[i] > endof[leng]) endof[++leng] = db[i];
        else
        {
            ll pos = lower_bound(endof+1, endof+1+leng, db[i]) - endof;
            endof[pos] = db[i];
        }
    }
    cout << leng << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> db[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}