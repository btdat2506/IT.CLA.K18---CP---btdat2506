/*************************************************************************
Program      :     Chon van dong vien thi dau (SPORT)
Date         :     11-3-2007
Group        :     Luong - Cap ghep (MinCost Flow)
*************************************************************************/

#include <fstream.h>
#define tfi "SPORT.INP"
#define tfo "SPORT.OUT"

// Khai bao luong input, output
ifstream inp;
ofstream out;

// Khai bao hang so
const int MAXN = 102;
const long VC = -2000000000;

// Khai bao cac bien chinh
int n,m,k, a[MAXN][MAXN];
int ft[MAXN], fp[MAXN];
int qf, ql, q[2*MAXN];
long kc[2*MAXN], ds;
int prev[2*MAXN], dd[2*MAXN];

// Ham doc du lieu
int doc()
{
    int i,j;
    inp.open(tfi);
    inp >> n >> m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) inp >> a[i][j];
    inp >> k;
    inp.close();
}    

// Ham khoi tao luong
int initflow()
{
    int i;
    for (i=1; i<=n; i++) ft[i]=0;
    for (i=1; i<=m; i++) fp[i]=0;
}

// Cac ham quan ly hang doi quay vong
int initq(){qf=1; ql=1;}
int put(int u) {q[ql++]=u; if (ql==2*MAXN-1) ql=1;}
int get() {int kq=q[qf++]; if (qf==2*MAXN-1) qf=1; return kq;}
int qempty() { return (qf==ql);}

// Ham Tim duong tang luong
int findpath()
{
    int i, u, v;
    initq(); 
    for (i=1; i<=n+m; i++) {prev[i]=0; kc[i]=VC; dd[i]=0;}
    for (i=1; i<=n; i++)
        if (ft[i]==0) {put(i); kc[i]=0; dd[i]=1; prev[i]=n+m+1;}
    while (!qempty()) 
    {
        u=get(); dd[u]=0;
        if (u<=n)  // ben trai
        {
            for (v=n+1; v<=n+m; v++)
                if ((ft[u]!=v-n) && (kc[v]<kc[u]+a[u][v-n]))
                {
                    kc[v]=kc[u]+a[u][v-n];
                    prev[v]=u;
                    if (dd[v]==0) {dd[v]=1; put(v);}
                } 
        } else  // ben phai
        {
            if (fp[u-n]!=0) 
            {
                v=fp[u-n];
                if (kc[v]<kc[u]-a[v][u-n]) 
                {
                    kc[v]=kc[u]-a[v][u-n];
                    prev[v]=u;
                    if (dd[v]==0) {dd[v]=1; put(v);}
                }
            }
        }
        
    }
    // Tim vi tri ket thuc
    long max=-1; u=0;
    for (i=n+1; i<=n+m; i++)
       if ((fp[i-n]==0) && (max<kc[i])) {max=kc[i]; u=i;}
    return u;
}

// Ham tang luong
int incflow(int v)
{
    int u;
    while (prev[v]!=n+m+1)
    {
        u=prev[v];
        if (u<=n) {ft[u]=v-n; fp[v-n]=u;}
        v=u;
    }
}


// Ham chinh
int solve()
{
    int i;
    if ((k>m) || (k>n)) return 0;
    initflow();
    for (i=1; i<=k; i++) 
       {
           int u=findpath();
           incflow(u);
       }
    ds=0;
    for (i=1; i<=n; i++) ds+=(ft[i]!=0) ? a[i][ft[i]] : 0;
    return 1;
}    

// Ham in ket qua
int viet()
{
    int i;
    out.open(tfo);
    if (!solve()) out << -1; else
    {
        out << ds << '\n';
        for (i=1; i<=n; i++)
            if (ft[i]!=0) out << i << ' ' << ft[i] << '\n';
    }
    out.close();
}    

// CHUONG TRINh CHINH
int main()
{
    doc();
    viet();
}    
