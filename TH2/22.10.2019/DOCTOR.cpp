#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x, db[200];

void process()
{
	For(i, 1, n)
	For(j, 1, m)
	{
		weight[i][j] = weight[i-1][j];
		if (inp_weight[i] <= j)
			weight[i][j] = min(weight[i][j], weight[i-1][j - inp_weight[i]] + value[i]); 
	}
}

void input()
{
	cin >> n >> x;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("DOCTOR.INP", "r", stdin);
	freopen("DOCTOR.OUT", "w", stdout);
	input();
	process();
}