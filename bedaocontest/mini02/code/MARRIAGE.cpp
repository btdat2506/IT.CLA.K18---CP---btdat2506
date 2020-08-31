#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("marriage.inp", "r", stdin);
  freopen("marriage.out", "w", stdout);

  int A, B, M; cin >> A >> B >> M;

  vector<bool> deg(A + B);
  while(M--) {
    int x, y; cin >> x >> y;
    deg[--x] = 1; deg[--y + A] = 1;
  }

  for(int i = 0; i < deg.size(); ++i) cout << (deg[i] ? "Yes" : "No") << "\n";

  return 0;
}
