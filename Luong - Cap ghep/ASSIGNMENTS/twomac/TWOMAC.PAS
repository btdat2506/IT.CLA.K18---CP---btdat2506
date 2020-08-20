const
   maxN                 =       101;
   tfi                  =       'TWOMAC.INP';
   tfo                  =       'TWOMAC.OUT';

var
   a                    :       array[1..maxN,1..maxN] of byte;
   N                    :       integer;
   fi, fo               :       text;

   LT                   :       array[1..maxN] of integer;
   x                    :       array[1..maxN] of integer;
   count                :       integer;

   Deg                  :       array[1..maxN] of integer;

   sl                   :       integer;
   x1, x2               :       array[1..maxN] of integer;
   cx                   :       array[1..maxN] of boolean;

procedure Docdl;
var i, u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         read(fi,u);
         if u=0 then
            begin
               readln(fi);
               continue;
            end;
         a[u,i]:=1;
         while not seekeoln(fi) do
            begin
               read(fi,u);
               a[u,i]:=1;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure Loang(u: integer);
var v: integer;
begin
   LT[u]:=1;
   for v:=1 to N do
      if (a[u,v]=1) and (LT[v]=0) then Loang(v);
   inc(count);
   x[N-count+1]:=u;
end;

procedure SXTopo;
var i: integer;
begin
   for i:=1 to N do LT[i]:=0;
   count:=0;
   for i:=1 to N do
      if LT[i]=0 then
         Loang(i);
end;

function La(i: integer): boolean;
var j: integer;
begin
   la:=false;
   if not cx[i] then exit;
   for j:=1 to N do
      if cx[j] and (a[i,j]=1) then exit;
   la:=true;
end;

procedure Tim(var k,l: integer);
var i, max1, max2: integer;
begin
   max1:=0;
   max2:=0;
   l:=0; k:=0;
   for i:=1 to N do
      if La(i) then
         begin
            if deg[i]>=max1 then
               begin
                  max2:=max1;
                  l:=k;
                  max1:=deg[i];
                  k:=i;
               end
            else if deg[i]>max2 then
               begin
                  max2:=deg[i];
                  l:=i;
               end;
         end;
end;

procedure Xep;
var i,j,k,l: integer;
begin
   SXTopo;
   for i:=1 to N do
      begin
         k:=x[i];
         deg[k]:=1;
         for j:=i-1 downto 1 do
            begin
               l:=x[j];
               if (a[l,k]=1) and (deg[k]<deg[l]+1) then
                  deg[k]:=deg[l]+1;
            end;
      end;
   sl:=0;
   count:=N;
   for i:=1 to N do cx[i]:=true;
   repeat
      Tim(k,l);
      inc(sl);
      x1[sl]:=k;
      cx[k]:=false;
      x2[sl]:=l;
      if l>0 then cx[l]:=false;
      count:=count-1;
      if l>0 then count:=count-1;
   until count=0;
end;

procedure Inkq;
var i, k, l: integer;
    kq: array[1..maxN, 1..2] of integer;
begin
   (* chuan bi ket qua de in *)
   for i:=1 to sl do
      begin
         k:=x1[i]; l:=x2[i];
         if k>0 then
            begin
               kq[k,1]:=1;
               kq[k,2]:=sl-i;
            end;
         if l>0 then
            begin
               kq[l,1]:=2;
               kq[l,2]:=sl-i;
            end;
      end;
   (* in ra file *)
   assign(fo,tfo); rewrite(fo);
   writeln(fo,sl);
   for i:=1 to N do
      writeln(fo,kq[i,1],' ',kq[i,2]);
   close(fo);
end;

BEGIN
   Docdl;
   Xep;
   Inkq;
END.