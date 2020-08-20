{$R+}
const
     tfi='HOCTRINH.INP';
     tfo='HOCTRINH.OUT';
     maxn=100;
Type
    mang=array[1..1000] of longint;
    mang1=array[1..1000] of byte;

var
   b,c:mang;
   s:array[1..maxn] of integer;
   a:array[1..maxn,1..6] of integer;
   tr:array[1..100] of ^mang1;
   n,t:integer;
   fi,fo:text;

procedure docdl;
var
   i,j:integer;
begin
     assign(fi,tfi);reset(fi);
     readln(fi,n,t);
     for i:=1 to n do read(fi,s[i]);
     readln(fi);
     for i:=1 to n do
         begin
              for j:=1 to 6 do read(fi,a[i,j]);
              readln(fi);
         end;
     close(fi);
end;

procedure capphat;
var
   i:integer;
begin
     for i:=1 to 100 do new(tr[i]);
end;

procedure qhd;
var
   i,j,k:longint;
begin
     fillchar(b,sizeof(b),0);
     for i:=1 to 6 do
         if a[1,i]<=t then
            begin
                 b[a[1,i]]:=(4+i)*s[1];
                 tr[1]^[a[1,i]]:=i;
            end;
     for i:=2 to n do
         begin
              fillchar(c,sizeof(c),0);
              for j:=1 to 6 do
                  for k:=t downto 1 do
                      if (b[k]>0) and (k+a[i,j]<=t) then
                         if c[k+a[i,j]]<s[i]*(j+4)+b[k] then
                            begin
                                 c[k+a[i,j]]:=s[i]*(j+4)+b[k];
                                 tr[i]^[k+a[i,j]]:=j;
                            end;
              b:=c;
         end;
end;

procedure Inkq;
var
   i,j,k,dem:integer;
   max:longint;
   x:array[1..100] of byte;
begin
     assign(fo,tfo);
     rewrite(fo);
     max:=0;
     for j:=1 to t do
         if b[j]>max then
            begin
                 i:=j;
                 max:=b[i];
            end;
     j:=n;dem:=0;
     if max=0 then exit;
     k:=tr[j]^[i];
     writeln(fo,max);
     repeat
           k:=tr[j]^[i];
           inc(dem);
           x[dem]:=k;
           i:=i-a[j,k];
           dec(j);
     until j=0;
     for i:=dem downto 1 do writeln(fo,a[n+1-i,x[i]],#32);
     close(fo);
end;

begin
     capphat;
     docdl;
     qhd;
     inkq;
end.
3 12
1 2 3
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6





