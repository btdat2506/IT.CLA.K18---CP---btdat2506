#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)
vector <bool> isPrime;
int64_t t, a, b, k;

void sieve()
{
    int64_t n = 10000000;
    isPrime.push_back(0);
    isPrime.push_back(0);
    For(i, 2, n) isPrime.push_back(1); 
    For(i, 2, n)
    if (isPrime[i])
    for(int64_t j = i * i; j <= n; j += i) isPrime[j] = 0;
}

int64_t xuli(int64_t n)
{
    int64_t dem = 0;
    if (isPrime[n]) return 1; //cout << n << ": ";
    unordered_map<int64_t, bool> check;
    For(i, 2, ceil(sqrt(n))) 
    {
    	if (n % i == 0 && isPrime[i] && !check[i]) 
    	{
    		dem++;
            check[i] = 1;
    		if (n/i != i && n % (n / i) == 0 && isPrime[n/i] && !check[n/i]) {dem++; check[n/i] = 1;}
    		//cout << i << ' ' << n/i << ' ';
    	}
    }//cout << endl;
    return dem;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    cin >> t;
    For(i, 1, t)
    {
        int64_t dem = 0;
        cin >> a >> b >> k;
        For(j, a, b)
        {
            bool kt = 0; 
            if (xuli(j) == k) dem++;
        }
        cout << "Case #" << i << ": " << dem << endl;
    }
    return 0;
}
