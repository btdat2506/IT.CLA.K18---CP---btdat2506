#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define BASE 10
#define For(i, a, b) for(ll i = a; i <= b; i++)

class big {
public :
	ll n, a[100010];
    void resize(int N)
    {
    	For(i, n, N)
    	a[i] = 0;
    	n = N;
    }
    void fix()
    { 
    	For(i, 1, n)
    	{
    		a[i+1] += (a[i]/BASE);
    		a[i] = a[i]%BASE;
    	}
    }
    void trim()
    {
    	while (n > 1 && a[n-1] == 0) n--;
    }
    void operator *= (int x)
    {
    	resize(n+4);
    	For(i, 1, n) a[i] *= x;
    	fix(); trim();
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll x = 0;
	while (cin >> x)
	{
		ll n;
		big pros, ans;
		cin >> n;
		pros.n = n;
		For(i, 1, n) 
		pros.a[i] = 1;
		pros *= pros;
	}
}