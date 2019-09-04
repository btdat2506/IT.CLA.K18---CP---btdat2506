#include <bits/stdc++.h>

using namespace std;

int TinhToan(int i, int j)
{
    if (i == 1 || j == 1) return 1;
    return TinhToan(i-1, j) + TinhToan(i, j-1);
}

int main()
{
    cin >> m >> n;

    return 0;
}
