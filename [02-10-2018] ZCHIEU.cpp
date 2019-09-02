#include <bits/stdc++.h>

using namespace std;

bool notOdd(int n)
{
    if (n % 2 == 0) return 1; else return 0;
}

bool isPrime(int n)
{
    if (n == 1) return 0;
    if (n < 4) return 1; else
    for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
    return 1;
}

int main()
{
    freopen("zchieu.inp", "r", stdin);
    int m, n;
    cin >> m >> n;
    int a[m][n];
    int Chan = 0, snt = 0;
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
        cin >> a[i][j];
        if (notOdd(a[i][j])) Chan++;
        if (isPrime(a[i][j])) snt++;
    }
    freopen("zchieu.out", "w", stdout);
    cout << Chan << " " << snt << endl;
    return 0;
}