{$r-}
const
   tfi                  =     'TIEPTHI.IN09876543210987654321P';
   tfo                  =     'TIEPTHI.OU09876543210987654321T';
   maxN                 =     200;
   Unseen               =     maxlongint;

type
   mang1                =     array[1..200] of longint;

var
   fi, fo               :     text;
   N,K                  :     integer;
   c                    :     array[1..maxN] of ^mang1;
   dau, cuoi            :     array[1..maxN] of integer;
   T                    :     array[1..maxN,1..maxN] of byte;

   Nhan                 :     array[1..2*maxN] of longint;
   Ft,Fp                :     array[1..maxN] of integer;

   Q                    :     array[1..2*maxN] of integer;
   qf,ql                :     integer;

   Tr                   :     array[1..2*maxN] of integer;
   kt                   :     integer;

   slx                  :     integer;
   x                    :     array[1..maxN] of integer;

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
   Qempty:=qf=ql;
end;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,K);
   for i:=1 to N do
      begin
         for j:=1 to N do read(fi,c[i]^[j]);
         readln(fi);
      end;
   for i:=1 to K do read(fi,dau[i]);
   readln(fi);
   for i:=1 to K do read(fi,cuoi[i]);
   readln(fi);
   close(fi);
end;

procedure Floy;
var i,j,l: integer;
begin
   for i:=1 to N do
      for j:=1 to N do T[i,j]:=0;
   for i:=1 to N do
      for j:=1 to N do
         if (i<>j) then
            for l:=1 to N do
               if (l<>i) and (l<>j) then
                  if (c[i]^[j]>c[i]^[l]+c[l]^[j]) then
                     begin
                        c[i]^[j]:=c[i]^[l]+c[l]^[j];
                        T[i,j]:=l;
                     end;
end;

procedure KhoiTaoNhan;
var i,j: integer;
begin
   for i:=1 to K do Nhan[i]:=0;
   for i:=K+1 to 2*K do
      begin
         Nhan[i]:=Unseen;
         for j:=1 to K do
            if Nhan[i]>c[dau[i-K]]^[cuoi[j]] then
               nhan[i]:=c[dau[i-K]]^[cuoi[j]];
      end;
end;

procedure KhoiTaoCapGhep;
var i: integer;
begin
   for i:=1 to K do Ft[i]:=0;
   for i:=1 to K do Fp[i]:=0;
end;

procedure TimDuong(xp: integer; var ok: boolean);
var i, u, v: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to 2*K do Tr[i]:=0;
   Put(xp);
   Tr[xp]:=2*K+1;
   repeat
      u:=Get;
      if u<=K then
         begin
            for v:=1 to K do
               if (c[dau[u]]^[cuoi[v]]=nhan[u]+Nhan[v+K]) and (Tr[v+K]=0) then
                  begin
                     Put(v+K);
                     Tr[v+K]:=u;
                  end;
         end
      else
         begin
            if Fp[u-K]=0 then
               begin
                  kt:=u;
                  exit;
               end;
            v:=Fp[u-k];
            if Tr[v]=0 then
               begin
                  Put(v);
                  Tr[v]:=-u;
               end;
         end;
   until Qempty;
   ok:=false;
end;

procedure SuaNhan;
var dmin: longint;
    i,j: integer;
begin
   dmin:=Unseen;
   for i:=1 to K do
      if Tr[i]<>0 then
         for j:=1 to K do
            if Tr[j+K]=0 then
               if dmin>c[dau[i]]^[cuoi[j]]-nhan[i]-nhan[j+k] then
                  dmin:=c[dau[i]]^[cuoi[j]]-nhan[i]-nhan[j+k];
   (* sua nhan *)
   for i:=1 to K do
      if Tr[i]<>0 then
         Nhan[i]:=Nhan[i]+dmin;
   for i:=1 to K do
      if Tr[i+K]<>0 then
         Nhan[i+K]:=Nhan[i+K]-dmin;
end;

procedure TangCap;
var u,v: integer;
begin
   v:=Kt;
   repeat
      u:=Tr[v];
      if u<0 then u:=-u else
         if u<2*K+1 then
            begin
               Ft[u]:=v-k;
               Fp[v-k]:=u;
            end;
      v:=u;
   until v=2*K+1;
end;

procedure Ghep;
var i: integer;
    ok: boolean;
begin
   KhoiTaoNhan;
   KhoiTaoCapGhep;
   for i:=1 to K do
      begin
         repeat
            TimDuong(i,ok);
            if not ok then SuaNhan;
         until ok;
         TangCap;
      end;
end;

procedure Tim(u,v: integer);
begin
   if T[u,v]=0 then
      begin
        inc(slx);
        x[slx]:=u;
        if T[u,v]=0 then exit;
      end
   else
      begin
         Tim(u,T[u,v]);
         Tim(T[u,v],v);
      end;
end;

procedure Inkq;
var tong: longint;
    i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   Tong:=0;
   for i:=1 to K do
      Tong:=Tong+C[dau[i]]^[cuoi[Ft[i]]];
   writeln(fo,Tong);
   for i:=1 to K do
      begin
         slx:=0;
         Tim(dau[i],cuoi[Ft[i]]);
         for j:=1 to slx do write(fo,x[j],' ');
         writeln(fo,cuoi[ft[i]]);
      end;
   close(fo);
end;

procedure CapPhat;
var i: integer;
begin
   for i:=1 to maxN do new(c[i]);
end;

BEGIN
   CapPhat;
   Docdl;
   Floy;
   Ghep;
   Inkq;
END.