#include <bits/stdc++.h>

using namespace std;
struct ii
{
    long long u,v,c;
};
long long matchX[1005],matchY[1005],trace[10005],m,n,k,x,y,c[100][100];;
long long finds()
{
    memset(trace,0,sizeof(trace));
    queue < long long > qu;
    while (!qu.empty()) qu.pop();
    for(long long i=1;i<=x;i++)
    {
        if (matchX[i]==0) qu.push(i);
    }
    while (!qu.empty())
    {
        long long k=qu.front();
        qu.pop();
        for(long long j=1;j<=y;j++)
        {
            if (trace[j]==0 && c[k][j]==1 )
            {
                trace[j]=k;
                if (matchY[j]==0)
                {
                    return j;
                }
            qu.push(matchY[j]);
            }
        }
    }
    return 0;
}
void enlarge(long long f)
{
    long long x,next;
    do
    {
        x=trace[f];
        next=matchX[x];
        matchX[x]=f;
        matchY[f]=x;
        f=next;
    }
    while (f!=0);
}
void solve()
{
    long long finish;
    do
    {
        finish=finds();
        if (finish!=0) {
            enlarge(finish);

        }
    }
    while (finish!=0);
}
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long dem,a[50][50];
    cin >> m >> n;
    for(long long i=0;i<=m+1;i++)
        for(long long j=0;j<=n+1;j++) a[i][j]=2;
    for(long long i=1;i<=m;i++)
        for(long long j=1;j<=n;j++) cin >> a[i][j];
    //--------------------------//
    ii dd[101],dc[101];
    dem=1;
    for(long long i=1;i<=m;i++)
    {
        long long j=1,first,Lfirst,Llast;
        while (j<=n)
        {
            if (a[i][j]!=2)
        {
                first=j;
                Lfirst=j;
                while (a[i][j]!=2) j++;
                Llast=j-1;
                dd[dem].u=i;
            dd[dem].v=Lfirst;
            dd[dem].c=Llast;
            dem++;
        }
        j++;
        }
    }
    x=dem-1;
    //------------------------------------//
    dem=1;
    for(long long i=1;i<=n;i++)
    {
        long long j=1,first,Lfirst,Llast;
        while (j<=m)
        {
            if (a[j][i]!=2)
        {
                first=j;
                Lfirst=j;
                while (a[j][i]!=2) j++;
                Llast=j-1;
                dc[dem].u=i;
                dc[dem].v=Lfirst;
                dc[dem].c=Llast;
                dem++;
        }
        j++;
        }
    }
    y=dem-1;
    //---------------------------------//
    for(long long i=1;i<=x;i++)
    {
        for(long long j=1;j<=y;j++)
        {
                c[i][j]=0;
            if ((dd[i].u >= dc[j].v && dd[i].u <= dc[j].c) && ((dc[j].u >= dd[i].v && dc[j].u <= dd[i].c)))
                    {
                        if (a[dd[i].u][dc[j].u]!=1)
                        {
                            c[i][j]=1;
                        }
                    }
        }
    }

    for(long long i=1;i<=x;i++) cout << dd[i].u << ' ' << dd[i].v << ' ' << dd[i].c << endl; cout << endl;
    for(long long i=1;i<=y;i++) cout << dc[i].u << ' ' << dc[i].v << ' ' << dc[i].c << endl;
        for(long long i=1;i<=x;i++)
    {
        for(long long j=1;j<=y;j++)
            cout << c[i][j];
        cout << endl;
    }
    solve();
    long long d=0;
    for(long long i=1;i<=x;i++)
    {
        if (matchX[i]!=0)
        {
            d++;
        }
    }
        for(long long i = 1; i <= x; i++) cout << matchX[i]; cout << endl;
    cout << d << endl;
    return 0;
}