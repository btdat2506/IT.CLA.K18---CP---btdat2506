#include <bits/stdc++.h>
using namespace std;
#define For(i, a ,b) for(int64_t i = a; i <= b; i++)
#define FOD(i,r,l) for (int64_t i=r;i>=l;i--)
#define ll int64_t
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define EL cout << endl;
#define sz(A) (int) A.size()
#define fillchar(a,x) memset(a, x, sizeof (a))
#define read(a) cin >> a
#define writeln(a) cout << a << endl
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef unsigned long long ull;
#define For(i, a ,b) for(ull i = a; i <= b; i++)

bool isPrime[10000001];
vector <ull> prime;
ull t, a, b, n, k, sz;

void sieve()
{
    ull N = 10000000;
    fillchar(isPrime, 1);
    For(i, 2, sqrt(N))
    if (isPrime[i])
    for(ull j = i * i; j < N; j += i) isPrime[j] = 0;
    For(i, 2, N-1) if (isPrime[i]) prime.push_back(i);
    sz = prime.size();
}

void process()
{
    ull ans = 0;
    For(i, 0, sz-k)
    {
        ull temp = 1;
        For(j, i, i+k-1) temp *= prime[j];
        if (temp > n) break; else ans = max(temp, ans);
    }
    if (ans != 0) writeln(ans); else writeln(-1);
}

int main()
{
    sieve();
    cin >> t;
    For(i, 1, t)
    {
        cin >> n >> k;
        process();
    }
}