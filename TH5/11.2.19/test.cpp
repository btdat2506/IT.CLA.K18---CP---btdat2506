#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)
vector <int64_t> isPrime;

void sieve(int64_t n)
{
    isPrime.push_back(0);
    For(i, 1, n) isPrime.push_back(1); 
    For(i, 2, n)
    if (isPrime[i])
    for(int64_t j = i * i; j <= n; j += i) isPrime[j] = 0;
}

int main()
{
    freopen("output.txt", "w", stdout);
    sieve(10000000);
    For(i, 1, 10000000) cout << isPrime[i] << ", ";
}