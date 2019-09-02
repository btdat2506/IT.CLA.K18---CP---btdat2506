#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define FOD(i,r,l) for (int64_t i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, a ,b) for(ull i = a; i <= b; i++)

bool isPrime[100010];
ull t, a, b;

void sieve(ull l, ull r)
{
    fillchar(isPrime, 1);
    For(i, 2, sqrt(r))
    for (ull j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) isPrime[j - l] = 0;
    For(i, max(l, (ull) 2), r) if (isPrime[i-l]) cout << i << endl; cout << endl;
}

int main()
{
    faster
    cin >> t;
    For(i, 1, t)
    {
        cin >> a >> b;
        sieve(a, b);
    }
}