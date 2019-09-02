uses crt;
const fo='laprap.in3';
var f:text;
 a,b,d,dc: array[0..200,0..200] of longint;
 o: array[0..200] of longint;
 i,j,m,t,n,h,ii,k:longint; cp,kq:int64;

 procedure nhap;
 begin
 assign(f,fo); reset(f);
  readln(f,n,m,t);
  for i:=1 to t do begin read(f,o[i]); {write(o[i]:4)};end;readln(f); {writeln;}
  for i:=1 to n do
  begin
  for j:=1 to n do begin read(f,a[i,j]); {write(a[i,j]:4)};end;
  readln(f); {writeln;}
  end;

  for i:=1 to n do
  begin
  for j:=1 to m do begin read(f,b[i,j]); {write(b[i,j]:4)};end;
  readln(f); {writeln;}
  end;
 end;

 procedure xuli;
 begin
    for i:=1 to 200 do
    for j:=1 to 200 do    d[i,j]:=100000;
    for j:=1 to n do begin d[1,j]:=b[j,o[1]]; dc[1,j]:=j; end;
    for i:=2 to t do
    for j:= 1 to n do
    for k:=1 to n do
    begin
    cp:=b[j,o[i]]+a[k,j];
    if d[i,j]>=d[i-1,k]+ cp then begin d[i,j]:=d[i-1,k]+cp; dc[i,j]:=k;  end;
    end;
 end;
 procedure xuat;
 var csmin,u: longint;
 begin
  kq:=d[t,1];  csmin:=1;
    for i:=1 to n do
    begin
         if kq> d[t,i] then begin kq:=d[t,i]; csmin:=i;end;
    end;
    write(kq);   writeln;
    write(csmin,' ');  u:=dc[t,csmin];
    for i:=t-1 downto 1 do
    begin
      write(u,' ');
      u:=dc[i,u];
        end;
     end;

begin
  clrscr;
  nhap;
  xuli;
  xuat;
  {
  for i:=0 to m do a[0,i]:=0;
  dc[0,1]:=0;
  for i:=0 to t do d[i]:=1000000000;

  for j:=1 to t do

    begin
    h:=1;k:=1;
      repeat
      begin
      for i:=1 to n do
      begin
      cp:= b[i,o[j]] + a[dc[j-1,h],i];
      if d[j] > cp then
      begin
          d[j]:=cp; for ii:=1 to k do dc[j,k]:=0; k:=1;
          dc[j,k]:=i;
      end else
      if d[j]=cp then begin k:=k+1; dc[j,k]:=i; end;
      end;
      h:=h+1;
      end;
      until dc[j-1,h]=0;
     end;
  kq:=0;
  for i:=1 to t do kq:=kq+d[i];
  writeln(kq);
  for j:=1 to t do write(dc[j,1]:4);   }
  readln;
end.
