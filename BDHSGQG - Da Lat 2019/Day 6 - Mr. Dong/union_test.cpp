# include <bits/stdc++.h>
using namespace std;
queue <unsigned long long> qq;
unsigned long long kq,dem,n,k,tg,v[300001];
void doc()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("UNION.INP","r",stdin);
    freopen("UNION.OUT","w",stdout);
    v[0]=0;
    cin>>n;
    for (long i=1;i<=n;i++) cin>>v[i];
}
void xuly1()
{
    k=qq.front();
    qq.pop();
    while (qq.front() == k) qq.pop();
    while (v[dem]==k) dem--;
    if (!qq.empty())
    {tg=k/2;
    qq.push(tg);
    kq++;}
}
void xuly2()
{
    k=v[dem];
    dem--;
    while (v[dem]==k) dem--;
    k/=2;
    qq.push(k);
    kq++;
}
int main()
{
    doc();
    sort(v+1,v+n+1);
    dem=n;
    qq.push(0);
    while (dem>0 || !qq.empty())
    {
        if (qq.front()>=v[dem]) xuly1();
                    else xuly2();
        while (qq.front()==0 && qq.size()>=1) qq.pop();
    }
    cout<<kq;
}