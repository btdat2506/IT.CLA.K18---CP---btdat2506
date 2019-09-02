/*
Bài này tư tưởng là bạn nhận xét thế này vì 2 mảnh đất là hình chữ nhật và không giao nhau nên giữa 2 mảnh đất đó sẽ có:

1. một đường dọc phân cách
2. một đường ngang phân cách
3. cả 2 đường dọc và ngang phân cách.

TH1: Có đường dọc phân cách thì bạn tính 2 hàm sau Lcoli và Rcoli. Hàm Lcoli
có ý nghĩa là hình chữ nhật lớn nhất nằm trong các cột từ 1→i mà thỏa mãn
chênh lệch không quá K . Hàm Rcoli cũng cùng ý nghĩa như vậy nhưng là các cột
từ M→i. Kết quả của trường hợp này là max{Lcoli+Rcoli∣∣i:1→M−1}.

TH2: Có đường ngang phân cách thì tư tưởng cũng giống như ở TH1.

TH3: Trường hợp này không cần xét tới vì đã được tính trong cả 2 trường hợp trên.

Kết quả toàn bài sẽ là max của TH1 và TH2.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define nmax 310
#define read scanf
#define write printf
#define vc 1000000000
int n,m,k;
int res=0,final = 0,a[nmax][nmax];
void xuly1()
{
    int hmin[nmax],hmax[nmax],c[nmax][nmax],st1[nmax],st2[nmax],gt[nmax],kq[nmax];
    foru(i,1,n)
     {
         foru(j,1,m) {hmin[j]=vc;hmax[j]=-vc;}
         int res= 0;
         foru(j,i,n)
            {
                int dau1 = 1;
                int dau2 = 1;
                int top1 = 0;
                int top2 = 0;
                int t2= 1;
                foru(t1,1,m) {hmin[t1]=min(hmin[t1],a[j][t1]);hmax[t1]=max(hmax[t1],a[j][t1]);}
                foru(t1,1,m)
                  {
                      while (top1>=dau1 && hmax[t1]>=hmax[st1[top1]]) top1--;
                      while (top2>=dau2 && hmin[t1]<=hmin[st2[top2]]) top2--;
                      top1++;st1[top1]=t1;
                      top2++;st2[top2]=t1;
                      while (top1>=dau1 && top2>=dau2 && hmax[st1[dau1]]-hmin[st2[dau2]]>k)
                       {
                           t2++;
                           while (dau1<=top1 && st1[dau1]<t2) dau1++;
                           while (dau2<=top2 && st2[dau2]<t2) dau2++;
                       }
                      if (t2<=t1) res = max(res,(t1-t2+1)*(j-i+1));
                  }
                 c[i][j] = res;
            }

     }
     kq[0]=0;
     foru(i,1,n)
       {
           gt[i]=0;
           foru(j,1,i) gt[i]=max(gt[i],c[j][i]);
           kq[i]=max(kq[i-1],gt[i]);
       }
    foru(i,2,n)
    foru(j,i,n)
      final = max(final,c[i][j]+kq[i-1]);
}
void xuly2()
{
    int hmin[nmax],hmax[nmax],c[nmax][nmax],st1[nmax],st2[nmax],gt[nmax],kq[nmax];
    foru(i,1,m)
     {
         foru(j,1,m) {hmin[j]=vc;hmax[j]=-vc;}
         int res= 0;
         foru(j,i,m)
            {
                int dau1 = 1;
                int dau2 = 1;
                int top1 = 0;
                int top2 = 0;
                int t2= 1;
                foru(t1,1,n) {hmin[t1]=min(hmin[t1],a[t1][j]);hmax[t1]=max(hmax[t1],a[t1][j]);}
                foru(t1,1,n)
                  {
                      while (top1>=dau1 && hmax[t1]>=hmax[st1[top1]]) top1--;
                      while (top2>=dau2 && hmin[t1]<=hmin[st2[top2]]) top2--;
                      top1++;st1[top1]=t1;
                      top2++;st2[top2]=t1;
                      while (top1>=dau1 && top2>=dau2 && hmax[st1[dau1]]-hmin[st2[dau2]]>k)
                       {
                           t2++;
                           while (dau1<=top1 && st1[dau1]<t2) dau1++;
                           while (dau2<=top2 && st2[dau2]<t2) dau2++;
                       }
                      if (t2<=t1) res = max(res,(t1-t2+1)*(j-i+1));
                  }
                c[i][j] = res;
            }

     }
     kq[0]=0;
     foru(i,1,m)
       {
           gt[i]=0;
           foru(j,1,i) gt[i]=max(gt[i],c[j][i]);
           kq[i]=max(kq[i-1],gt[i]);
       }
    foru(i,2,m)
    foru(j,i,m)
      final = max(final,c[i][j]+kq[i-1]);
}
int main()
{
   // freopen("bland.inp","r",stdin);
    read("%d%d%d",&n,&m,&k);
    foru(i,1,n) foru(j,1,m) read("%d",&a[i][j]);
    xuly1();
    xuly2();
    write("%d",final);
    return 0;
}
