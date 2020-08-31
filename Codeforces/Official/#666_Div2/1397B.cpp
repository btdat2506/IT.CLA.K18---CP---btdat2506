#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

// begin: 22:30:28 Aug/30/2020
// end: 

ll n, case1, case2, tmp1, tmp2, res1, res2, arr[100010];

void process()
{
    sort(arr, arr+n);
    case1 = sqrt(arr[1]); tmp1 = case1; 
    case2 = (ll) (sqrt(arr[1]) + 1); tmp2 = case2;
    For(i, 1, n)
    {
        res1 += abs(arr[i] - tmp1);
        res2 += abs(arr[i] - tmp2);
        tmp1 *= case1;
        tmp2 *= case2;
    }
    cout << min(res1, res2) + (arr[0] - 1) << "\n";
}

void input()
{
    cin >> n;
    For(i, 0, n)
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