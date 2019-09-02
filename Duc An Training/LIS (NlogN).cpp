 #include <bits/stdc++.h>
#define int64 int64_t

//begin: 11.04am, end:

using namespace std;

int64 inf = numeric_limits<int64>::max() / 1000;
int64 n, ans;
vector<int64> A, endof;

void process() {
    endof.resize(1, -inf);

    for (int64 i = 0; i<n; i++) cout << A[i] << " "; cout << endl;

    for (int64 i = 0; i<n; i++) {
        int64 p = upper_bound(endof.begin(), endof.end(), A[i]) - endof.begin() - 1;
        if (p == endof.size() - 1) endof.push_back(0);

        endof[p+1] = A[i];

        cout << i << ": ";
        for (int64 j = 0; j<endof.size(); j++) cout << endof[j] << " "; cout << endl;
    }

    ans = endof.size() - 1;
    printf("%lld\n", ans);
}

void input() {
    freopen("LIS.INP", "r", stdin);
    scanf("%lld", &n); A.resize(n);
    for (int64 i = 0; i<n; i++) scanf("%lld", &A[i]);
}

int main()
{
    input();
    process();
    return 0;
}
