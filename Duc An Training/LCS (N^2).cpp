#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll m, n, arr1[1010], arr2[1010], lcs[1010][1010];

void process()
{
	For(i, 1, m)
	For(j, 1, n)
	{
		if (arr1[i] == arr2[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
		else
		lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	}
	cout << lcs[m][n] << endl;
}

void process_sqr()
{
	For(i, 1, m)
	For(j, 1, n)
	if (arr1[i] != arr2[j]) lcs[i][j] = 0; else
	//Fod(i, m, 1)
	//Fod(j, n, 1)
	For(i1, 0, i-1)
	For(j1, 0, j-1) 
	if (arr1[i1] == arr2[j1])
		lcs[i][j] = max(lcs[i][j], lcs[i1][j1] + 1); 
	cout << lcs[m][n] << endl;
}

void input()
{
	cin >> m >> n;
	For(i, 1, m) cin >> arr1[i];
	For(i, 1, n) cin >> arr2[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process_sqr();
}