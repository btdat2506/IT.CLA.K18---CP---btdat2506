#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool ok1 = 1, ok2 = 0;
ll n, res, arr[1000010];
unordered_map <ll, ll> P;

void PrimeDefactorizeProcess(ll u)
{
    For(i, 2, sqrt(u) + 1)
    if (u > 1 && u % i == 0)
    {
        while (u % i == 0) u /= i;
        P[i]++;
    }
    if (u > 1) P[u]++;
}

void process()
{
    For(i, 1, n)
    PrimeDefactorizeProcess(arr[i]);
    for(unordered_map <ll, ll>::iterator iter = P.begin(); iter != P.end(); iter++)
        if (iter->second > 1) ok1 = 0;
    res = arr[1];
    For(i, 2, n)
    res = __gcd(res, arr[i]);
    if (res == 1) ok2 = 1;
    if (ok1)
        cout << "pairwise coprime" << "\n";
    else
        if (ok2)
            cout << "setwise coprime" << "\n";
        else
            cout << "not coprime" << "\n";
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

