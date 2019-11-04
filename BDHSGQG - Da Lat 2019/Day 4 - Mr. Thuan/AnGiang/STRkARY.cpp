#include <bits/stdc++.h>

using namespace std;

const long long base = 31;

int n;
char s[400005];
long long p[400005], h[400005], hh[400005];
vector<int> res;

inline long long geth(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

inline long long gethh(int l, int r) {
    return hh[r] - hh[l - 1] * p[r - l + 1];
}

inline bool permu(int pos, int k) {
    long long ha = geth(pos, pos + k - 1);
    for (int i = 1; i <= k; i++)
        if (gethh(i, i + k - 1) == ha) return true;
    return false;
}

inline bool check(int k) {
    for (int i = 1; i <= k; i++) hh[i] = hh[i - 1] * base + s[i] - 'a' + 1;
    for (int i = 1; i <= k; i++) hh[k + i] = hh[k + i - 1] * base + s[i] - 'a' + 1;
    for (int i = k + 1; i <= n; i += k) if (!permu(i, k)) return false;
    return true;
}

int main() {
    //freopen("STRKARY.INP", "r", stdin);
    //freopen("STRKARY.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s + 1;
    n = strlen(s + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
    for (int i = 1; i <= n; i++) h[i] = h[i - 1] * base + s[i] - 'a' + 1;

    for (int k = 1; k <= n; k++)
        if (n % k == 0 && check(n / k)) res.push_back(k);

    cout << res.size() << "\n";
    for (int i:res) cout << i << " ";
}
