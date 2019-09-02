#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

string st, T;
ll P[1000100], pos[1000100];

void process()
{
	memset(P, 0, sizeof(P));
	memset(pos, 0, sizeof(pos));
	T = "";
	For(i, 0, st.length())
	T += '#' + st.substr(i, 1);
	T += '#';
	ll c = 0, r = 0, maxlen = 0, rescenter = 0;
	For(i, 1, T.size()-1)
	{
		ll imirror = 2 * c - i;
		if (r > i)
			P[i] = min(r-i, P[imirror]);
		else P[i] = 0;
		while (i - 1 - P[i] >= 0 && i + 1 + P[i] <= T.size()-1 &&
			   T[i-1-P[i]] == T[i+1+P[i]])
			P[i]++;
		if (i + P[i] > r)
			c = i,
			r = i + P[i];
		pos[i] = i;
		if (P[i] > maxlen)
			maxlen = P[i],
			rescenter = i;
	}
	ll fi = -1;
	For(i, 1, T.size()-1)
	if (((pos[i] - P[i])/2 + P[i]) == st.length())
	{
		fi = i;
		break;
	}
	Fod(i, (pos[fi] - P[fi])/2-1, 0)
	st += st.substr(i, 1);
	cout << st << endl;

}

void readfile()
{
	ifstream inp("input.txt");
	freopen("output.txt", "w", stdout);
	while (!inp.eof())
	{
		inp >> st;
		process();
	}
}

void readkeyboard()
{
	while (cin >> st)
	process();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//readfile();
	readkeyboard();
}