const
   M  =100;
   N  =100;
   tfi='MONHOC.IN0987654321';

var
   Gr: array[1..100,1..100] of byte;
   a: array[1..100] of integer;
procedure Taodl;
var i,j: integer;
begin
   for i:=1 to M do
      for j:=1 to N do
         Gr[i,j]:=random(2);
   for i:=1 to M do
      begin
         a[i]:=0;
         for j:=1 to N do a[i]:=a[i]+Gr[i,j];
         a[i]:=random(a[i])+1;
      end;
end;

procedure Inkq;
var fi: text;
    i,j: integer;
begin
   assign(fi,tfi); rewrite(fi);
   writeln(fi,M,' ',N);
   for i:=1 to M do
      begin
         write(fi,a[i],' ');
         for j:=1 to N do
            if Gr[i,j]=1 then write(fi,j,' ');
         writeln(fi);
      end;
   close(fi);
end;

BEGIN
    randomize;
    TaoDl;
    Inkq;
END.