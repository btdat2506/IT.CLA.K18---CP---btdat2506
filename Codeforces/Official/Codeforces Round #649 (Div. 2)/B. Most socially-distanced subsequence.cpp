#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool state;
ll n, siz, p[100010], res[100010];

void process()
{
    siz = 1;
    res[1] = p[1];
    state = p[1] < p[2];
    //==========================
    For(i, 2, n)
    if ((p[i-1] < p[i]) != state)
        siz++,
        res[siz] = p[i-1],
        state = p[i-1] < p[i];
    //==========================
    siz++,
    res[siz] = p[n]; 
    //==========================
    cout << siz << "\n";
    For(i, 1, siz)
    cout << res[i] << ' ';
    cout << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> p[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }    
}