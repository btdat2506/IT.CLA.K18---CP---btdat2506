#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k;

vector <ll> quantity;

void process()
{
    ll sub = 0, ans;
    For(i, 0, 2*k) sub += quantity[i];
    ans = sub;
    For(i, 1, 1000000-2*k)
    {
        sub -= quantity[i-1];
        sub += quantity[i+k*2];
        ans = max(ans, sub);
    }
    cout << ans << endl;
}

void input()
{
   //freopen("MOBI.INP", "r", stdin);
   //freopen("MOBI.OUT", "w", stdout);
    cin >> n >> k;
    quantity.resize(4000000);
    For(i, 0, 4000000-1) quantity[i] = 0;
    For(i, 1, n) {ll x; cin >> x; cin >> quantity[x];}
}

int main()
{
    input();
    process();
}