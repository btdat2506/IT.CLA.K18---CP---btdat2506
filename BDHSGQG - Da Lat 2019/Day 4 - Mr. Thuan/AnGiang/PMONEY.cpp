#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ii;

int n;
long long rma, rmi, pre[1000006];
char s[1000006], ss[1000006];

int main() {
    //freopen("PMONEY.INP", "r", stdin);
    //freopen("PMONEY.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s + 1;
    n = strlen(s + 1);

    ///MAX
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+' || s[i] == '_') pre[i] = pre[i - 1] + 1;
        else if (s[i] == '-') pre[i] = pre[i - 1] - 1; else pre[i] = pre[i - 1];

        if (pre[i] < 0) {
            cout << "NIE";
            return 0;
        }
    }

    long long cnt = pre[n];
    for (int i = 1; i <= n; i++) ss[i] = s[i];
    for (int i = n; i > 0; i--) if (s[i] == '_') {
        if (cnt >= 2) {
            ss[i] = '-';
            cnt -= 2;
        } else if (cnt == 1) {
            ss[i] = '0';
            cnt -= 1;
        } else ss[i] = '+';
    }

    rma = 0; cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ss[i] == '+') cnt++;
        else if (ss[i] == '-') cnt--;

        if (cnt < 0) {
            cout << "NIE";
            return 0;
        }

        rma += cnt;
    }

    if (cnt != 0) {
        cout << "NIE";
        return 0;
    }

    ///MIN
    for (int i = 1; i <= n; i++)
        if (s[i] == '-' || s[i] == '_') pre[i] = pre[i - 1] - 1;
        else if (s[i] == '+') pre[i] = pre[i - 1] + 1; else pre[i] = pre[i - 1];

    for (int i = 1; i <= n; i++) ss[i] = s[i];

    stack<ii> st; cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '_') {
            ss[i] = '-';
            st.push(ii(i, 2));
        }

        while (pre[i] + cnt < 0) {
            int pos = st.top().ff, val = st.top().ss; st.pop();

            if (pre[i] + cnt + val > 0) {
                st.push(ii(pos, 1));
                cnt++; ss[pos] = '0';
            } else {
                ss[pos] = '+';
                cnt += val;
            }
        }
    }

    rmi = 0; cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ss[i] == '+') cnt++;
        else if (ss[i] == '-') cnt--;
        rmi += cnt;
    }

    cout << rmi << " " << rma;
}
