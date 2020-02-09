#include <bits/stdc++.h>

using namespace std;

//begin: 21:02 Feb 08 Saturday
//end: 21:30 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, tmp;
bool isPrime[1000010];

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    For(i, 2, 1000)
    if (isPrime[i])
    for(ll j = i*i; j <= 1000000; j += i)
    isPrime[j] = 0;
}

void process()
{
    tmp = sqrt(n);
    if (tmp*tmp == n && isPrime[tmp])
    {
        cout << 1 << "\n";
    }
    else
        cout << 0 << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("THREE.INP", "r", stdin);
    freopen("THREE.OUT", "w", stdout);
    sieve();
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }
}