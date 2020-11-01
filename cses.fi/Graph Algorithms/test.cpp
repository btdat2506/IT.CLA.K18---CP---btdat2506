#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<bool> visited;
vector<int> ans;
vector<vi> g(20);

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

vi topo_sort() {
    visited.assign(n+2, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >>b;
        g[a].push_back(b);
    }
    vi o=topo_sort(), dp(n+1), p(n+1);
    for(ll v: o) cout << v << ' '; cout << "\n";
    dp[1]=1;
    trav(i, o) trav(j, g[i])
    if (dp[i] && dp[i]+1>dp[j])
        dp[j]=dp[i]+1, p[j]=i;
    int d=dp[n];
    cout << dp[n] << "\n";
    if (!d) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << d << "\n";
    vi ans;
    for (int i=n; i; i=p[i])
        ans.push_back(i);
    rep(i, 0, d)
    cout  << ans[d-1-i] << " \n"[i==d-1];
    return 0;
}