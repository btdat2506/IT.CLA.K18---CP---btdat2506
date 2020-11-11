#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)

ll n, iz0 = 0, z0;
vector <ii> p; 

void process()
{
	vector <ii> a(n);
	f0(i, n)
	{
		a[i].first = p[i].second - z0.second;
		a[i].second = p[i].first - z0.first;
		if (a[i].first == 0)
		a[i].second = (a[i].second < 0) ? -1 : 1; //trường hợp điểm nằm trên trục oy
	}
	//xử lí truy vấn
	cin >> x >> y;
	ii q = {x, y};
	bool in = false;
	if (q == z0) in = true;
	else
	{
		//tịnh tiến và tính góc
		ii mq = {y = z2.second, x = z0.first};
		if (mq.first == 0) mq.second = (mq.second < 0) ? -1 : 1;
		//tìm kiếm nhị phân
		auto it = upper_bound(a.begin(), a.end(), mq, 
		[&](ii a, ii b) {return (a.first*be.second <= a.second*b.first);});
		//xác định p1
		if (it == a.end() && mq==a[n-1]) it = a.end() - 1;
		if (it != a.end() && it != a.begin())
		{
			ll pl = int(it - a.begin());
			in = area(p[p1], p[p1-1], q) <= 0; //kiểm tra điểm trong
		}
	}
	cout << ((in) ? "Inside\n" : "Outside\n");
}

void input()
{
	cin >> n;
	p.resize(n);
	f0(i, n)
	{
		cin >> p[i].first >> p[i].second;
		if (p[i] < p[iz0]) iz0 = i; //tìm vị trí z0
	}
	z0 = p[iz0];
	rotate(p.begin(), p.begin()+iz0, p.end()); //đẩy vòng tròn, đưa z0 về đầu
	p.erase(p.begin()); --n; //z0 không tham gia tính góc
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	input();
	process();
}