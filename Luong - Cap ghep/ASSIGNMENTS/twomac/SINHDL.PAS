const
   N            =100;
   tfi='TWOMAC.IN09874321';

var
   a: array[1..100,1..100] of byte;
   x: array[1..100] of integer;

   fi: text;

procedure taodl;
var i,k,tg,j: integer;
begin
   fillchar(a,sizeof(a),0);
   for i:=1 to N do x[i]:=i;
   for i:=N downto 2 do
      begin
         k:=random(i-1)+1;
         tg:=x[k];
         x[k]:=x[i];
         x[i]:=tg;
      end;
   for i:=2 to N do
      for j:=i-1 downto 1 do
         begin
            k:=random(2);
            if k=1 then a[x[j],x[i]]:=1;
         end;
end;

procedure Inkq;
var i,dem,j: integer;
begin
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N);
   for i:=1 to N do
      begin
         dem:=0;
         for j:=1 to N do
            if a[j,i]=1 then
               begin
                  write(fi,j,' ');
                  inc(dem);
               end;
         if dem=0 then write(fi,0);
         writeln(fi);
      end;
   close(fi);
end;

BEGIN
   randomize;
   Taodl;
   inkq;
END.