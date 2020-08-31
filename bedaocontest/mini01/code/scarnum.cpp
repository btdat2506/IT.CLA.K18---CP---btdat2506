#include <bits/stdc++.h>
#define ll long long
#define pb push_back
//#define upto(i, a, b) for(int i=(a), _b=(b); i<=_b; ++i)

using namespace std;
const int inf = (int) 1e6;

bool isok[inf + 7];

vector <int> num;

int T, n;

void getscarnum(){

    for(int x = 0; x < (int)num.size(); ++x)
        for(int i = 1; i <= inf/num[x]; ++i)
          isok[i*num[x]] = 1;

}

int main()
{
    //freopen("t.inp", "r", stdin);
    freopen("scarnum.inp", "r", stdin);
    freopen("scarnum.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    num.pb(2); num.pb(5);

    int pos(0), s;

    while(pos < (int) num.size()){

        s = num[pos]*10 + 2;

        if(s <= inf) num.pb(s);

        s = num[pos]*10 + 5;

        if(s <= inf) num.pb(s);

        ++pos;

    }

    getscarnum();

    cin>>T;

    while(T--){

        cin>>n;

        if(isok[n]) cout<<"YES"<<'\n';

        else cout<<"NO"<<'\n';

    }


    return 0;
}
