{**************************************************************************
Program    :    Nang suat day chuyen (NANGSUAT)
Date       :    10-3-2007
Group      :    Luong - Cap ghep
Langues    :    Free Pascal
**************************************************************************}

uses crt;

const
   tfi                  =       'NANGSUAT.INP';
   tfo                  =       'NANGSUAT.OUT';
   maxN                 =       200;
   NN                   =       200;

type
   mang                 =       array[1..maxN] of integer;

var
   fi,fo                :       text;
   N                    :       integer;
   a                    :       array[1..maxN] of ^mang;
   Amin,Amax            :       integer;
   T                    :       LongInt;
   ft,fp                :       mang;
   mf                   :       integer;
   Q                    :       mang;
   qf,ql                :       integer;
   Tr                   :       mang;
   ktt,ktp              :       integer;

procedure SinhDL;
var ch: char;
    i,j: integer;
begin
   clrscr;
   writeln('Ban co tao file ',tfi,' C/K)?');
   repeat ch:=readkey until upcase(ch) in ['C','K'];
   if upcase(ch)='K' then exit;
   randomize;
   N:=NN;
   for i:=1 to N do
      for j:=1 to N do a[i]^[j]:=random(20000)+1;
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N);
   for i:=1 to N do
      begin
         for j:=1 to N do write(fi,a[i]^[j],' ');
         writeln(fi);
      end;
   close(fi);
end;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         for j:=1 to N do read(fi,a[i]^[j]);
         readln(fi);
      end;
   close(fi);
end;

procedure CapPhat;
var i: integer;
begin
   for i:=1 to maxN do new(a[i]);
end;

procedure GiaiPhong;
var i: integer;
begin
   for i:=1 to maxN do dispose(a[i]);
end;

procedure ChuanBi;
var i,j: integer;
begin
   Amin:=a[1]^[1]; Amax:=a[1]^[1];
   for i:=1 to N do
      for j:=1 to N do
         begin
            if Amin>a[i]^[j] then Amin:=a[i]^[j];
            if Amax<a[i]^[j] then Amax:=a[i]^[j];
         end;
end;

procedure InitFlow;
begin
   fillchar(ft,sizeof(ft),0);
   fillchar(fp,sizeof(fp),0);
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
var i,u,v,w: integer;
begin
   InitQ;
   ok:=true;
   fillchar(Tr,sizeof(Tr),0);
   for i:=1 to N do
      if ft[i]=0 then
         begin
            Put(i);
            Tr[i]:=-1;
         end;
   while not Qempty do
      begin
         u:=Get;
         for v:=1 to N do
            if (a[u]^[v]>=T) then
               begin
                  if fp[v]=0 then
                     begin
                        ktp:=v;
                        ktt:=u;
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

procedure IncFlow;
var u,v,v1: integer;
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
    i: integer;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   mf:=0;
   for i:=1 to N do
      if ft[i]<>0 then inc(mf);
end;

procedure GhepSlow;
var Dau,Cuoi: LongInt;
begin
   Dau:=Amin;
   Cuoi:=Amax+1;
   repeat
      T:=(Dau+cuoi) div 2;
      GhepMax;
      if mf<n then Cuoi:=T else Dau:=T;
   until Cuoi-dau=1;
   T:=Dau;
   GhepMax;
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,T);
   for i:=1 to N do writeln(fo,ft[i]);
   close(fo);
end;

BEGIN
   CapPhat;
   {SinhDL;}
   Docdl;
   ChuanBi;
   GhepSlow;
   Inkq;
   GiaiPhong;
END.
