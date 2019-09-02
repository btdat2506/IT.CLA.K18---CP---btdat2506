#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)
int64_t n, k, dem = 0;
void sieve(bool isPrime[])
{
    //isPrime.push_back(0);
    //For(i, 1, n) isPrime.push_back(1); //memset
    For(i, 2, n)
    {
        if (isPrime[i])
        {
            dem++;
            isPrime[i] = 0;
            //cout << i << ' ' << dem << endl;
            if (dem == k) {cout << i << endl; break;}
            for(int64_t j = i * i; j <= n; j += i)
            {
                if (isPrime[j] == 1) dem++;
                isPrime[j] = 0;
                if (dem == k) {cout << j << endl; break;}
                //cout << j << ' ' << dem << endl;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    bool isPrime[n+10];
    memset(isPrime, 1, sizeof(isPrime));
    sieve(isPrime);
    //system("pause");
}

