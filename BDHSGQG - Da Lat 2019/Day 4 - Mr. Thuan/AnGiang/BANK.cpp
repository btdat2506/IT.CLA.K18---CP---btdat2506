#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int n,T,f[maxn],maxx=0;
struct edge
{
    int x,t;
};
bool cmp (edge a1, edge a2)
{
     return  a1.x>a2.x;
}
vector <edge> a;
int main()
{
   //freopen("bank.inp","r",stdin);
   // freopen("bank.out","w",stdout);
    cin>>n>>T;
    for (int x,t,i=1;i<=n;++i)
    {
        cin>>x>>t;
       a.push_back({x,t});

    }
   // a.push_back({})
    sort(a.begin(),a.end(),cmp);
    for (int i=1;i<=n;++i)
    {

        while (f[a[i-1].t]>0 && a[i-1].t>=0) a[i-1].t--;
        if (a[i-1].t>=0) f[a[i-1].t]=a[i-1].x;
    }
    for (int i=0;i<=T;++i)
        maxx+=f[i];
    cout<<maxx;

}
