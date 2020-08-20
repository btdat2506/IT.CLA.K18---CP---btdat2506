{*********************************************************************
* Program      :  NANG CAP MANG MAY TINH                             *
* Date         :  07-01-2006                                         *
* Group        :  Luong va Cap ghep                                  *
*********************************************************************}
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R-,S-,T-,V+,X+,Y+}
{$M 16384,0,655360}
const
   tfi                  =       'NANGCAP.INP';
   tfo                  =       'NANGCAP.OUT';
   maxN                 =       201;
   Unseen               =       2*maxn+1;

type
   mang1                =       array[1..maxN] of longint;
   mang2                =       array[1..maxN] of integer;
   mang3                =       array[1..2*maxN] of integer;

var
   fi, fo               :       text;
   N                    :       integer;
   s,t                  :       mang1;
   d                    :       array[1..maxN] of ^mang1;

   fs,ft                :       mang2;
   fl                   :       array[1..maxN] of ^mang2;

   Q                    :       mang3;
   qf,ql                :       integer;
   tr                   :       mang3;

   kt                   :       integer;

   solx                 :       integer;
   x                    :       mang2;

procedure CapPhat;
var i: integer;
begin
   for i:=1 to maxN do new(d[i]);
   for i:=1 to maxN do new(fl[i]);
end;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N);
   for i:=1 to N do read(fi,s[i]);
   for i:=1 to N do read(fi,t[i]);
   for i:=1 to N do
      for j:=1 to N do read(fi,d[i]^[j]);
   close(fi);
end;

procedure Floy;
var i,j,k: integer;
begin
   for k:=1 to N do
      for i:=1 to N do
         if (i<>k) then
            for j:=1 to N do
               if (j<>k) and (j<>i) and (d[i]^[j]>d[i]^[k]+d[k]^[j]) then
                   d[i]^[j]:=d[i]^[k]+d[k]^[j];

End;

procedure InitFlow;
var i: integer;
begin
   for i:=1 to N do fs[i]:=-1;
   for i:=1 to N do ft[i]:=-1;
   for i:=1 to N do
      fillchar(fl[i]^,sizeof(fl[i]^),0);
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

function ThongQua(u,v: integer): integer;
var ok: boolean;
begin
   ok:=(s[u]+t[u]+d[u]^[v]<=s[v]);
   if ok then ThongQua:=0 else ThongQua:=-Unseen;
end;

procedure FindPath(var ok: boolean);
var i,u,v,cc: integer;
begin
   ok:=true;
   InitQ;
   fillchar(tr,sizeof(tr),0);
   for i:=1 to n do
      if fs[i]<0 then
         begin
            Put(i);
            tr[i]:=Unseen;
         end;
   while not Qempty do
      begin
         u:=Get;
         if u<=N then
            begin
               {cung nguoc}
               for v:=1 to N do
               if v<>u then
                  begin
                     cc:=ThongQua(v,u);
                     if (cc>=fl[v]^[u]) and (Tr[v+N]=0) then
                        begin
                           Put(v+N);
                           Tr[v+N]:=-u;
                        end;
                  end;
            end
         else
            begin
               {dinh ket thuc}
               if ft[u-N]<0 then
                  begin
                     kt:=u;
                     exit;
                  end;
               {cung xuoi}
               for v:=1 to N do
               if v<>u-N then
                  begin
                     cc:=ThongQua(u-N,v);
                     if (cc>fl[u-N]^[v]) and (Tr[v]=0) then
                        begin
                           Put(v);
                           Tr[v]:=u;
                        end;
                  end;
            end;
      end;
   ok:=false;
end;

procedure IncFlow;
var u,v: integer;
begin
   u:=kt;
   inc(ft[u-N]);
   repeat
      v:=tr[u];
      if v<0 then
         begin
            v:=-v;
            dec(fl[u-n]^[v]);
         end
      else if v<Unseen then  inc(fl[v-N]^[u]);
      if v<Unseen then u:=v;
   until v=Unseen;
   inc(fs[u]);
end;

procedure Solve;
var ok: boolean;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
end;

procedure TimX(u: integer);
var v: integer;
    stop: boolean;
begin
   solx:=0;
   stop:=false;
   repeat
      inc(solx);
      x[solx]:=u;
      if ft[u]=0 then
         begin
            for v:=1 to N do
               if fl[u]^[v]=-1 then break;
            u:=v;
         end
      else stop:=true;
   until stop;
end;

procedure Inkq;
var mf,i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   mf:=0;
   for i:=1 to N do mf:=mf+fs[i];
   writeln(fo,abs(mf));
   for i:=1 to N do
      if fs[i]=-1 then
         begin
            TimX(i);
            write(fo,solx);
            for j:=1 to solx do write(fo,#32,x[j]);
            writeln(fo);
         end;
   close(fo);
end;

BEGIN
   CapPhat;
   Docdl;
   Floy;
   Solve;
   Inkq;
END.
