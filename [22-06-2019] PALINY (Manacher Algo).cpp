#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000003 //10^9 + 3
#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

const ll base = 31;

ll n, P[1000000];
string st;

void ManacherAlgo() //https://leetcode.com/problems/longest-palindromic-substring/discuss/2967/22-line-c-manacheru2019s-algorithm-on-solution
{
	string T = "";
	For(i, 0, n)
	T += '#' + st.substr(i, 1);
	T += '#';
	For(i, 0, T.length()) cout << T[i]; cout << endl;
	ll center = 0,
	   boundary = 0,
	   maxlen = 0,
	   resCenter = 0;
	For(i, 1, T.size()-1)
	{
		ll imirror = 2 * center - i;
		if (boundary > i) P[i] = min(boundary-i, P[imirror]); else P[i] = 0;
		while (i - 1 - P[i] >= 0 &&
		       i + 1 + P[i] <= T.size()-1 && T[i+1+P[i]] == T[i-1-P[i]])
			P[i]++;
		if (i + P[i] > boundary)
			center = i,
			boundary = i + P[i];
		if (P[i] > maxlen)
			maxlen = P[i],
			resCenter = i;
	}
	cout << st.substr((resCenter - maxlen) / 2, maxlen) << endl;
	cout << maxlen << endl;
} 

void input()
{
	cin >> n;
	cin >> st;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	ManacherAlgo();
}