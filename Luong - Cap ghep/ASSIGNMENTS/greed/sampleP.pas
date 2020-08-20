{*********************************************************************
* Program    :      DAO THAM LAM (GREED)                             *
* Date       :      12-01-2006                                       *
* Group      :      Luong va Cap ghep                                *
*********************************************************************}
const
   tfi               =     'GREED.IN';
   tfo               =     'GREED.OUT';
   maxN              =     100;
   Unseen            =     10000;
   Vocuc             =     30000;

type
   mang1             =     array[1..maxN] of integer;

var
   fi,fo             :     text;
   N                 :     integer;
   x                 :     mang1;
   a                 :     array[1..maxN] of mang1;

   Nhan              :     array[1..2*maxN] of integer;
   Ft,Fp             :     array[1..maxN] of integer;
   Q                 :     array[1..2*maxN] of integer;
   qf,ql             :     integer;
   Tr                :     array[1..2*maxN] of integer;
   kt                :     integer;
   Tong              :     longint;


procedure Docdl;
var i,u,v: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do read(fi,x[i]); readln(fi);
   for u:=1 to N do
      for v:=1 to N do a[u,v]:=Unseen;
   while not seekeof(fi) do
      begin
         readln(fi,u,v);
         a[u,v]:=1;
         a[v,u]:=1;
      end;
   close(fi);
end;

procedure ChBi;
var i,j,k: integer;
begin
   for k:=1 to N do
      for i:=1 to N do
         for j:=1 to N do
            if a[i,j]>a[i,k]+a[k,j] then
               a[i,j]:=a[i,k]+a[k,j];
   for i:=1 to N do a[i,i]:=0;
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

procedure KhoitaoNhan;
var i,j: integer;
begin
   for i:=1 to N do Nhan[i]:=0;
   for j:=1 to N do
      begin
         Nhan[j+n]:=a[x[1],j];
         for i:=2 to N do
            if a[x[i],j]<Nhan[j+n] then Nhan[j+n]:=a[x[i],j];
      end;
end;

procedure KhoiTaoCapGhep;
begin
   fillchar(Ft,sizeof(Ft),0);
   fillchar(Fp,sizeof(Fp),0);
end;

procedure TimDuong(xp: integer; var ok: boolean);
var u,v,w: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   Put(xp); Tr[xp]:=2*N+1;
   repeat
      u:=Get;
      if u<=N then
         begin
            for v:=1 to N do
               if (a[x[u],v]=Nhan[u]+Nhan[v+n]) and (Tr[v+n]=0) then
                  begin
                     Put(v+n);
                     Tr[v+n]:=u;
                  end;
         end
      else
         begin
            if Fp[u-N]=0 then
               begin
                  kt:=u;
                  exit;
               end;
            v:=Fp[u-n];
            if Tr[v]=0 then
               begin
                  Put(v);
                  Tr[v]:=-u;
               end;
         end;
   until  Qempty;
   ok:=false;
end;

procedure SuaNhan;
var dmin,i,j: integer;
begin
   dmin:=Vocuc;
   for i:=1 to N do if Tr[i]<>0 then
      for j:=1 to N do if Tr[j+n]=0 then
         if dmin>a[x[i],j]-Nhan[i]-Nhan[j+n] then
            dmin:=a[x[i],j]-Nhan[i]-Nhan[j+n];
   for i:=1 to N do if Tr[i]<>0 then
      Nhan[i]:=Nhan[i]+dmin;
   for i:=1 to N do if Tr[i+n]<>0 then
      Nhan[i+n]:=Nhan[i+n]-dmin;
end;

procedure TangCap;
var u,v: integer;
begin
   v:=kt;
   repeat
      u:=Tr[v];
      if u<0 then u:=-u
      else if u<2*N+1 then
         begin
            Ft[u]:=v-n;
            Fp[v-n]:=u;
         end;
      v:=u;
   until v=2*N+1;
end;

procedure Ghep;
var i: integer;
    ok: boolean;
begin
   KhoiTaoNhan;
   KhoiTaoCapGhep;
   for i:=1 to N do
      begin
         repeat
            TimDuong(i,ok);
            if not ok then SuaNhan;
         until ok;
         TangCap;
      end;
   Tong:=0;
   for i:=1 to N do
      Tong:=Tong+a[x[i],Ft[i]];
end;

procedure Inkq;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,tong);
   close(fo);
end;


BEGIN
   Docdl;
   ChBi;
   Ghep;
   Inkq;
END.
