#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long

/// 1 = A += A
/// 2 = B += B
/// 3 = A += B
/// 4 = B += A
int A , B;
vector < int > ans;

void solve(int A , int B)
{
    if(A != B)
    {
        if(A % 2 == 0 && B % 2 == 0)
        {
            int x = __gcd(A , B);
            A /= x;
            B /= x;
            solve(A , B);
        }
        else if(A % 2 == 1 && B % 2 == 0)
        {
            ans.pb(1);
            solve(A * 2 , B);
        }
        else if(A % 2 == 0 && B % 2 == 1)
        {
            ans.pb(2);
            solve(A , B * 2);
        }
        else if(A % 2 == 1 && B % 2 == 1)
        {
            if(A <= B)
            {
                ans.pb(4);
                ans.pb(1);
                solve(A + A , B + A);
            }
            else
            {
                ans.pb(3);
                ans.pb(2);
                solve(A + B , B + B);
            }
        }
    }
}

main()
{
    //freopen("PLUS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    solve(A , B);
    cout << ans.size() << "\n";
    REP(s , ans.size())
    {
        if(ans[s] == 1)
            cout << "A+=A" << "\n";
        else if(ans[s] == 2)
            cout << "B+=B" << "\n";
        else if(ans[s] == 3)
            cout << "A+=B" << "\n";
        else
            cout << "B+=A" << "\n";
    }
}
