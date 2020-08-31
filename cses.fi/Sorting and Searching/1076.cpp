#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll k, n, arr[200010];

void process()
{
    multiset <ll> sorted;
    For(i, 1, k-1)
        sorted.insert(arr[i]);
    ll pos = ((k % 2 == 0) ? k / 2 : (k + 1) / 2) - 1;
    For(i, k, n)
    {
        sorted.insert(arr[i]);
        multiset <ll>::iterator it = next(sorted.begin(), pos);
        cout << *it << " ";
        sorted.erase(sorted.find(arr[i-k+1]));
    }
}

void input()
{
    cin >> n >> k;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}