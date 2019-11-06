#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef int64_t ll;

struct Data
{
    ll a = 0, b = 0;
};

Data db[100010];
ll n, ans, res;

bool cmp(const Data &L, const Data &R)
{
    return min(L.a, R.b) < min(L.b, R.a);
}

void process()
{   
    sort(db+1, db+1+n, cmp);
    For(i, 1, n)
    {
        res -= db[i].a;
        if (res < 0) 
            ans += -res, 
            res = 0;
        res += db[i].b;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> db[i].a;
    For(i, 1, n)
    cin >> db[i].b;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PRJCHAIN.INP", "r", stdin);
    freopen("PRJCHAIN.OUT", "w", stdout);
    input();
    process();
}