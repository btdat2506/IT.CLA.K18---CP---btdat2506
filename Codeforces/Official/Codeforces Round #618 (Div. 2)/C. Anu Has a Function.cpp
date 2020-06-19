#include <bits/stdc++.h>

using namespace std;

//begin: 22:45 Feb 09 Sunday
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, arr[1000010];

void process()
{
    sort(arr+1, arr+1+n, greater<ll>());
    ll l = 1, r = n, l_turn = 0, r_turn = 1;
    while (l <= r)
    {
        if (l == r)
        {
            cout << arr[l] << "\n";
            return;
        }
        l_turn = !l_turn;
        r_turn = !r_turn;
        if (l_turn)
        {
            cout << arr[l] << " ";
            l++;
        }
        if (r_turn)
        {
            cout << arr[r] << " ";
            r--;
        }
    }
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}