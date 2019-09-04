#include <bits/stdc++.h>

using namespace std;

#define ll int
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, ans = INT_MAX, arr1[100010], arr2[100010];

void process()
{
    sort(arr1, arr1+n);
    For(i, 0, n)
    {   
        ll y = lower_bound(arr1, arr1+n, -arr2[i]) - arr1;
        if (y > 0) ans = min(ans, abs(arr2[i] + arr1[y-1]));
        else ans = min(ans, abs(arr2[i] + arr1[y]));
    }
    cout << ans;
}

void input()
{
    cin >> n;
    For(i, 0, n)
    cin >> arr1[i];
    For(i, 0, n)
    cin >> arr2[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    input();
    process();
}
