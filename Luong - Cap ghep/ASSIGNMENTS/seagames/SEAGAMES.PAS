{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt;

const
   tfi='SEAGAMES.INP';
   tfo='SEAGAMES.OUT';
   NN=100;
   maxN=100;

var
   fi,fo: text;
   N,K: integer;
   c: array[1..2*maxN] of integer;
   a: array[1..maxN,1..maxN] of LongInt;
   Lmin: LongInt;
   ft,fp: array[1..maxN] of integer;
   Q: array[1..maxN] of integer;
   qf,ql: integer;
   Tr: array[1..maxN] of integer;
   ktt,ktp: integer;
   mf: integer;
   x: array[1..2*maxN] of integer;

procedure Sinhdl;
var ch: char;
    i,j,tg: integer;
begin
   clrscr;
   writeln('Ban co tao file ',tfi,' (C/K)?');
   repeat ch:=readkey until upcase(ch) in ['C','K'];
   if upcase(ch)='K' then exit;
   randomize;
   N:=NN;
   K:=N+N;
   for i:=1 to N do c[i]:=i;
   for i:=N+1 to K do c[i]:=random(N)+1;
   for i:=K downto 2 do
      begin
         j:=random(i)+1;
         tg:=c[i];
         c[i]:=c[j];
         c[j]:=tg;
      end;
   for i:=1 to N do
      for j:=1 to N do a[i,j]:=random(10000)+20000;
   assign(fi,tfi); rewrite(fi);
   writeln(fi,N,' ',K);
   for i:=1 to K do write(fi,c[i],' ');
   writeln(fi);
   for i:=1 to N do
      begin
         for j:=1 to N do write(fi,a[i,j],' ');
         writeln(fi);
      end;
   close(fi);
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

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,K);
   for i:=1 to K do read(fi,c[i]);
   for i:=1 to N do
      for j:=1 to N do read(fi,a[i,j]);
   close(fi);
end;

procedure InitFlow;
begin
   fillchar(ft,sizeof(ft),0);
   fillchar(fp,sizeof(fp),0);
end;

procedure FindPath(var ok: boolean);
var u,v,w: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   for u:=1 to N do
      if ft[u]=0 then
         begin
            Put(u);
            Tr[u]:=-1;
         end;
   while not Qempty do
      begin
         u:=Get;
         for v:=1 to N do
           if (a[v,u]<=Lmin) then
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
      u:=Tr[u];
      v:=v1;
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

procedure Ghep;
var Dau,cuoi: LongInt;
    i,j: integer;
begin
   Dau:=a[1,1];
   Cuoi:=a[1,1];
   for i:=1 to N do
      for j:=1 to N do
         begin
            if dau>a[i,j] then dau:=a[i,j];
            if cuoi<a[i,j] then cuoi:=a[i,j];
         end;
   dau:=dau-1;
   repeat
      Lmin:=(dau+cuoi) div 2;
      GhepMax;
      if mf=N then cuoi:=Lmin
              else dau:=Lmin;
   until cuoi=dau+1;
   Lmin:=cuoi;
   GhepMax;
end;

procedure Inkq;
var i: integer;
begin
   for i:=1 to K do x[i]:=fp[c[i]];
   assign(fo,tfo); rewrite(fo);
   for i:=1 to K do write(fo,x[i],' ');
   close(fo);
end;

BEGIN
   {Sinhdl;}
   Docdl;
   Ghep;
   Inkq;
END.
