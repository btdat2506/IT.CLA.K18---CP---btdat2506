{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}
const
 tfi='Hoctrinh.inp';
 tfo='Hoctrinh.out';
 nmax=100;
 Tmax=1000;
 Smax=10000;
 Diem:array[1..6] of longint=(5,6,7,8,9,10);

type
 arr=array[1..Tmax] of byte;

var
 fi,fo:text;
 n,t:integer;
 C,D:array[1..Tmax] of longint;
 tr:array[1..nmax] of ^arr;
 S:array[1..Smax] of integer;
 A:array[1..nmax,1..6] of integer;
 Kq:array[1..nmax] of byte;
 Dmax:longint;

procedure Capphat;
 var i:integer;
 begin
  for i:=1 to nmax do
      begin
       New(tr[i]);
       fillchar(tr[i]^,sizeof(tr[i]^),0);
      end;
 end;

procedure Enter;
 var i,j:integer;
 begin
  assign(fi,tfi);reset(fi);
  readln(fi,n,t);
  for i:=1 to n do read(fi,S[i]);
  for i:=1 to n do
      for j:=1 to 6 do read(fi,A[i,j]);
  close(fi);
 end;

procedure Qhd;
 var i,j,k:integer;
 begin
  for k:=1 to 6 do
      begin
       C[A[1,k]]:=S[1]*Diem[k];
       tr[1]^[A[1,k]]:=k;
      end;
  for i:=2 to n do
      begin
       fillchar(D,sizeof(D),0);
       for j:=1 to t do
           begin
            for k:=1 to 6 do
                if A[i,k]<j then
                   if C[j-a[i,k]]<>0 then
                      if D[j]<C[j-a[i,k]]+Diem[k]*S[i] then
                         begin
                          D[j]:=C[j-a[i,k]]+Diem[k]*S[i];
                          tr[i]^[j]:=k;
                         end;
           end;
       move(D,C,sizeof(D));
      end;
 end;

procedure Process;
 var j,u,v:integer;
 begin
  Dmax:=0;
  v:=0;
  for j:=1 to t do
      if C[j]>Dmax then
         begin
          Dmax:=C[j];
          v:=j;
         end;
  u:=n;
  repeat
   Kq[u]:=tr[u]^[v];
   v:=v-A[u,Kq[u]];
   u:=u-1;
  until u=0;
 end;

procedure Solve;
 begin
  Qhd;
  Process;
 end;

procedure Print;
 var i:integer;
 begin
  assign(fo,tfo);rewrite(fo);
  writeln(fo,Dmax);
  for i:=1 to n do writeln(fo,A[i,Kq[i]]);
  close(fo);
 end;

BEGIN
 Capphat;
 Enter;
 Solve;
 Print;
END.