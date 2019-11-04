#include <bits/stdc++.h>

using namespace std;

long long a, b;
vector<int> res;

int main() {
    //freopen("PLUS.INP", "r", stdin);
    //freopen("PLUS.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    while (a != b) {
        if (a % 2 == 1 && b % 2 == 1) {
            if (a < b) {
                b += a; res.push_back(3);
                a += a; res.push_back(1);
            } else {
                a += b; res.push_back(2);
                b += b; res.push_back(4); }
        } else if (a % 2 == 1) {
            a += a;
            res.push_back(1);
        } else if (b % 2 == 1) {
            b += b;
            res.push_back(4);
        }

        long long d = __gcd(a, b);
        a /= d; b /= d;
    }

    cout << res.size() << "\n";
    for (int i:res)
        if (i == 1) cout << "A+=A\n";
        else if (i == 2) cout << "A+=B\n";
        else if (i == 3) cout << "B+=A\n";
        else if (i == 4) cout << "B+=B\n";
}

