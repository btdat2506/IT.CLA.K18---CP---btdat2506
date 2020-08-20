uses crt;
const
   N=100;
   tfi='TIGER.IN';

var
   x: array[1..100] of integer;

procedure TaoDl;
var i,j,tg: integer;
begin
   for i:=1 to N do x[i]:=i;
   for i:=n-1 downto 3 do
      begin
         j:=random(i)+2;
         tg:=x[j];
         x[j]:=x[i];
         x[i]:=tg;
      end;
end;

procedure Inkq;
var fi: text;
    k,i,j,socanh: integer;
    d,c: array[1..10] of integer;

function chuaco(k: integer): boolean;
var i: integer;
begin
   chuaco:=false;
   for i:=1 to k-1 do
      if (d[i]=d[k]) and (c[i]=c[k]) then exit;
   chuaco:=true;
end;
begin
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N);
   (* In cac canh trong cac mui *)
   for k:=1 to 4 do
      begin
         for i:=(k-1)* N div 4+1 to k*N div 4-1 do
            for j:=i+1 to k*N div 4 do
               writeln(fi,x[i],' ',x[j]);
      end;
   (* Cho so canh noi lien thong *)
   for i:=1 to 3 do
      begin
         socanh:=random(5)+1;
         writeln(socanh);
         for k:=1 to socanh do
            begin
               repeat
                  d[k]:=x[random(N div 4)+1+(i-1)*N div 4];
                  c[k]:=x[random(N div 4)+1+i*N div 4];
               until chuaco(k);
               writeln(fi,d[k],' ',c[k]);
            end;
      end;
   close(fi);
end;

BEGIN
   clrscr;
   randomize;
   Taodl;
   Inkq;
END.