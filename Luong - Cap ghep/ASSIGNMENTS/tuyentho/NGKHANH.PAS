{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 1500,0,655360}
Const
 fi='Assign.in6543213215';
 fo='Assign.ou6543213215';
    {Assign.ou5}
Type
 Mach=Array [0..300] Of Longint;
 Data=Array [0..300] Of ^Mach;
Var
 first,last,start,finish,k,w,n,m,r,t : Longint;
 d,l,a,mx,my,x,y,u,q,p : Mach;
 c : Data;
 f : Text;
Procedure Output;
 Var
  i : Longint;
 Begin
  Assign(f,fo);Rewrite(f);
  Writeln(f,n-w,' ',t);
  For i:=1 To n Do Writeln(f,u[i]);
  Close(f);
 End;
Function Get(i,j : Longint) : Longint;
 Begin
  Get:=c[l[i]]^[j]-x[l[i]]-y[j];
 End;
Procedure InitBFS;
 Var
  i : Longint;
 Begin
  Fillchar(p,Sizeof(Mach),0);
  first:=1;last:=1;
  q[1]:=start;
  finish:=0;
  For i:=1 To k Do
   Begin
    d[i]:=Get(start,i);
    a[i]:=start;
   End;
 End;
Procedure FindPath;
 Var
  i,j : Longint;
 Begin
  While first<=last Do
   Begin
    i:=q[first];Inc(first);
    For j:=1 To k Do
     Begin
      If (p[j]=0) And (Get(i,j)=0) Then
       Begin
        p[j]:=i;
        If my[j]=0 Then
         Begin
          finish:=j;
          Exit;
         End;
        Inc(last);q[last]:=my[j];
       End;
      If Get(i,j)<d[j] Then
       Begin
        d[j]:=Get(i,j);
        a[j]:=i;
       End;
     End;
   End;
 End;
Procedure Repeair;
 Var
  delta,i : Longint;
 Begin
  delta:=100000000;
  For i:=1 To k Do If (p[i]=0) And (d[i]<delta) Then delta:=d[i];
  Inc(x[l[start]],delta);
  For i:=1 To k Do If p[i]=0 Then
   d[i]:=d[i]-delta
  Else
   Begin
    x[l[my[i]]]:=x[l[my[i]]]+delta;
    y[i]:=y[i]-delta;
   End;
  For i:=1 To k Do If (p[i]=0) And (d[i]=0) Then
   Begin
    p[i]:=a[i];
    If my[i]=0 Then
     Begin
      finish:=i;
      Exit;
     End;
    Inc(last);q[last]:=my[i];
   End;
 End;
Procedure Enlarge;
 Var
  next,i : Longint;
 Begin
  Repeat
   i:=p[finish];
   next:=mx[i];
   mx[i]:=finish;
   my[finish]:=i;
   finish:=next;
  Until
   finish=0;
 End;
Procedure Solve;
 Var
  i,j : Longint;
 Begin
  If m<n Then k:=n Else k:=m;
  For i:=1 To k Do
   Begin
    start:=i;
    InitBFS;
    Repeat
     FindPath;
     If finish=0 Then Repeair;
    Until
     finish<>0;
    Enlarge;
   End;
  For i:=1 To k Do If c[l[i]]^[mx[i]]<=10000 Then
   Begin
    Inc(w);
    u[mx[i]]:=l[i];
   End;
  For i:=1 To n Do If u[i]=0 Then For j:=1 To r Do If (c[j]^[i]<c[u[i]]^[i]) Or (u[i]=0) Then u[i]:=j;
  k:=n;
  Fillchar(x,Sizeof(Mach),0);
  Fillchar(y,Sizeof(Mach),0);
  Fillchar(mx,Sizeof(Mach),0);
  Fillchar(my,Sizeof(Mach),0);
  For i:=1 To k Do l[i]:=u[i];
  For i:=1 To k Do
   Begin
    start:=i;
    InitBFS;
    Repeat
     FindPath;
     If finish=0 Then Repeair;
    Until
     finish<>0;
    Enlarge;
   End;
  For i:=1 To k Do If c[l[i]]^[mx[i]]<=10000 Then
   Begin
    u[mx[i]]:=l[i];
    t:=t+c[l[i]]^[mx[i]];
   End;
 End;
Procedure Input;
 Var
  i,j : Longint;
 Begin
  Assign(f,fi);Reset(f);
  Readln(f,m,n,r);
  If n<m Then k:=m Else k:=n;
  If k<r Then k:=r;
  For i:=0 To k Do
   Begin
    New(c[i]);
    For j:=0 To k Do c[i]^[j]:=100000000;
   End;
  For i:=1 To m Do Read(f,l[i]);
  While Not SEEKEOF(f) Do Readln(f,i,j,c[i]^[j]);
  Close(f);
 End;
Begin
 Input;
 Solve;
 Output;
End.