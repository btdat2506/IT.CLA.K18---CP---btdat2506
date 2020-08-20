{***************************************************************************
* Ten fil bai tap: ASSIGN.RTF                                              *
* Nguoi viet     : LE THANH BINH                                           *
* Ngay viet      : 24/10/2003                                              *
* Thuat toan     : CAP GHEP DAY DU TOI UU DAT MIN                          *
***************************************************************************}
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt;

const
   tfi                  =       'ASSIGN.INP';
   tfo                  =       'ASSIGN.OUT';
   maxN                 =       200;
   ONE                  =       1;
   TWO                  =       maxN*ONE+1;
   THREE                =       maxN*TWO+1;
   ZERO                 =       maxN*THREE+1;

type
   mang                 =       array[1..maxN] of LongInt;

var
   fi,fo                :       text;
   Gr                   :       array[1..maxN] of ^mang;
   N                    :       integer;
   Nhan                 :       array[1..2*maxN] of LongInt;
   fa,fb                :       array[1..maxN] of integer;
   Q                    :       array[1..2*maxN] of integer;
   qf,ql                :       integer;
   Tr                   :       array[1..2*maxN] of integer;
   kt                   :       integer;

procedure ChuanBi;
var i,j,u,v,w: integer;
begin
   for i:=1 to maxN do new(Gr[i]);
   readln(fi,N);
   for i:=1 to N do
      for j:=1 to N do Gr[i]^[j]:=ZERO;
   for i:=1 to N do
      begin
         readln(fi,u,v,w);
         Gr[i]^[u]:=ONE;
         Gr[i]^[v]:=TWO;
         Gr[i]^[w]:=THREE;
      end;
end;

procedure KhoiTaoNhan;
var i,j: integer;
begin
   for i:=1 to N do Nhan[i]:=0;
   for j:=1 to N do
      begin
         Nhan[j+N]:=ZERO;
         for i:=1 to N do
            if Gr[i]^[j]<Nhan[j+N] then Nhan[j+N]:=Gr[i]^[j];
      end;
   fillchar(fa,sizeof(fa),0);
   fillchar(fb,sizeof(fb),0);
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

procedure TimDuong(xp: integer; var ok: boolean);
var u,v,w: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   Put(xp); Tr[xp]:=-1;
   repeat
      u:=Get;
      if u<=N then
         begin
            for v:=1 to N do
               if (Nhan[u]+Nhan[v+N]=Gr[u]^[v]) and (Tr[v+N]=0) then
                  begin
                     Put(v+N);
                     Tr[v+N]:=u;
                     if fb[v]=0 then
                        begin
                           kt:=v+N;
                           exit;
                        end;
                  end;
         end
      else
         begin
            w:=fb[u-N];
            if Tr[w]=0 then
               begin
                  Put(w);
                  Tr[w]:=u;
               end;
         end;
   until Qempty;
   ok:=false;
end;

procedure SuaNhan;
var dmin: LongInt;
    i,j: integer;
begin
   dmin:=MaxLongInt;
   for i:=1 to N do
      if Tr[i]<>0 then
         for j:=1 to N do
            if (Tr[j+N]=0) and (dmin>Gr[i]^[j]-Nhan[i]-Nhan[j+N]) then
               dmin:=Gr[i]^[j]-Nhan[i]-Nhan[j+N];
   for i:=1 to N do
      if Tr[i]<>0 then Nhan[i]:=Nhan[i]+dmin;
   for j:=1 to N do
      if Tr[j+N]<>0 then Nhan[j+N]:=Nhan[j+N]-dmin;
end;

procedure TangCap;
var u,v: integer;
begin
   v:=kt;
   repeat
      u:=Tr[v];
      fa[u]:=v-N;
      fb[v-N]:=u;
      v:=Tr[u];
   until v=-1;
end;

procedure GhepSumMin;
var i: integer;
    ok: boolean;
begin
   KhoiTaoNhan;
   for i:=1 to N do
      begin
         repeat
            TimDuong(i,ok);
            if not ok Then SuaNhan;
         until ok;
         TangCap;
      end;
end;

procedure Inkq;
var i,pp,qq,rr: integer;
begin
   pp:=0; qq:=0; rr:=0;
   for i:=1 to N do
      begin
         if Gr[i]^[fa[i]]=ZERO then inc(pp);
         if Gr[i]^[fa[i]]=ONE then inc(qq);
         if Gr[i]^[fa[i]]=TWO then inc(rr);
      end;
   writeln(fo,pp,' ',qq,' ',rr);
   for i:=1 to N do writeln(fo,fa[i]); 
end;

BEGIN
   assign(fi,tfi); reset(fi);
   assign(fo,tfo); rewrite(fo);
   ChuanBi;
   GhepSumMin;
   Inkq;
   close(fi); close(fo);
END.