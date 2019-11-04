#include<bits/stdc++.h>
using namespace std;
const int N = 100050;
double a[N];
double b[N];
double f[N];
int n,k;
bool kt(double x)
{
    for(int i=1;i<=n;i++)
    {
        b[i] = b[i-1] + (a[i] - x);
        f[i] = min(f[i-1],b[i]);
    }
    for(int i=k;i<=n;i++)
    {
        if(b[i]>=f[i-k]) return true;
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> k;
    f[0] = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    double l = -100000,r = 100000, mid = (l+r)/ 2;
    for(int i=1;i<=200;i++)
    {
        mid = (l+r)/ 2;
        if(kt(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(5) << fixed << mid ;
}
