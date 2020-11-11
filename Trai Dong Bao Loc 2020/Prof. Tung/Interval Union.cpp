#include <bits/stdc++.h>
#define NAME "merge_seg."
using namespace std;
typedef pair<int, bool> pib;
ifstream fi(NAME"INP");
ofstream fo(NAME"OUT");
int n, a, b, c = 1, ans = 0;

int main()
{
	fi >> n;
	vector<pib> x(2*n);
	for(int i = 0; i < n; ++i)
	{
		fi >> a >> b;
		x[2*i] = {a, 0};
		x[2*i+1] = {b, 1};
	}
	sort(x.begin(), x.end());
	for(int i = 1; i < 2*n; i++)
	{
		if (c) 
			ans += x[i].first - x[i-1].first;
		if (x[i].second) --c; else ++ c; //đến điểm cuối
	}
	fo << ans;
	fo << "\nTime: " << clock()/(double)1000 << " sec";
}