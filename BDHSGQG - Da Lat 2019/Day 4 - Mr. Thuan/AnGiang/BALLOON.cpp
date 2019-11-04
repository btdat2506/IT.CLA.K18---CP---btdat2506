#include <bits/stdc++.h>

using namespace std;

string s;
int t, n, col[202], g[5][201][201][201];

int cal(int c, int d, int l, int r) {
    if (l == r) {
        if (d == 1) return -1000000009;
        return d * d;
    }

    if (g[c][d][l][r] != -1) return g[c][d][l][r];

	if (col[s[l]] == c) {
		if (l == r - 1) return (d + 1) * (d + 1);
		return g[c][d][l][r] = cal(c, d + 1, l + 1, r);
	} else {
		int cur = -1000000009;
		for (int k = l + 2; k <= r; k++)
			cur	= max(cur, cal(col[s[l]], 1, l + 1, k) + cal(c, d, k, r));
		return g[c][d][l][r] = cur;
	}
}

int main() {
    //freopen("BALLOON.INP", "r", stdin);
    //freopen("BALLOON.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    col['R'] = 1; col['B'] = 2; col['G'] = 3; col['Y'] = 4;

    cin >> t;
    while (t--) {
        cin >> s; n = s.size();

        for (int c = 1; c <= 4; c++)
            for (int d = 0; d <= n; d++)
                for (int l = 0; l <= n; l++)
                    for (int r = 0; r <= n; r++) g[c][d][l][r] = -1;

        cout << max(0, cal(col[s[0]], 1, 1, n)) << "\n";
    }
}
