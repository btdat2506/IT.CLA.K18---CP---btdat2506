#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define sz(a) int((a).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(), _e = (c).end(); it != _e; ++it)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define repd(i,n) for(int i = (n)-1; i >= 0; --i )
#define fo(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define fod(i,a,b) for(int i = (a), _b = (b); i >= _b; --i)
 
#define INF 1000000000
#define N 205
 
bool check[N][N], cant[N][N];
int p, q, s, t, n, m; //(p,q): diem dau, (s,t): diem cuoi
queue<ii> qu;
 
void process(int i, int j) {
	if(check[i][j]==0) {
	check[i][j] = 1;
	qu.push(ii(i,j));
	}
}
 
void printQueue(queue<ii> qu) {
	for(;!qu.empty(); printf( "(%d;%d) ", qu.front().fi, qu.front().se ), qu.pop() );
	putchar(10);
}
 
int main() {
	freopen( "test.in", "r", stdin );
	freopen( "test.ok", "w", stdout );
	scanf( "%d%d%d%d%d%d", &n, &m, &p, &q, &s, &t );
	rep(i, m) {
		int u, v; scanf( "%d%d", &u, &v );
		cant[u][v] = 1;
	}
	qu.push(ii(p, q)); check[p][q] = 1;
	for( int step = 0; !qu.empty(); ++step ) {
		printQueue(qu);
		rep(k, qu.size()) {
			int u = qu.front().fi, v = qu.front().se; qu.pop();
			if( u == s && v == t ) {
				printf( "%d\n", step );
				return 0;
			}
			for(int i=u-1, j=v-1; cant[i][j]==0&&i>0&&j>0; --i,--j)
				process(i,j);
			for(int i=u+1, j=v+1; cant[i][j]==0&&i<=n&&j<=n; ++i,++j)
				process(i,j);
			for(int i=u+1, j=v-1; cant[i][j]==0&&i<=n&&j>0; ++i,--j)
				process(i,j);
			for(int i=u-1, j=v+1; cant[i][j]==0&&i>0&&j<=n; --i,++j)
				process(i,j);
		}
	}
	printf( "-1\n" );
	return 0;
}