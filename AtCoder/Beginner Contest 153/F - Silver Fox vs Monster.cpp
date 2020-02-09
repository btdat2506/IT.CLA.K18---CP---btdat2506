#include <bits/stdc++.h>

using namespace std;
struct TNode{
    long long Left, Right;
    long long lz;
};
TNode st[200 * 100000];
int cnt_node = 0;
//a[u] -> a[v] += val
int AddNode() {
    //st.push_back({0, 0, 0});
    return cnt_node++;
}
void update(int root, long long l, long long r, long long u, long long v, long long val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        st[root].lz += val;
        return;
    }
    long long mid = (l + r) >> 1;
    if (st[root].Left == 0) st[root].Left = AddNode();
    if (st[root].Right == 0) st[root].Right = AddNode();
    update(st[root].Left, l, mid, u, v, val);
    update(st[root].Right, mid + 1, r, u, v, val);
}
long long get(int root, long long l, long long r, long long pos) {
    if (l == r) return st[root].lz;
    long long mid = (l + r) >> 1;
    if (pos <= mid) {
        if (st[root].Left == 0) st[root].Left = AddNode();
        return get(st[root].Left, l, mid, pos) + st[root].lz;
    }
    if (st[root].Right == 0) st[root].Right = AddNode();
    return get(st[root].Right, mid + 1, r, pos) + st[root].lz;
}
const int maxn = 2e5 + 5;
pair<int, int> a[maxn];
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AddNode();
    int n;
    long long len, dmg;
    cin >> n >> len >> dmg;
    len *= 2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        long long pos = a[i].first;
        long long hp = get(0, 0, 3e9, pos) + a[i].second;
        if (hp <= 0) continue;
        long long t = hp / dmg + (hp % dmg != 0);
        update(0, 0, 3e9, pos, pos + len, -t * dmg);
        res += t;
    }
    cout << res;
    return 0;
}
