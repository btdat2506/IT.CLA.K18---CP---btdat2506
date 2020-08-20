{$B-,R-,Q-}
const
   tfi                          =       'SHOT.INP';
   tfo                          =       'SHOT.OUT';
   maxN                         =       1000;

var
   fi, fo                       :       text;
   M,N                          :       integer;
   Gr                           :       array[1..2,1..maxN] of integer;

   Ft,Fp                        :       array[1..maxN] of integer;
   mf                           :       integer;

   Q                            :       array[1..maxN] of integer;
   qf,ql                        :       integer;
   Tr                           :       array[1..maxN] of integer;
   ktt,ktp                      :       integer;

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

procedure Docdl;
var i,j,u: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         for j:=1 to N do
            begin
               read(fi,u);
               if u=0 then
                  if Gr[1,j]=0 then Gr[1,j]:=i else Gr[2,j]:=i;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure InitFlow;
var i: integer;
begin
   for i:=1 to N do Ft[i]:=0;
   for i:=1 to M do Fp[i]:=0;
end;

procedure FindPath(var ok: boolean);
var i,u,v,w,k: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to N do Tr[i]:=0;
   for i:=1 to N do
      if Ft[i]=0 then
         begin
            Put(i);
            Tr[i]:=-1;
         end;
   while not Qempty do
      begin
         u:=Get;
         for k:=1 to 2 do
            begin
               v:=Gr[k,u];
               if Fp[v]=0 then
                  begin
                     Ktt:=u;
                     Ktp:=v;
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
var u,v, v1: integer;
begin
   v:=ktp;
   u:=ktt;
   repeat
      v1:=Ft[u];
      Ft[u]:=v;
      Fp[v]:=u;
      u:=tr[u];
      v:=v1;
   until u=-1;
end;

procedure Solve;
var ok: boolean;
    i: integer;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok Then IncFlow;
   until not ok;
   mf:=0;
   for i:=1 to N do
      if Ft[i]>0 then inc(mf);
   if mf<M then exit;
   for i:=1 to N do
      if Ft[i]=0 then Ft[i]:=Gr[1,i];
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if mf<M then writeln(fo,'NO') else
      begin
         writeln(fo,'YES');
         for i:=1 to N do writeln(fo,Ft[i]);
      end;
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.