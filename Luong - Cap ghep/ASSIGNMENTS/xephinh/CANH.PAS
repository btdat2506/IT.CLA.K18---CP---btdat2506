{$M 16384,0,655360}
Const
   tfi          =            'xep.inp';
   tfo          =            'xep.out';
   d            :            array[1..8]of byte=(1,2,4,8,16,32,64,128);
   maxn         =            101;
var
   fi,fo        :            text;
   a,dd         :            array[1..maxn*maxn]of byte;
   b,e          :            array[1..maxn,1..maxn]of byte;
   c            :            array[1..maxn,1..maxn]of integer;
   m,n,sl       :            longint;
procedure nhap;
var i,j:integer;
begin
   readln(fi,m,n);
   for i:=1 to m*n do read(fi,a[i]);
   for i:=1 to m do
      for j:=1 to n do read(fi,b[i,j]);
end;
procedure xet(u,v,l:longint);
var i,j:longint;
begin
  for i:=1 to m do
    for j:=1 to n do
      if (c[i,j]=0)and(b[i,j]=u) then
        begin
          c[i,j]:=v;
          e[i,j]:=l;
          sl:=sl+l;
          dd[v]:=1;
          exit;
        end;
end;
procedure tim0;
var i:longint;
begin
   for i:=1 to m*n do
    if dd[i]=0 then
       xet(a[i],i,0);
end;
function xoay(l,u:longint):longint;
var s,s1:string;
   i:longint;
begin
  s:='';
  repeat
    s:=chr(u mod 2+48)+s;
    u:=u div 2;
  until u=0;
  while length(s)<8 do s:='0'+s;
  for i:=1 to l do
    begin
        s1:=copy(s,7,2);
        delete(s,7,2);
        s:=s1+s;
     end;
  u:=0;
  for i:=1 to 8 do
     u:=u+(ord(s[i])-48)*d[8-i+1];
  xoay:=u;
end;
procedure tim1;
var i,u:longint;
begin
  for i:=1 to m*n do
  if dd[i]=0 then
   begin
     u:=xoay(1,a[i]);
     xet(u,i,1);
   end;
end;
procedure tim2;
var i,u:longint;
begin
  for i:=1 to m*n do
   if dd[i]=0 then
   begin
     u:=xoay(2,a[i]);
     xet(u,i,2);
   end;
end;
procedure tim3;
var i,u:longint;
begin
  for i:=1 to m*n do
   if dd[i]=0 then
   begin
     u:=xoay(3,a[i]);
     xet(u,i,3);
   end;
end;
procedure tham;
var ok:boolean;
begin
   fillchar(dd,sizeof(dd),0);
   fillchar(c,sizeof(c),0);
   sl:=0;
   tim0;
   tim1;
   tim2;
   tim3;
end;
procedure tim;
var i,j,t:longint;
begin
   tham;
   t:=0;
   for i:=1 to m do
     for j:=1 to n do
       if c[i,j]<>0 then inc(t);
   if t<>m*n then writeln(fo,-1) else
   begin
     for i:=1 to m do
       begin
         for j:=1 to n do write(fo,c[i,j],' ');
         writeln(fo);
       end;
      for i:=1 to m do
       begin
         for j:=1 to n do write(fo,e[i,j],' ');
         writeln(fo);
       end;
   end;
end;
begin
   assign(fi,tfi);reset(fi);
   assign(fo,tfo);rewrite(fo);
   nhap;
   tim;
   close(fi);close(fo);
end.
