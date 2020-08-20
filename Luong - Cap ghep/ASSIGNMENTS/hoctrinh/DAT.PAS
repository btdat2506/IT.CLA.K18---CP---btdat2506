{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R+,S+,T-,V+,X+}
{$M 16384,0,655360}
{$R-}
const
     fi='HOCTRINH.INP';
     fo='HOCTRINH.OUT';
type
    arr1=array[0..1000] of longint;
    arr2=array[1..100,1..6] of integer;
    arr3=array[1..100] of longint;
    arr4=array[1..1000] of byte;
var
   f,g:text;
   b:array[1..100] of ^arr4;
   b1,b2:arr1;
   a:^arr2;
   s:^arr3;
   n,t:integer;

  procedure mo;
  begin
       assign(f,fi);reset(f);
       assign(g,fo);rewrite(g);
  end;

  procedure dong;
  begin
       close(f);
       close(g);
  end;

  procedure nhap;
  var i,j:integer;
  begin
       new(a);
       new(s);
       readln(f,n,t);
       for i:=1 to n do read(f,s^[i]);
       for i:=1 to n do
       for j:=1 to 6 do
       read(f,a^[i,j]);
       for i:=1 to n do new(b[i]);
  end;

  procedure xdb;
  var i,j,k:integer;
      max:longint;
  begin
       for j:=0 to t do
       begin
            b2[j]:=0;
            for k:=6 downto 1 do
            if j>=a^[1,k] then
            begin
                 b2[j]:=(k+4)*s^[1];
                 break;
            end;
       end;
       i:=1;
       repeat
             inc(i);
             b1:=b2;
             for j:=0 to t do
             begin
                  max:=0;
                  for k:=1 to 6 do
                  if j>=a^[i,k] then
                  if max<b1[j-a^[i,k]]+(k+4)*s^[i] then
                  begin
                       max:=b1[j-a^[i,k]]+(k+4)*s^[i];
                       b[i]^[j]:=k;
                  end;
                  b2[j]:=max;
             end;
      until i=n;
  end;

  procedure inkq;
  var i,j,min,imin,k:integer;
      x:array[1..100] of integer;
  begin
       writeln(g,b2[t]);
       i:=n;
       j:=t;
       repeat
             x[i]:=b[i]^[j];
             j:=j-a^[i,b[i]^[j]];
             dec(i);
       until i=1;
       for k:=6 downto 1 do
       if a^[1,k]<=j then
       begin
            x[1]:=k;
            break;
       end;
       for i:=1 to n do writeln(g,a^[i,x[i]]);
  end;

begin
     mo;
     nhap;
     xdb;
     inkq;
     dong;
end.
