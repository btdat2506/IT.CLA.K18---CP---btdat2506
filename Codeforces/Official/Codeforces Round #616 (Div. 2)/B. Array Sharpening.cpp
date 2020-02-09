#include <bits/stdc++.h>

using namespace std;

//begin: 22:55 Feb 02 Sunday
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, unvalid_pos_from_left, unvalid_pos_from_right, arr[300010];

void process()
{
    unvalid_pos_from_left = unvalid_pos_from_right = 0;
    For(i, 1, n)
    if (arr[i] < i-1)
    {
        unvalid_pos_from_left = i;
        break;
    }
    Fod(i, n, 1)
    if (arr[i] < n-i)
    {
        unvalid_pos_from_right = i;
        break;
    }
    if (unvalid_pos_from_left - unvalid_pos_from_right > 1 ||
        unvalid_pos_from_right == 0 ||
        unvalid_pos_from_left  == 0)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n) cin >> arr[i];
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