#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

const ll N = 10000010;
ll q, Prime[N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(ll i = 2; i < N; i++)
        if (!Prime[i])
            for(ll j = i; j < N; j += i)
                Prime[j]++;

    cin >> q;
    for(ll j = 1; j <= q; j++)
    {
        ll a, b, dem = 0, k; cin >> a >> b >> k;
        for(ll i = a; i <= b; i++) if (Prime[i] == k) dem++;
        cout << "Case #" << j << ": " << dem << endl;
    }

    return 0;
}