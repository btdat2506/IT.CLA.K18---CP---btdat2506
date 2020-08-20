const
   tfi                     =     'NASA.INP';
   tfo                     =     'NASA.OUT';
   maxN                    =     101;

var
   fi, fo                  :     text;
   N,M                     :     integer;
   a,b                     :     array[1..maxN] of longint;
   c                       :     array[1..maxN,1..maxN] of byte;

   Ft,Fp                   :     array[1..maxN] of longint;
   Fl                      :     array[1..maxN,1..maxN] of longint;
   mf                      :     longint;

   Q                       :     array[1..2*maxN] of integer;
   qf,ql                   :     integer;

   Tr                      :     array[1..2*maxN] of integer;
   Ep                      :     array[1..2*maxN] of longint;

   kt                      :     integer;

   slx, sly                :     integer;
   x,y                     :     array[1..maxN] of integer;

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
   readln(fi,N,M);
   for i:=1 to N do read(fi,a[i]);
   readln(fi);
   for i:=1 to M do read(fi,b[i]);
   readln(fi);
   for i:=1 to N do
      begin
         for j:=1 to M do read(fi,c[i,j]);
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
   ok:=true;
   InitQ;
   for i:=1 to N+M do Tr[i]:=0;
   for i:=1 to N do
      if Ft[i]<a[i] then
         begin
            Put(i);
            Tr[i]:=M+N+1;
            Ep[i]:=a[i]-Ft[i];
         end;
   while not Qempty do
      begin
         u:=Get;
         if u<=N then (* dinh ben trai *)
            begin
               for v:=1 to M do
                  if (c[u,v]=1) and (Tr[v+N]=0) then
                     begin
                        Put(v+N);
                        Tr[v+N]:=u;
                        Ep[v+N]:=Ep[u];
                     end;
            end
         else (* dinh ben phai *)
            begin
               if Fp[u-N]<b[u-N] then
                  begin
                     kt:=u;
                     if Ep[kt]>b[u-N]-Fp[u-N] then
                        Ep[kt]:=b[u-N]-Fp[u-N];
                     exit;
                  end;
               for v:=1 to N do
                  if (c[v,u-N]=1) and (Fl[v,u-N]>0) and (Tr[v]=0) then
                     begin
                        Put(v);
                        Tr[v]:=-u;
                        Ep[v]:=Ep[u];
                        if Ep[v]>Fl[v,u-N] then Ep[v]:=Fl[v,u-N];
                     end;
            end;
      end;
   repeat
   until Qempty;
   ok:=false;
end;

procedure IncFlow;
var delta: longint;
    u,v: integer;
begin
   delta:=Ep[kt];
   v:=kt;
   fp[v-N]:=Fp[v-N]+delta;
   repeat
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            Fl[v,u-N]:=Fl[v,u-N]-delta;
         end
      else Fl[u,v-N]:=Fl[u,v-N]+delta;
      v:=u;
   until Tr[v]=N+M+1;
   Ft[v]:=Ft[v]+delta;
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
   mf:=0;
   for i:=1 to N do
      mf:=mf+Ft[i];
end;

procedure TimLatCat;
var i: integer;
begin
   slx:=0;
   for i:=1 to N do
      if Tr[i]<>0 then
         begin
            inc(slx);
            x[slx]:=i;
         end;
   sly:=0;
   for i:=1 to M do
      if Tr[i+N]<>0 then
         begin
            inc(sly);
            y[sly]:=i;
         end;
end;

procedure Solve;
begin
   MaxFlow;
   TimLatCat;
end;

procedure Inkq;
var Tong: longint;
    i: integer;
begin
   Tong:=0;
   for i:=1 to N do Tong:=Tong+a[i];
   Tong:=Tong-mf;
   assign(fo,tfo); rewrite(fo);
   writeln(fo, Tong);
   for i:=1 to slx do write(fo,x[i],' ');
   writeln(fo);
   for i:=1 to sly do write(fo,y[i],' ');
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.