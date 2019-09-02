#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

struct dt
{
	ll non_rev, rev;
};

dt db[100010];
ll n, ans = 0, temp[100010], bit[100010];

bool cmp (const ll &L, const ll &R)
{
	return L < R;
}

bool cmp1(const dt &L, const dt &R)
{
	return L.non_rev < R.non_rev;
}

void hashstr(ll idx, string st)
{
	ll leng = st.length();
	string rev_st = st;
	reverse(rev_st.begin(), rev_st.end());
	rev_st = ' ' + rev_st;
	st = ' ' + st;
	For(i, 1, leng)
	db[idx].non_rev = db[idx].non_rev * 27 + (st[i] - 'a' + 1),
	db[idx].rev = db[idx].rev * 27 + (rev_st[i] - 'a' + 1);
	For(i, leng, 10)
	db[idx].non_rev *= 27,
	db[idx].rev *= 27;
}

void compress()
{
	For(i, 1, n) temp[i] = db[i].non_rev;
	sort(temp+1, temp+1+n, cmp);
	For(i, 1, n)
	db[i].non_rev = lower_bound(temp+1, temp+1+n, db[i].non_rev) - (temp+1) + 1;
	For(i, 1, n) temp[i] = db[i].rev;
	sort(temp+1, temp+1+n, cmp);
	For(i, 1, n)
	db[i].rev = lower_bound(temp+1, temp+1+n, db[i].rev) - (temp+1) + 1;
}

ll getsum(ll idx)
{
	ll sum = 0;
	while (idx > 0) //*** chỗ này là ">= 0", không phải là "> 0"
		sum += bit[idx],
		idx = (idx & (idx + 1)) - 1; //equals to idx -= idx & (-idx)
	return sum;
}

void update(ll idx)
{
	while (idx <= n)
		bit[idx]++,
		idx = idx | (idx + 1); // equals to idx += idx & (-idx)
}

void process()
{
	sort(db+1, db+1+n, cmp1);
	compress();
	Fod(i, n, 1)
	{
		ans += getsum(db[i].rev);
		update(db[i].rev); //dcm cái chỗ này không phải là i mà là db[i+1].rev làm phải fix bug 1 ngày 1 đêm
	}
	cout << ans;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		string st;
		cin >> st;
		hashstr(i, st);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input();
	process();
}