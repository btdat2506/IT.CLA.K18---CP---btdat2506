#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, l, r, res, a[100010];

long double ternary_search() {
    long double eps = 1e-9; 
    long double l1 = l, r1 = r;              //set the error limit here
    while (r1 - l1 > 1) {
        long double m1 = l1 + (r1 - l1) / 3;
        long double m2 = r1 - (r1 - l1) / 3;
        long double f1 = *lower_bound(a+1, a+1+n, -m1);      //evaluates the function at m1
        long double f2 = *lower_bound(a+1, a+1+n, -m2);      //evaluates the function at m2
        if (f1+m1 > f2+m2)
            l1 = m1;
        else
            r1 = m2;
    }
    return l1;                    //return the maximum of f(x) in [l, r]
}

void process()
{
    sort(a+1, a+1+n);
    /*ll mid = (l + r) / 2;
    while (l != mid && r != mid)
    {
        ll tmp = lower_bound(a+1, a+1+n, -mid) - a,
            tmp1 = lower_bound(a+1, a+1+n, -((l + mid)/2) - a, //(l + (l + r)/2 ) / 2
            tmp2 = lower_bound(a+1, a+1+n, -((mid + r)/2) - a;
        if (tmp2 > tmp1)
        {
            if (tmp2 > tmp)
            {
                l = mid;
            }
            if (tmp > tmp2)

        }
        
        mid = (l + r) / 2;
    } */
    cout << ternary_search() << "\n";
}

void input()
{
    cin >> n >> l >> r;
    For(i, 1, n)
    cin >> a[i];
}

int main()
{
    freopen("MAXDIS.INP", "r", stdin);
    freopen("MAXDIS.OUT", "w", stdout);
    input();
    process();
}