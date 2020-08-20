{$R-}
const
   tfi                  =       'EXHIBIT.INP';
   tfo                  =       'EXHIBIT.OUT';
   maxN                 =       200;

type
   mang                 =       array[1..maxN] of byte;

var
   fi, fo               :       text;
   M,N                  :       integer;
   a                    :       array[1..maxN,1..maxN] of byte;
   Gr                   :       array[1..maxN] of ^mang;

   Ft, Fp               :       array[1..maxN] of integer;

   Q                    :       array[1..maxN] of integer;
   qf,ql                :       integer;

   Tr                   :       array[1..maxN] of integer;

   ktt, ktp             :       integer;

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

procedure InitFlow;
begin
   fillchar(Ft,sizeof(Ft),0);
   fillchar(Fp,sizeof(Fp),0);
end;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(u: integer);
begin
   q[ql]:=u;
   inc(ql);
end;

function Get: integer;
begin
   Get:=q[qf];
   inc(qf);
end;

function Qempty: boolean;
begin
   Qempty:=(qf=ql);
end;

procedure FindPath(var ok: boolean);
var i, u, v, w: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to N do Tr[i]:=0;
   for i:=1 to N do
      if Ft[i]=0 then
         begin
            Tr[i]:=-1;
            Put(i);
         end;
   while not Qempty do
      begin
         u:=Get;
         for v:=1 to N do
           if (Gr[u]^[v]=1) then
               begin
                  if Fp[v]=0 then
                     begin
                        ktt:=u;
                        ktp:=v;
                        exit;
                     end;
                  w:=Fp[v];
                  if Tr[w]=0 then
                     begin
                        Put(w);
                        Tr[w]:=u;
                     end;
               end;
      end;
   ok:=false;
end;

procedure IncFlow;
var u,v,v1: integer;
begin
   v:=ktp;
   u:=ktt;
   repeat
      v1:=Ft[u];
      Ft[u]:=v;
      Fp[v]:=u;
      u:=Tr[u];
      v:=v1;
   until u=-1;
end;

procedure ThemHang(i: integer);
var ok: boolean;
    k: integer;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   for k:=1 to N do
      a[i,k]:=Fp[k];
end;

procedure Tinh;
var i,j: integer;
begin
   {Xay dung do thi hai phia}
   for i:=1 to N do
      for j:=1 to N do Gr[i]^[j]:=1;
   for i:=1 to M do
      for j:=1 to N do
         Gr[a[i,j]]^[j]:=0;
   for i:=M+1 to N do
      begin
         ThemHang(i);
         for j:=1 to N do
            Gr[a[i,j]]^[j]:=0;
      end;
end;

procedure Inkq;
var i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,N-M);
   for i:=M+1 to N do
      begin
         for j:=1 to N do write(fo,a[i,j],' ');
         writeln(fo);
      end;
   close(fo);
end;

procedure CapPhat;
var i: integer;
begin
   for i:=1 to maxN do new(Gr[i]);
end;

BEGIN
   CapPhat;
   Docdl;
   Tinh;
   Inkq;
END.