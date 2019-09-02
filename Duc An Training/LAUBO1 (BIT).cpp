#include <bits/stdc++.h>
#define int64 int64_t

//begin: 8.36am, end:

using namespace std;

int64 n, ans;
vector<int64> A;

bool getBit(int64 x, int64 y) { //lay bit thu y cua x
    return (x >> y) & 1;
}

bool check(int64 state) {
    for (int64 i = 0; i<n-1; i++)
    if (getBit(state, i) && getBit(state, i+1)) return false;

    return true;
}

void process() {
    ans = 0;

    for (int64 state = 0; state < (1 << n); state++)
    if (check(state)) {
        int64 tmp = 0;

        for (int64 i = 0; i<n; i++)
        if (getBit(state, i)) tmp += A[i];

        ans = max(ans, 2 * tmp);
    }

    printf("%lld\n", ans);
}

void input() {
    freopen("LAUBO1.INP", "r", stdin);
    scanf("%lld", &n); A.resize(n);
    for (int64 i = 0; i<n; i++) scanf("%lld", &A[i]);
}

int main()
{
    input();
    process();
    return 0;
}
