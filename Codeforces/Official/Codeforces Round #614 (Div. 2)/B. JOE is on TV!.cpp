#include <bits/stdc++.h>

using namespace std;

//begin: 18:27
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;
double ans;

void process()
{
    cout << setprecision(12) << fixed;
    For(i, 1, n)
    ans += 1/(double)i;
    cout << ans << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}