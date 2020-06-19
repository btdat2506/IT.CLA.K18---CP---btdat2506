#include <bits/stdc++.h>

using namespace std;

//begin: 21:42 Feb 09 Sunday
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, arr[400010];

void process()
{
    sort(arr+1, arr+1+2*n);
    cout << abs(arr[n] - arr[n+1]) << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, 2*n)
    cin >> arr[i];
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