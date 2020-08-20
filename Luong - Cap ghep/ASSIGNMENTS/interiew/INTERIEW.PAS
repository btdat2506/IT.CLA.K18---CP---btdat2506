{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}

uses crt;

const
   tfi                  =       'INTERIEW.INP';
   tfo                  =       'INTERIEW.OUT';
   maxN                 =       30;
   maxM                 =       1500;
   maxP                 =       60;
   Unseen               =       maxN+maxM+1;

type
   Alphabet             =       set of 'A'..'Z';
   Mang1                =       array[1..maxN,1..maxM] of byte;

var
   fi,fo                :       text;
   N,M                  :       integer;
   a                    :       array[1..maxN,1..maxM] of byte;
   count                :       integer;
   ft                   :       array[1..maxN] of integer;
   fp                   :       array[1..maxM] of integer;
   fl                   :       ^mang1;
   Q                    :       array[1..maxN+maxM] of integer;
   qf,ql                :       integer;
   Tr                   :       array[1..maxN+maxM] of integer;
   Lim                  :       integer;
   kt                   :       integer;
   mf                   :       integer;

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
    yc: array[1..maxN] of Alphabet;
    kn: array[1..maxM] of Alphabet;
    ch: char;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         yc[i]:=[];
         while not seekeoln(fi) do
            begin
               read(fi,ch);
               yc[i]:=yc[i]+[ch];
            end;
         readln(fi);
      end;
   readln(fi,M);
   for i:=1 to M do
      begin
         kn[i]:=[];
         while not seekeoln(fi) do
            begin
               read(fi,ch);
               kn[i]:=kn[i]+[ch];
            end;
         READLN(FI);
      end;
   close(fi);
   for i:=1 to N do
      for j:=1 to M do
         if (yc[i] <= kn[j]) then a[i,j]:=1 else a[i,j]:=0;
end;

procedure InitFlow;
var i,j: integer;
begin
   for i:=1 to N do ft[i]:=0;
   for i:=1 to N do
      for j:=1 to M do fl^[i,j]:=0;
   for i:=1 to M do fp[i]:=0;
end;

procedure TimDuong(var ok: boolean);
var i,u,v: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to N+M do Tr[i]:=0;
   for i:=1 to N do
      if Ft[i]<Lim then
         begin
            Put(i);
            Tr[i]:=Unseen;
         end;
   while not Qempty do
      begin
         u:=Get;
         if u<=N then {chi co cung xuoi}
         begin
            for v:=1 to M do
               if (a[u,v]=1) and (fl^[u,v]=0) and (Tr[v+N]=0) then
                  begin
                     Put(v+N);
                     Tr[v+N]:=u;
                  end
         end
         else {ben phai}
            begin
               if fp[u-N]=0 then
                  begin
                     kt:=u;
                     exit;
                  end;
               v:=fp[u-N];
               if Tr[v]=0 then
                  begin
                     Put(v);
                     Tr[v]:=-u;
                  end;
            end;
      end;
   ok:=false;
end;

procedure IncFlow;
var u,v: integer;
begin
   v:=kt;
   repeat
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            Fl^[v,u-N]:=0;
            Fp[u-N]:=0;
         end
      else if u<>Unseen then
         begin
            Fl^[u,v-N]:=1;
            fp[v-N]:=u;
         end;
      v:=u;
   until Tr[v]=Unseen;
   ft[v]:=ft[v]+1;
end;

procedure MaxFlow;
var ok: boolean;
    i: integer;
begin
   InitFlow;
   repeat
      TimDuong(ok);
      if ok then IncFlow;
   until not ok;
   mf:=0;
   for i:=1 to N do
      mf:=mf+ft[i];
end;

procedure FastFlow;
var dau,cuoi: longint;
begin
   dau:=0;
   cuoi:=maxP;
   repeat
      Lim:=(Dau+Cuoi) div 2;
      MaxFlow;
      if mf=count then cuoi:=lim else dau:=lim;
   until cuoi=dau+1;
   Lim:=cuoi;
   MaxFlow;
end;

procedure Solve;
var i: integer;
begin
   Lim:=maxP;
   MaxFlow;
   count:=mf;
   FastFlow;
end;

procedure Inkq;
var dem,i,j: integer;
begin
   dem:=0;
   for i:=1 to N do
      if ft[i]>0 then inc(dem);
   assign(fo,tfo); rewrite(fo);
   writeln(fo,dem);
   for i:=1 to N do
      if ft[i]>0 then
         begin
            write(fo,i,' ',ft[i],' ');
            for j:=1 to M do
               if fl^[i,j]=1 then write(fo,j,' ');
            writeln(fo);
         end;
   close(fo);
end;

BEGIN
   New(fl);
   Docdl;
   Solve;
   Inkq;
   dispose(fl);
END.