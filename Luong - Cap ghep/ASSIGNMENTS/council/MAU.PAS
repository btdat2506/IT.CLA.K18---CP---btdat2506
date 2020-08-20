{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
uses crt;

const
   tfi                  =       'COUNCIL.INP';
   tfo                  =       'COUNCIL.OUT';
   maxN                 =       100;
   maxK                 =       50;
   maxP                 =       50;
   maxQ                 =       maxP+2*maxN+maxK;
   maxD                 =       maxQ;
   Unseen               =       maxD+1;

var
   a                    :       array[1..maxN,1..maxK] of byte;
   DN                   :       array[1..maxN] of integer;
   max                  :       array[1..maxP] of integer;
   fi,fo                :       text;
   N,P,K                :       integer;

   fl                   :       array[1..maxP] of integer;
   fp                   :       array[1..maxP,1..maxN] of byte;
   fn                   :       array[1..maxN] of byte;
   fk                   :       array[1..maxN,1..maxK] of byte;
   fr                   :       array[1..maxK] of integer;
   mf                   :       integer;

   Q                    :       array[1..maxQ] of integer;
   qf,ql                :       integer;

   Tr                   :       array[1..maxD] of integer;

   kt                   :       integer;

   good                 :       boolean;

procedure Docdl;
var i,l,j,u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N,P,K);
   for i:=1 to N do
      begin
         read(fi,DN[i]);
         read(fi,l);
         for j:=1 to l do
            begin
               read(fi,u);
               a[i,u]:=1;
            end;
         readln(fi);
      end;
   for i:=1 to P do read(fi,max[i]);
   close(fi);
end;

procedure InitFlowFirst;
begin
   fillchar(fl,sizeof(fl),0);
   fillchar(fp,sizeof(fp),0);
   fillchar(fn,sizeof(fn),0);
   fillchar(fk,sizeof(fk),0);
   fillchar(fr,sizeof(fr),0);
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

procedure Loai1(u: integer);
var i: integer;
begin
   for i:=1 to N do
      if (DN[i]=u) and (fp[u,i]=0) and (Tr[i+p]=0) then
         begin
            Put(i+p);
            Tr[i+p]:=u;
         end;
end;

procedure Loai2(u: integer);
var v: integer;
begin
   if (fn[u-p]=0) and (Tr[u+N]=0) then
      begin
         Put(u+N);
         Tr[u+N]:=u;
      end;
   v:=DN[u-p];
   if (Tr[v]=0) and (fp[v,u-p]=1) then
      begin
         Put(v);
         Tr[v]:=-u;
      end;
end;

procedure Loai3(u: integer);
var i,j: integer;
begin
   i:=u-(p+n);
   for j:=1 to K do
      if (a[i,j]=1) and (fk[i,j]=0) and (Tr[j+(p+2*n)]=0) then
         begin
            Put(j+p+2*n);
            Tr[j+p+2*n]:=u;
         end;
   if (fn[i]=1) and (Tr[u-N]=0) then
      begin
         Put(u);
         Tr[u-N]:=-u;
      end;
end;

procedure Loai4(u: integer);
var i,j: integer;
begin
   j:=u-(p+2*n);
   for i:=1 to N do
      if (a[i,j]=1) and (fk[i,j]=1) and (Tr[p+n+i]=0) then
         begin
            Put(p+n+i);
            Tr[p+n+i]:=-u;
         end;
end;

procedure FindPathFirst(var ok: boolean);
var i,u: integer;
begin
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   for i:=1 to P do
      if fl[i]=0 then
         begin
            Put(i);
            Tr[i]:=Unseen;
         end;
   ok:=true;
   while not Qempty do
      begin
         u:=Get;
         if u<=p then Loai1(u) else
         if u<=p+n then Loai2(u) else
         if u<=p+2*n then Loai3(u) else
            begin
               if fr[u-(p+2*n)]=0 then
                  begin
                     kt:=u;
                     exit;
                  end;
               Loai4(u);
            end;
      end;
   ok:=false;
end;

procedure FindPath(var ok: boolean);
var i,u: integer;
begin
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   for i:=1 to P do
      if fl[i]<max[i] then
         begin
            Put(i);
            Tr[i]:=Unseen;
         end;
   ok:=true;
   while not Qempty do
      begin
         u:=Get;
         if u<=p then Loai1(u) else
         if u<=p+n then Loai2(u) else
         if u<=p+2*n then Loai3(u) else
            begin
               if fr[u-(p+2*n)]=0 then
                  begin
                     kt:=u;
                     exit;
                  end;
               Loai4(u);
            end;
      end;
   ok:=false;
end;


procedure Nguoc2(u,v: integer);
begin
   fp[u,v]:=0;
end;
procedure Nguoc3(u: integer);
begin
   fn[u]:=0;
end;
procedure Nguoc4(u,v: integer);
begin
   fk[u,v]:=0;
end;

procedure Xuoi1(u,v: integer);
begin
   fp[u,v]:=1;
end;
procedure Xuoi2(u: integer);
begin
   fn[u]:=1;
end;
procedure Xuoi3(u,v: integer);
begin
   fk[u,v]:=1;
end;

procedure IncFlow;
var u,v: integer;
begin
   v:=kt;
   fr[v-p-2*n]:=1;
   while Tr[v]<>Unseen do
      begin
         u:=Tr[v];
         if u<0 then
            begin
               u:=-u;
               if u<=p+n then nguoc2(v,u-p) else
               if u<=p+2*n then Nguoc3(u-p-n) else
                  Nguoc4(v-p-n,u-p-2*n);
            end
         else
           begin
              if u<=p then Xuoi1(u,v-p) else
              if u<=p+n then Xuoi2(u-p) else Xuoi3(u-p-n,v-p-2*n);
           end;
         v:=u;
      end;
   fl[v]:=fl[v]+1;
end;

procedure FirstFlow;
var ok: boolean;
    i: integer;
begin
   InitFlowFirst;
   repeat
      FindPathFirst(ok);
      if ok then IncFlow;
   until not ok;
   mf:=0;
   for i:=1 to p do
      mf:=mf+fl[i];
end;

procedure MaxFlow;
var ok: boolean;
    i: integer;
begin
   good:=false;
   if mf<p then exit;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   mf:=0;
   for i:=1 to K do
      mf:=mf+fr[i];
   if mf<k then exit;
   good:=true;
end;

procedure Inkq;
var i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if not good then writeln(fo,-1) else
      begin
         for j:=1 to K do
            for i:=1 to N do
               if fk[i,j]=1 then write(fo,i,' ');
      end;
   close(fo);
end;

BEGIN
   Docdl;
   FirstFlow;
   MaxFlow;
   Inkq;
END.