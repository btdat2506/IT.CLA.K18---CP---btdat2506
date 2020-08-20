const
   N=80;
   M=100;
   tfi='NASA.IN870987654321';

var
   a,b: array[1..100] of integer;
   c: array[1..100,1..100] of byte;

procedure Taodl;
var i,j: integer;
begin
   for i:=1 to N do a[i]:=random(50)+1;
   for i:=1 to M do b[i]:=random(4)+1;
   for i:=1 to N do
      for j:=1 to M do
         begin
            c[i,j]:=random(5);
            if c[i,j]<>1 then c[i,j]:=0;
         end;
end;

procedure Inkq;
var fi: text;
    i,j: integer;
begin
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N,' ',M);
   for i:=1 to N do write(fi,a[i],' '); writeln(fi);
   for i:=1 to M do write(fi,b[i],' '); writeln(fi);
   for i:=1 to N do
      begin
         for j:=1 to M do write(fi,c[i,j],' ');
         writeln(fi);
      end;
   close(fi);
end;


BEGIN
   randomize;
   Taodl;
   Inkq;
END.