#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <queue>
#include <bitset>
#include <stack>
#include <unordered_map>

using namespace std;

#define all(v) (v).begin(),(v).end()
#define SRT(v) sort(all(v))
#define rall(v) (v).rbegin(),(v).rend()
#define rSRT(v) sort(rall(v))
#define sz(a) int((a).size())
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define PB push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define EPS 1e-9
#define Mod (ll)1000000007
#define oo (int)1<<30
#define OO (ll)1ll<<60
#define PI 3.141592653589793
#define F first
#define S second
#define pw(x) (x)*1LL*(x)

typedef stringstream ss;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii>vii;
typedef pair<int, ll> il;
typedef vector<vector<ii>> vvii;
typedef vector<vector<il>> vvil;

//ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
//int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

//string alpha = "abcdefghijklmnopqrstuvwxyz";
//string vowels = "aeoui";
//string pm = "AHIMOTUVWXY";

//const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
//const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

string a, b, ans;
int dp[3005][3005];

int solve(int i, int j)
{
	if (i == a.size() || j == b.size()) return 0;
	if (~dp[i][j]) return dp[i][j];
	if (a[i] == b[j]) return dp[i][j] = solve(i + 1, j + 1) + 1;
	return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
}

void build(int i, int j)
{
	if (i == a.size() || j == b.size()) return;
	if (a[i] == b[j]) {
		ans += a[i];
		build(i + 1, j + 1);
	}
	else {
		if (solve(i, j) == solve(i + 1, j)) build(i + 1, j);
		else build(i, j + 1);
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> a >> b;
	mem(dp, -1);
	solve(0, 0);
	build(0, 0);
	cout << ans;
	//int wait; sc(wait);
}
