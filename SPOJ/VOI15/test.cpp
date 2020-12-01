#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i < b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

struct dt
{
	ll n, c, s;
	vector <ii> pt;
	bool operator < (const dt &T)
	{
		return s < T.s;
	}
};

/*
Bug từ bài này:
- kiểm tra các biến có đúng nhiệm vụ, đúng vị trí không
- hàm có return đúng biến cần return không, và các vòng for chạy có chuẩn không
- Khi chia, dùng double(res)/double(2) sẽ đảm bảo không thể sai

 */

ll m, k, max_c, res;
vector <dt> db;

ll get_res(ll u)
{
	ll sum = 0, t = 0;
	vector <int> f (m+10);
	f[0] = (db[0].c != u);
	for(ll i = 1; i < m; i++)
	f[i] = f[i-1] + (db[i].c != u);
	//For(i, 0, m) cout << (db[i].c != u) << ' '; cout << "\n";
	for(ll l = 0, r = m; l < m; l++)
	{
		sum = 0;
		r = m;
		while (r >= m || f[r] - f[l - 1] > k) r--; //bug
		//cout << l << ' ' << r << '\n';
		for(ll t1 = l; t1 <= r; t1++)
		sum += db[t1].s;
		t = max(t, sum);
		//cout << sum << ' ' << t << "\n";
	}
	_CrtDumpMemoryLeaks();
	return t;
}

void process()
{
	for(dt &T: db)
	{
		T.s = 0;
		T.pt.push_back(T.pt[0]);
		f0(i, T.pt.size()-1)
		T.s += (T.pt[i].x-T.pt[i+1].x) * (T.pt[i].y+T.pt[i+1].y);
		T.pt.pop_back();
	}
	sort(db.begin(), db.end());
	Fod(i, m-1, 1) //tràn mảng ngu học
	db[i].s -= db[i-1].s;
	//f0(i, m) cout << db[i].s << ' '; cout << "\n";
	for(ll i = 1; i <= max_c; i++)
	{
		res = max(res, get_res(i));
	}
	long double ans = res/2;
	cout << (res >> 1) << ((res % 2 == 0) ? ".0" : ".5") << "\n";
	_CrtDumpMemoryLeaks();
}

void input()
{
	cin >> m >> k;
	db.resize(m);
	f0(i, m)
	{
		cin >> db[i].n >> db[i].c;
		max_c = max(max_c, db[i].c);
		db[i].pt.resize(db[i].n);
		f0(j, db[i].n)
		cin >> db[i].pt[j].x >> db[i].pt[j].y;
	}
	_CrtDumpMemoryLeaks();
}

int main()
{
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}
