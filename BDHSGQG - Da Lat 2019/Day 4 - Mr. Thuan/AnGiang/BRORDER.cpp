#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int q, n;
char s[1000006];
long long f[2000006];

long long pow(long long a, long long n) {
    long long res = 1, t = a;
    while (n) {
        if (n & 1) res = res * t % mod;
        t = t * t % mod; n >>= 1;
    }
    return res;
}

long long C(int n, int k) {
    return f[n] * pow(f[k] * f[n - k] % mod, mod - 2) % mod;
}

long long cal(int x, int y) {
    int n = (x + y) >> 1, k = (x - y) >> 1;
    if (k == 0) return 1;
    return (f[n + k] * (n - k + 1) % mod) * pow(f[k] * f[n + 1] % mod, mod - 2);
}

int main() {
    //freopen("BRORDER.INP", "r", stdin);
    //freopen("BRORDER.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    f[0] = 1;
    for (int i = 1; i <= 2000000; i++) f[i] = f[i - 1] * i % mod;

    cin >> q;
    while (q--) {
        cin >> s + 1;
        n = strlen(s + 1);

        int cur = 0, precur = 0, res = 1;
        for (int i = 1, j = n - 1; i <= n; i++, j--) {
            if (s[i] == '(') cur++; else cur--;
            if (cur > precur && cur > 1) res = (res + cal(j, cur - 2)) % mod;
            precur = cur;
        }

        cout << (((cal(n, 0) - res + 1) % mod + mod) % mod) << "\n";
    }
}

