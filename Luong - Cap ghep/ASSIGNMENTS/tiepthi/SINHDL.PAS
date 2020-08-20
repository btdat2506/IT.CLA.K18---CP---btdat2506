const
   N=200;
   K=200;
   tfi='TIEPTHI.IN0987654321';

type
   mang=array[1..200] of longint;

var
   c: array[1..200] of ^mang;
   dau, cuoi: array[1..200] of integer;

procedure Taodl;
var i,j,l: integer;
begin
   for i:=1 to N do c[i]^[i]:=0;
   for i:=1 to N-1 do
      for j:=i+1 to N do
         begin
            c[i]^[j]:=random(10000)+1;
            c[i]^[j]:=4*c[i]^[j];
            c[j]^[i]:=c[i]^[j];
         end;
   for i:=1 to N do dau[i]:=i;
   for i:=N downto 2 do
      begin
         j:=random(i)+1;
         l:=dau[i];
         dau[i]:=dau[j];
         dau[j]:=l;
      end;
   for i:=1 to N do cuoi[i]:=i;
   for i:=N downto 2 do
      begin
         j:=random(i)+1;
         l:=cuoi[i];
         cuoi[i]:=cuoi[j];
         cuoi[j]:=l;
      end;

end;

procedure Inkq;
var fi: text;
    i,j: integer;
begin
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N,' ',K);
   for i:=1 to N do
      begin
         for j:=1 to N do write(fi,c[i]^[j],' ');
         writeln(fi);
      end;
   for i:=1 to K do write(fi,dau[i],' ');
   writeln(fi);
   for i:=1 to K do write(fi,cuoi[i],' ');
   writeln(fi);
   close(fi);
end;

procedure CapPhat;
var i: integer;
begin
   for i:=1 to N do new(c[i]);
end;

BEGIN
   CapPhat;
   randomize;
   Taodl;
   inkq;
END.