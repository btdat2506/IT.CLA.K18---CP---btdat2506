#include <bits/stdc++.h>

using namespace std;

int n,k,I;
vector<int> res;

int memo[10001][10001];

int cal(int pos,int rem)
{
	if (pos > n)
		return 1;
	if (memo[pos][rem] != -1)
		return memo[pos][rem];
	int cur = 0;
	if (rem == I-1)
		cur = cal(pos+1,0);
	else
	{
		cur = min(1000000000,cur + cal(pos+1,0));
		cur = min(1000000000,cur + cal(pos+1,rem+1));
	}
	return memo[pos][rem] = cur;
}

bool ok = true;

void Try(int pos,int rem)
{
	//cerr << '!' << pos << ' ' << rem << ' ' << k << '\n';
	if (pos > n)
	{
		if (k != 1)
			ok = false;
		return;
	}
	if (rem == I-1)
	{
		res.push_back(1);
		Try(pos+1,0);
	}	
	else
	{
		if (cal(pos+1,rem+1) < k)
		{
			k -= cal(pos+1,rem+1);
			res.push_back(1);
			Try(pos+1,0);
		}
		else
		{
			res.push_back(0);
			Try(pos+1,rem+1);
		}	
	}		 	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> I;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=I-1;j++)
			memo[i][j] = -1;				
	Try(1,0);
	if (!ok)
	{
		cout << -1;
		return 0;
	}	
	for (int i=0;i<res.size();i++)
		cout << res[i] << ' ';
	return 0;
}