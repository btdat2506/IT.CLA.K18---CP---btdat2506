{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R-,S+,T-,V+,X+}
{$M 16384,0,655360}


const
   tfi                  =       'SOMNHAT.INP';
   tfo                  =       'SOMNHAT.OUT';
   maxN                 =       200;

type
   mang=array[1..maxN] of longint;

var
   Gr                   :       array[1..maxN] of ^mang;
   fi,fo                :       text;
   N,M,K                :       longint;
   yc                   :       array[1..maxN,1..2] of longint;
   Lim                  :       longint;
   ft,fp                :       array[1..maxN] of longint;
   mf                   :       longint;
   Q                    :       array[1..maxN] of longint;
   qf,ql                :       longint;
   Tr                   :       array[1..maxN] of longint;
   ktt,ktp              :       longint;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(u: longint);
begin
   q[ql]:=u;
   inc(ql);
end;

function Get: longint;
begin
   Get:=q[qf];
   inc(qf);
end;

function Qempty: boolean;
begin
   Qempty:=(qf=ql);
end;

procedure Laprap(nv,u,t1,t2,t3: longint);
var i: longint;
begin
   for i:=1 to N do
      if yc[i,1]=u then
         begin
            case yc[i,2] of
               1: Gr[i]^[nv]:=t1;
               2: Gr[i]^[nv]:=t2;
               3: Gr[i]^[nv]:=t3;
            end;
         end;
end;

procedure Docdl;
var i,j,r,u,t1,t2,t3: longint;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,M,K);
   for i:=1 to N do
      for j:=1 to M do Gr[i]^[j]:=-1;
   for i:=1 to N do read(fi,yc[i,1],yc[i,2]);
   for i:=1 to M do
      begin
         read(fi,r);
         for j:=1 to r do
            begin
               read(fi,u,t1,t2,t3);
               LapRap(i,u,t1,t2,t3);
            end;
      end;
   close(fi);
end;

procedure InitFlow;
begin
   fillchar(ft,sizeof(ft),0);
   fillchar(fp,sizeof(fp),0);
end;

procedure TimDuong(var ok: boolean);
var u,v,w: longint;
begin
   ok:=true;
   InitQ;
   Fillchar(Tr,sizeof(Tr),0);
   for u:=1 to N do
      if ft[u]=0 then
         begin
            Put(u);
            Tr[u]:=-1;
         end;
   while not Qempty do
      begin
         u:=Get;
         for v:=1 to M do
            if (Gr[u]^[v]<>-1) and (Gr[u]^[v]<=Lim) then
               begin
                  if fp[v]=0 then
                     begin
                        ktt:=u;
                        ktp:=v;
                        exit;
                     end;
                  w:=fp[v];
                  if Tr[w]=0 then
                     begin
                        Put(w);
                        Tr[w]:=u;
                     end;
               end;
      end;
   ok:=false;
end;

procedure TangCap;
var u,v,v1: longint;
begin
   v:=ktp;
   u:=ktt;
   repeat
      v1:=ft[u];
      ft[u]:=v;
      fp[v]:=u;
      v:=v1;
      u:=Tr[u];
   until u=-1;
end;

procedure GhepMax;
var ok: boolean;
    i: longint;
begin
   InitFlow;
   repeat
      TimDuong(ok);
      if ok Then TangCap;
   until not ok;
   mf:=0;
   for i:=1 to N do
      if ft[i]<>0 then inc(mf);
end;

procedure Solve;
var i,j,Dau,cuoi: longint;
begin
   Dau:=-1; Cuoi:=-1;
   for i:=1 to N do
      for j:=1 to M do
         if Gr[i]^[j]<>-1 then
            if Gr[i]^[j]>Cuoi then Cuoi:=Gr[i]^[j];
   Lim:=Cuoi;
   GhepMax;
   if mf=N then
      begin
         repeat
            Lim:=(Dau+Cuoi) div 2;
            GhepMax;
            if mf=N then Cuoi:=Lim else Dau:=Lim
         until Dau=Cuoi-1;
         Lim:=Cuoi;
         GhepMax;
      end
   else Lim:=-1;
end;

procedure Inkq;
var i: longint;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,Lim);
   if Lim<>-1 then
      begin
         for i:=1 to N do writeln(fo,ft[i]);
      end;
   close(fo);
end;

procedure CapPhat;
var i: longint;
begin
   for i:=1 to maxN do new(Gr[i]);
end;

procedure GiaiPhong;
var i: longint;
begin
   for i:=1 to maxN do Dispose(Gr[i]);
end;

BEGIN
   CapPhat;
   Docdl;
   Solve;
   Inkq;
   GiaiPhong;
END.