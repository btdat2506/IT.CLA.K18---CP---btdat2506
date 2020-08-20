{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}
Program assignWork;
Const
     fi='assign.inp';
     fo='assign.out';
     MaxN=300;
type vector=array[1..MaxN] of word;
     arrayc=array[0..MaxN] of ^vector;
Var
   c:arrayc;
   m,n,r,kk:byte;
   typet,superman:array[1..MaxN] of byte;
   matchx,matchy,trace,pre:array[1..MaxN] of byte;
   fx,fy,d:array[1..MaxN] of longint;
   q:array[1..MaxN] of byte;
   first, last,add, start, finish:byte;
   f:text;
{****************************************************}
function max(a,b:integer):integer;
begin
  if a>b then max:=a else max:=b;
end;
{****************************************************}
Procedure alloc_mem;
var i,j:byte;
begin
  new(c[0]);
  for i:=1 to kk do begin
    new(c[i]);
    for j:=1 to kk do c[i]^[j]:=maxint;
  end;
end;
{****************************************************}
Procedure InputData;
var a:array[1..MaxN] of integer;
    counter,data:word;
    i,j:byte;
begin
  assign(f,fi);
  reset(f);
  readln(f,m,n,r);
  kk:=max(n,m);
  alloc_mem;
  for counter:=1 to m do read(f,typet[counter]);
  readln(f);
  for i:=1 to n do a[i]:=maxint;
  while not eof(f) do begin
    readln(f,i,j,data);
    c[i]^[j]:=data;
    if a[j]>data then begin
      a[j]:=data;
      superman[j]:=i;
    end;
  end;
  for j:=1 to n do c[0]^[j]:=a[j];
  close(f);
end;
{****************************************************}
Procedure Initialize;
begin
end;
{****************************************************}
function gc(i,j:byte):integer;
begin
  gc:=c[i]^[j];
end;
{****************************************************}
Procedure Init_findingAugmentingpath;
var i,j,t:byte;
    temp:word;
begin
  fillchar(matchx, sizeof(matchx), 0);
  fillchar(matchy, sizeof(matchy), 0);
  fillchar(fy, sizeof(fy), 0);
  for i:=1 to kk do begin
    fx[i]:=maxint+1;
    t:=typet[i];
    for j:=1 to n do if gc(t,j)<fx[i] then
       fx[i]:=gc(t,j);
  end;
end;
{****************************************************}
Procedure push(u:byte);
begin
  inc(last);
  q[last]:=u;
end;
{****************************************************}
function pop:byte;
begin
  pop:=q[first];
  inc(first);
end;
{****************************************************}
Procedure Init_q;
var i,j,t:byte;
begin
  first:=1;
  last:=0;
  fillchar(trace, sizeof(trace), 0);
  t:=typet[start];
  for j:=1 to n do begin
    d[j]:=gc(t, j);
    pre[j]:=start;
  end;
  finish:=0;
  push(start);
end;
{****************************************************}
function gf(u,v:byte):longint;
var t:byte;
begin
  t:=typet[u];
  gf:=gc(t,v) - fx[u] - fy[v];
end;
{****************************************************}
Procedure findaugmentingPath;
var w:longint;
    u,v:byte;
begin
  while first<=last do begin
    u:=pop;
    for v:=1 to n do begin
      if trace[v]<>0 then continue;
      w:=gf(u,v);
      if w=0 then begin
        trace[v]:=u;
        if matchy[v]=0 then begin
          finish:=v;
          exit;
        end;
        push(matchy[v]);
      end;
      if w<d[v] then begin
        d[v]:=w;
        pre[v]:=u;
      end;
    end;
  end;
end;
{****************************************************}
Procedure aFx_fy;
var delta:longint;
    i,j,u,v:byte;
begin
  delta:=1 shl 30;
  for j:=1 to n do if trace[j]=0 then
     if d[j]<delta then delta:=d[j];
  fx[start]:=fx[start]+delta;
  for v:=1 to n do if trace[v]<>0 then begin
    u:=matchy[v];
    fx[u]:=fx[u]+delta;
    fy[v]:=fy[v]-delta;
  end else d[v]:=d[v]-delta;

  for v:=1 to n do if trace[v]=0 then begin
    if d[v]=0 then begin
      trace[v]:=pre[v];
      if matchy[v]=0 then begin
        finish:=v;
        exit;
      end;
      push(matchy[v]);
    end;
  end;
end;
{****************************************************}
Procedure enlarge;
var next, k, j:byte;
begin
  j:=finish;
  repeat
    k:=trace[j];
    next:=matchx[k];
    matchy[j]:=k;
    matchx[k]:=j;
    j:=next;
  until j=0;
end;
{****************************************************}
function check(i:byte):boolean;
var t:byte;
begin
  t:=matchx[i];
  check:=(i>=1) and (i<=n) and (gc(typet[i], t)<maxint);
end;
{****************************************************}
Procedure Solve;
var i,j:byte;
    saven:byte;
begin
  saven:=n;
  n:=kk;
  Init_findingAugmentingPath;
  for i:=1 to m do begin
    Start:=i;
    Init_Q;
    repeat
      findAugmentingPath;
      If finish=0 then Afx_fy;
    until finish>0;
    enlarge;
  end;
  n:=saven;
  j:=0;
  for i:=1 to m do begin
    if check(i) then begin
      inc(j);
      typet[j]:=typet[i];
    end;
  end;
  add:=0;
  if j=n then exit
  else add:=n-j;
  for i:=j+1 to n do typet[i]:=0;
  Init_FindingAugmentingPath;
  for i:=1 to n do begin
    start:=i;
    Init_Q;
    repeat
      findAugmentingPath;
      if finish=0 then aFx_fy;
    until finish>0;
    enlarge;
  end;
end;
{****************************************************}
Procedure Writesolution;
var i,j,t:byte;
    res:longint;
begin
  assign(f,fo);
  rewrite(f);
  res:=0;
  for i:=1 to n do begin
    t:=typet[i];
    res:=res+gc(t, matchx[i]);
  end;
  writeln(f,add,' ',res);
  for j:=1 to n do begin
    t:=typet[ matchy[j] ];
    if t=0 then t:=superman[j];
    writeln(f,t);
  end;
  close(f);
end;
{****************************************************}
begin
  InputData;
  Initialize;
  Solve;
  writeSolution;
end.