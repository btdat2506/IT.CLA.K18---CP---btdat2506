#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int64_t i = a; i <= b; i++)

int64_t m, n;

vector <vector<int64_t>> database;

int main()
{
    cin >> m >> n;
    database.resize(m+10);
    For(i, 1, m)
    {
        database[i].resize(n+10);
        For(j, 1, n)
        cin >> database[i][j];
    }
}