#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans, a[2000], L[2000], R[2000];
stack <ll> st;

void process()
{
    sort(a+1, a+1+n);
    a[0] = a[n+1] = INT64_MIN;
    st.push(0);
    For(i, 1, n)
    {
    	while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        st.push(i);
        L[i] = (st.empty()) ? 1 : st.top() + 1;
    }
    while (!st.empty()) st.pop();
    st.push(n+1);
    Fod(i, n, 1)
    {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        st.push(i);
        R[i] = (st.empty()) ? n : st.top() - 1;
    }
    For(i, 1, n)
    ans = max(ans, min(R[i] - L[i] + 1, a[i]));
    cout << ans << "\n";
}

void process1()
{
    sort(a+1, a+1+n, greater<int>());
    For(i, 1, n)
    if (a[i] <= i)
    ans = max(ans, a[i]);
    cout << ans << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> a[i];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        ans = 1;
        input();
        process();
    }    
}