#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)
 
 
const ll siz = 1000010,
         base = 31,
         MOD = 1000000003;
 
ll m, n, hashT[siz], hashP[siz], power[siz];
string T, P;
 
ll gethash(ll *hash, ll i, ll j)
{
	return hash[j] - hash[i-1] * power[j - i + 1];// + MOD * MOD) % MOD;
}
 
void precalc()
{
	T = ' ' + T;
	P = ' ' + P;
	For(i, 1, n)
	hashT[i] = (hashT[i-1] * base + (T[i] - 'a' + 1));//% MOD;
	For(i, 1, m)
	hashP[i] = (hashP[i-1] * base + (P[i] - 'a' + 1)); //% MOD;
	power[0] = 1;
	For(i, 1, max(n, m))
	power[i] = (power[i-1] * base); //% MOD;
}
 
void answer()
{
	ll l, r, u, v;
	cin >> l >> r >> u >> v;
	ll len = min(r-l+1, v-u+1);
    ll lo = 1, high = len;
    while (low <= high) 
    {
        ll k = (low + high) / 2;
        if (gethash(hashT, l, l+k-1) == gethash(hashP, u, u+k-1))
            low = k + 1;
        else
            high = k - 1;
    }
    if (high == len) 
    {
        if (r-l == v-u) cout << '=';
        else if (r-l < v-u) cout << '<';
        else cout << '>';
    } else
        cout << (T[l+high]<P[u+high]? '<':'>');
}
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	cin >> T >> P;
	precalc();
	ll q;
	cin >> q;
	For(i, 1, q) answer();
} 