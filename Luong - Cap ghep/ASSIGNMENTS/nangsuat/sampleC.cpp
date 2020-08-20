/*************************************************************************
Program    :   Phan viec tren day chuyen (NANGSUAT)
Date       :   9-3-2007
Group      :   Luong - Cap ghep
*************************************************************************/

#include <fstream.h>
#define tfi "NANGSUAT.INP"
#define tfo "NANGSUAT.OUT"

// khai bao cac hang so
const int MAXN = 202;

// Khai bao luong input, output
ifstream inp;
ofstream out;

// Khai bao cac bien chinh
int n;
int a[MAXN][MAXN];
int ft[MAXN], fp[MAXN],mf;
long lim;
int q[MAXN], qf, ql;
int tr[MAXN];
int ktt, ktp;

// Ham doc du lieu tu file input
int doc()
{
    int i,j;
    inp.open(tfi);
    inp >> n;
    for (i=1; i<=n; i++)
       for (j=1; j<=n; j++) inp >> a[i][j];
    inp.close();
}

// Ham khoi dau mot luong 0
int initflow()
{
    for (int i=1; i<=n; i++) {ft[i]=0; fp[i]=0;}
}    

// Cac ham quan ly hang doi
int initq() {qf=1; ql=1;}
int put(int u) {q[ql++]=u;}
int get() {return q[qf++];}
int qempty() {return (qf==ql);}

// Ham tim duong tang luong
int findpath()
{
    int u,v,w,i;
    initq();
    for (i=1; i<=n; i++) tr[i]=0;
    for (i=1; i<=n; i++)
       if (ft[i]==0) {put(i); tr[i]=-1;}
    while (!qempty())
    {
        int u=get();
        for (v=1; v<=n; v++)
           if ((a[u][v]>=lim) && (ft[u]!=v))
           {
               if (fp[v]==0) {ktp=v; ktt=u; return 1;}
               w=fp[v];
               if (tr[w]==0) {put(w); tr[w]=u;}
           }
    }
    return 0;
}    

// Ham tang gia tri cua luong
int incflow()
{
    int u,v,v1;
    u=ktt; v=ktp;
    do {v1=ft[u]; ft[u]=v; fp[v]=u; u=tr[u]; v=v1;} while (u!=-1);
}    
    

// Ham ghep voi thoi gian lim
int ghep()
{
    int i,k;
    initflow();
    while (findpath()) incflow();
    mf=0;
    for (i=1; i<=n; i++)
       if (ft[i]!=0) mf++;
}

// Ham phan viec
int solve()
{
    long d,c;
    d=0;
    c=0;
    for (int i=1; i<=n; i++)
       for (int j=1; j<=n; j++) 
          if (c<a[i][j]) c=a[i][j];
    c++;
    do 
    {
       lim=(d+c)/2; ghep();
       if (mf<n) c=lim; else d=lim;
    } while (c-d>1);
    lim=d;
    ghep();
}    

// Ham in ket qua
int viet()
{
    int i;
    out.open(tfo);
    out << lim << '\n';
    for (i=1; i<=n; i++) out << ft[i] << '\n';
    out.close();
}    

// CHUONG TRINH CHINH
int main()
{
    doc();
    solve();
    viet();
}    
