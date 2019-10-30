#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, db[10000];

void process1() //n^2*logn
{
	
}

void input()
{
	cin >> n >> m;
	For(i, 1, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process1();
}