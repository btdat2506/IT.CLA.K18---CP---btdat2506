const
   tfi                  =       'TOMAU.INP';
   tfo                  =       'TOMAU.OUT';
   maxN                 =       101;

var
   fi, fo               :       text;
   M,N                  :       integer;
   a                    :       array[1..maxN,1..maxN] of byte;

   bac                  :       array[1..2*maxN] of integer;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         for j:=1 to N do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
end;

function DinhBacLe: integer;
var i: integer;
begin
   for i:=1 to M+N do
      if odd(bac[i]) then
         begin
            DinhBacLe:=i;
            exit;
         end;
   DinhBacLe:=0;
end;

function Next(u: integer): integer;
var v: integer;
begin
   if u<=M then
      begin
         for v:=1 to N do
            if a[u,v]=0 then
                begin
                   Next:=v+M;
                   exit;
                end;
      end
   else
      begin
         for v:=1 to M do
            if a[v,u-M]=0 then
               begin
                  Next:=v;
                  exit;
               end;
      end;
   Next:=0;
end;

procedure ToMau(xp: integer);
var u,v,color: integer;
begin
   color:=2;
   u:=xp;
   repeat
      v:=Next(u);
      if v>0 then
         begin
            if u<=M then a[u,v-M]:=color else a[v,u-M]:=color;
            bac[u]:=bac[u]-1;
            bac[v]:=bac[v]-1;
            u:=v;
            color:=5-color;
         end;
   until v=0;
end;

function DinhConCanh: integer;
var i: integer;
begin
   for i:=1 to M+N do
      if bac[i]>0 then
         begin
            DinhConCanh:=i;
            exit;
         end;
   DinhConCanh:=0;
end;

procedure Solve;
var i,j,u: integer;
begin
   for i:=1 to  M do
      begin
         bac[i]:=0;
         for j:=1 to N do
            bac[i]:=bac[i]+(1-a[i,j]);
      end;
   for i:=M+1 to M+N do
      begin
         u:=i-M;
         bac[i]:=0;
         for j:=1 to M do
            bac[i]:=bac[i]+(1-a[j,u]);
      end;

   {Tim cac duong xuat phat tu dinh le}
   repeat
      u:=DinhBacLe;
      if u>0 then ToMau(u);
   until u=0;
   {Tim cac duong xuat phat tu dinh bac chan}
   repeat
      u:=DinhConCanh;
      if u>0 then ToMau(u);
   until u=0;
end;

procedure Inkq;
var i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   for i:=1 to M do
      begin
         for j:=1 to N do
            case a[i,j] of
               1: write(fo,'D');
               2: write(fo,'X');
               3: write(fo,'V');
            end;
         writeln(fo);
      end;
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.