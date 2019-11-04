#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int comb[10001][10001];

int cal(int n,int k)
{
	if (k > n)
		return 0;
	if (n == 0 || k == 0)
		return 1;
	if (comb[n][k])
		return comb[n][k];
	int cur = 0;
	cur = min(1000000000 + 1,cur + cal(n-1,k-1));
	cur = min(1000000000 + 1,cur + cal(n-1,k));
	return comb[n][k] = cur;
}

vector<int> res;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	int cur = 1;
	for (int i=1;i<=n;i++)
	{
		if (!m)
			break;
		if (cal(n-i,m-1) < k)
			k -= cal(n-i,m-1);	
		else
		{
			m--;
			res.push_back(i);
		}				
	}
	if (res.size() < m)
	{
		cout << -1;
		return 0;
	}	
	for (int i=0;i<res.size();i++)
		cout << res[i] << ' ';	
}