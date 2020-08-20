{*********************************************************************
Program   : TRU BAT GIOI
Date      : 23-08-2005
Thuat toan: Cap ghep
*********************************************************************}
uses crt;

const
   tfi                          =       'BG.IN0987654321P';
   tfo                          =       'BG.OU0987654321T';
   maxMN                        =       100;

type
   mang1                        =       array[1..maxMN] of longint;
   mang2                        =       array[1..maxMN,1..maxMN] of byte;
   mang3                        =       array[1..maxMN] of integer;
   mang4                        =       array[1..2*maxMN] of longint;

var
   fi, fo                       :       text;
   N,M                          :       integer;
   x1,y1,x2,y2                  :       mang1;

   a                            :       mang2;
   ft,fp                        :       mang3;
   Tr                           :       mang3;
   Q                            :       mang3;
   qf,ql                        :       integer;
   ktt,ktp                      :       integer;

   K                            :       integer;
   x,y                          :       mang4;

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
var i: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,M);
   for i:=1 to N do read(fi,x1[i],y1[i]);
   for i:=1 to M do read(fi,x2[i],y2[i]);
   close(fi);
end;

function kc(u1,v1,u2,v2: longint): real;
begin
   kc:=sqrt(sqr(u2-u1)+sqr(v2-v1))
end;

function ThamDuoc(i,j: integer): boolean;
var d,d1,d2: real;
begin
   d:=Kc(x1[i],y1[i],x1[i+1],y1[i+1]);
   d1:=Kc(x1[i],y1[i],x2[j],y2[j]);
   d2:=Kc(x2[j],y2[j],x1[i+1],y1[i+1]);
   ThamDuoc:=(d1+d2<=2*d)
end;

procedure XDDoThi;
var i,j: integer;
begin
   Fillchar(a,sizeof(a),0);
   for i:=1 to N-1 do
     for j:=1 to M do
        if ThamDuoc(i,j) then a[i,j]:=1;
end;

procedure InitFlow;
begin
   Fillchar(ft,sizeof(ft),0);
   Fillchar(fp,sizeof(fp),0);
end;

procedure FindPath(var ok: boolean);
var i,u,v,w: integer;
begin
   ok:=true;
   Fillchar(Tr,sizeof(Tr),0);
   InitQ;
   for i:=1 to N-1 do
      if Ft[i]=0 then
         begin
            Put(i);
            Tr[i]:=-1;
         end;
   while not Qempty do
      begin
         u:=Get;
         for v:=1 to M do
            if (a[u,v]=1) and (ft[u]<>v) then
               begin
                  if fp[v]=0 then
                     begin
                        ktt:=u;
                        ktp:=v;
                        exit;
                     end;
                  w:=fp[v];
                  if tr[w]=0 then
                     begin
                        Put(w);
                        tr[w]:=u;
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

procedure LapDuong;
var i,j: integer;
begin
   K:=1;
   x[1]:=x1[1]; y[1]:=y1[1];
   for i:=1 to N-1 do
      begin
         if Ft[i]>0 then
            begin
               j:=Ft[i];
               inc(K);
               x[k]:=x2[j]; y[k]:=y2[j];
            end;
         inc(k);
         x[k]:=x1[i+1];
         y[k]:=y1[i+1];
      end;
end;

procedure GhepMax;
var ok: boolean;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   LapDuong;
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,K);
   for i:=1 to K do
      write(fo,x[i],' ',y[i],' ');
   close(fo);
end;

BEGIN
   Docdl;
   XDDoThi;
   GhepMax;
   Inkq;
END.