{$R-}
const
   maxN                 =       100;
   tfi                  =       'MONHOC.INP';
   tfo                  =       'MONHOC.OUT';

var
   Gr                   :       array[1..maxN,1..maxN] of byte;
   a                    :       array[1..maxN] of integer;
   fi, fo               :       text;

   M,N                  :       integer;

   T,Lim                :       integer;

   Ft,Fp                :       array[1..maxN] of integer;
   Fl                   :       array[1..maxN,1..maxN] of byte;
   Mf                   :       integer;

   Q                    :       array[1..2*maxN] of integer;
   qf,ql                :       integer;

   Tr                   :       array[1..2*maxN] of integer;

   kt                   :       integer;

   good                 :       boolean;

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
var i,j: integer;
begin
   fillchar(Gr,sizeof(Gr),0);
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         read(fi,a[i]);
         while not seekeoln(fi) do
            begin
               read(fi,j);
               Gr[i,j]:=1;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure InitFlow;
begin
   Fillchar(Ft,sizeof(Ft),0);
   Fillchar(Fl,sizeof(Fl),0);
   Fillchar(Fp,sizeof(Fp),0);
end;

procedure FindPath(var ok: boolean);
var i,u,v: integer;
begin
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   for i:=1 to M do
      if Ft[i]<a[i] then
         begin
            Put(i);
            Tr[i]:=M+N+1;
         end;
   ok:=true;
   while not Qempty do
      begin
         u:=Get;
         if u>M then
            begin
               if Fp[u-M]<Lim then
                  begin
                     kt:=u;
                     exit;
                  end;
               for v:=1 to M do
                  if (Gr[v,u-M]=1) and (Fl[v,u-M]=1) and (Tr[v]=0) then
                     begin
                        Put(v);
                        Tr[v]:=-u; (* cung nguoc *)
                     end;
            end
         else
            begin
               for v:=1 to N do
                  if (Gr[u,v]=1) and (Fl[u,v]=0) and (Tr[v+M]=0) then
                     begin
                        Put(v+M);
                        Tr[v+M]:=u;
                     end;
            end;
      end;
   ok:=false;
end;

procedure IncFlow;
var u,v: integer;
begin
   v:=Kt;
   Fp[v-M]:=Fp[v-M]+1;
   repeat
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            Fl[v,u-M]:=0;
         end
      else if u<M+N+1 then Fl[u,v-M]:=1;
      if u<>M+N+1 then v:=u;
   until u=M+N+1;
   Ft[v]:=Ft[v]+1;
end;

procedure MaxFlow;
var ok: boolean;
    i: integer;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   Mf:=0;
   for i:=1 to M do Mf:=Mf+Ft[i];
end;

procedure Solve;
var i, dau, cuoi: integer;
begin
   T:=0;
   for i:=1 to M do T:=T+a[i];
   Lim:=N;
   MaxFlow;
   if Mf<T then
      begin
         good:=false;
         exit;
      end;
   good:=true;
   dau:=0;
   cuoi:=N;
   repeat
      Lim:=(dau+cuoi) div 2;
      MaxFlow;
      if Mf=T then cuoi:=Lim else Dau:=Lim;
   until cuoi-dau=1;
   Lim:=cuoi;
   MaxFlow;
end;

procedure Inkq;
var dem,i,k: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if not good then writeln(fo,-1) else
      begin
         writeln(fo,Lim);
         for i:=1 to N do
            begin
               dem:=0;
               for k:=1 to M do
                  if Fl[k,i]=1 then
                     begin
                        dem:=dem+1;
                        write(fo,k,' ');
                     end;
               if dem=0 then write(fo,0);
               writeln(fo);
            end;
      end;
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.