/******************************************************************************
Program :  CHUONG TRINH CHAM BAI HOC SINH - Version 1.0 (Ban C++)
Date    :  06-03-2007
******************************************************************************/

#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <iomanip.h>
#include <conio.h>
#include <string.h>
#include <math.h>

// Dinh ngia cac luong
ifstream inp;
ifstream out;
ifstream ans;

// khai bao phan dau cac file
char fi[] = "INP.00";
char fo[] = "OUT.00";
char fm[] = "ANS.00";
int Pmin   = 1;
int Pmax   = 10;

char cp[3]="00";

// Khai bao bien
int loi[100], diem[100], tong=0;
long kqm, kqo;


// Ham Doc du lieu (neu co)
int doc()
{
    return 0;
}   

// Ham cham diem 
int cham() 
{
    out >> kqo;
    ans >> kqm;
    if (kqm!=kqo) return 10; // wrong answer
    return 0;
}    

// Ham in ket qua
int viet()
{
    int i;
    cout << '\n';
    cout << "KET QUA CHAM BAI" << '\n';
    cout << '\n';
    cout << '\n';
    for (i=Pmin; i<=Pmax; i++)
    {
        cout << "Test " << setw(2) << i << "  :  "  << diem[i] << " --- ";
        switch (loi[i])
        {
            case 0 : cout << "Accept" ; break;
            case 1 : cout << "Missing Output File"; break; 
            case 10: cout << "Wrong answer"; break;
        }
        cout << '\n';
    }
    cout << "--------------------------" << '\n';
    cout << "Tong     =" << setw(3) << tong << '\n';
    cout << '\n';
    cout << '\n';
    cout << "Press any key to continue..." << '\n';
    getch();
    return 0;
}    

// Xoa tat ca cac file output
int XoaFile()
{
    int i;
    FILE *f;
    for (i=Pmin; i<=Pmax; i++)
    {
        fo[4]=i/10+48; fo[5]=i%10+48;
        f=fopen(fo,"r");
        if (f!=NULL) {fclose(f); remove(fo);}
    }
}    


// Ham cham diem
int check()
{
    int p;
    char u,v;
    for (p=Pmin; p<=Pmax; p++)
    {
        u=p/10+48;
        v=p%10+48;
        fi[4]=u; fi[5]=v;
        fo[4]=u; fo[5]=v;
        fm[4]=u; fm[5]=v;
        
        // Khai bao luong
        inp.open(fi);
        out.open(fo);
        if (!out.good()) {loi[p]=1; diem[p]=0;} else
        {
            ans.open(fm);
                
            // Cham diem
            doc();
            loi[p]=cham();
            if (loi[p]==0) diem[p]=10; else diem[p]=0;
            tong+=diem[p];
        
            // Dong luong
            inp.close();
            out.close();
            ans.close();
        }
    }
    viet();
    XoaFile();
    return 0;
}     

// CHUONG TRINH CHINH
int main()
{
    check();
}    
