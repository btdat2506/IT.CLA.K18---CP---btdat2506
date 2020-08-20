const
   tfi                  =     'PATROL.INP';
   tfo                  =     'PATROL.OUT';
   maxN                 =     100;

var
   fi, fo               :     text;
   a                    :     array[1..maxN,1..maxN] of byte;
   N,T                  :     integer;

   Fl                   :     array[1..maxN,1..maxN] of integer;

   Q                    :     array[1..maxN] of integer;
   qf,ql                :     integer;
   Tr,Ep                :     array[1..maxN] of integer;

   dad                  :     array[1..maxN] of integer;

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
var i,j,k,u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N,T);
   for i:=1 to N-1 do
      begin
         read(fi,k);
         for j:=1 to k do
            begin
               read(fi,u);
               a[i,u]:=2;
            end;
         readln(fi);
      end;
   close(fi);
end;

function Min(u,v: integer): integer;
begin
   if u<v then min:=u else min:=v;
end;

procedure TimDuongMax(var ok: boolean);
var u,v: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   Put(1); Tr[1]:=N+1; Ep[1]:=2;
   repeat
      u:=Get;
      (* Tim cac cung xuoi *)
      for v:=u+1 to N do
         if (Fl[u,v]<a[u,v]) and (Tr[v]=0) then
            begin
               Put(v);
               Tr[v]:=u;
               Ep[v]:=min(Ep[u],a[u,v]-Fl[u,v]);
               if v=N then exit;
            end;
      (* Tim cac cung nguoc *)
      for v:=1 to u-1 do
         if (Fl[v,u]>0) and (Tr[v]=0) then
            begin
               Put(v);
               Tr[v]:=-u;
               Ep[v]:=Min(Ep[u],Fl[v,u]);
            end;
   until Qempty;
   ok:=false;
end;

procedure TangLuongMax;
var u,v,delta: integer;
begin
   delta:=Ep[N];
   v:=N;
   repeat
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            Fl[v,u]:=Fl[v,u]-delta;
         end
      else if u<N+1 then
         Fl[u,v]:=Fl[u,v]+delta;
      v:=u;
   until v=N+1;
end;

procedure MaxFlow;
var ok: boolean;
begin
   Fillchar(Fl,sizeof(Fl),0);
   repeat
      TimDuongMax(ok);
      if ok then TangLuongMax;
   until not ok;
end;

procedure AddFlow;
var i,j,delta,v,u: integer;
begin
   for i:=N-1 downto 1 do
      for j:=i+1 to N do
         if (a[i,j]=2) and (Fl[i,j]<2) then
            begin
               delta:=2-Fl[i,j];
               Fl[i,j]:=2;
               v:=i;
               while v>1 do
                  begin
                     u:=v;
                     repeat dec(u) until a[u,v]=2;
                     Fl[u,v]:=Fl[u,v]+delta;
                     v:=u;
                  end;
               u:=j;
               while u<N do
                  begin
                     v:=u;
                     repeat inc(v) until a[u,v]=2;
                     Fl[u,v]:=Fl[u,v]+delta;
                     u:=v;
                  end;
            end;
end;

procedure TimDuongMin(var ok: boolean);
var u,v: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   Put(1); tr[1]:=N+1; Ep[1]:=maxint;
   repeat
      u:=Get;
      (* Cung xuoi *)
      for v:=u+1 to N do
         if (Fl[u,v]>2) and (Tr[v]=0) then
            begin
               Put(v);
               Tr[v]:=u;
               Ep[v]:=Min(Ep[u],Fl[u,v]-2);
               if v=N then exit;
            end;
      (* cung nguoc *)
      for v:=u-1 downto 1 do
         if (a[v,u]=2) and (Tr[v]=0) then
            begin
               Put(v);
               tr[v]:=-u;
               Ep[v]:=Ep[u];
            end;
   until Qempty;
   ok:=false;
end;

procedure GiamLuongMin;
var u,v,delta: integer;
begin
   v:=N;
   delta:=Ep[N];
   repeat
      u:=tr[v];
      if u<0 then
         begin
            u:=-u;
            Fl[v,u]:=Fl[v,u]+delta;
         end
      else if u<N+1 then Fl[u,v]:=Fl[u,v]-delta;
      v:=u;
   until v=N+1;
end;

procedure MinFlow;
var ok: boolean;
    i: integer;
begin
   repeat
      TimDuongMin(ok);
      if ok then GiamLuongMin;
   until not ok;
end;

procedure Solve;
begin
   MaxFlow;
   AddFlow;
   MinFlow;
end;

procedure Inkq;
var kq: longint;
    i,j: integer;
begin
   kq:=0;
   for i:=1 to N-1 do
      for j:=i+1 to N do
         kq:=kq+Fl[i,j];
   kq:=kq*T;
   assign(fo,tfo); rewrite(fo);
   writeln(fo,kq);
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.