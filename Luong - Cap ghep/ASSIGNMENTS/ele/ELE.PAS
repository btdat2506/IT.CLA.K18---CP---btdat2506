{**************************************************************************
* Ten file bai tap: ELE.RTF                                               *
* Nguoi viet      : LE THANH BINH                                         *
* Ngay viet       : 24/10/2003                                            *
**************************************************************************}
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt;

const
   tfi                         =       'ELE.INP';
   tfo                         =       'ELE.OUT';
   maxN                        =       15;
   Unseen                      =       maxN*maxN+1;
   dh: array[1..4] of integer  =       (0,-1,0,1);
   dc: array[1..4] of integer  =       (1,0,-1,0);

type
   mang                        =        array[1..maxN*maxN] of integer;

var
   fi,fo                       :        text;
   N                           :        integer;
   a                           :        array[1..maxN,1..maxN] of byte;

   Truoc,Sau                   :        mang;
   mf                          :        integer;

   Q                           :        mang;
   qf,ql                       :        integer;

   Tr                          :        mang;
   kt                          :        integer;

function DoiSo(i,j: integer): integer;
begin
   DoiSo:=(i-1)*N+j;
end;

procedure DoiDinh(u: integer; var i,j: integer);
begin
   i:=(u-1) div N+1;
   j:=(u-1) mod N+1;
end;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         for j:=1 to N do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
end;

procedure InitFlow;
begin
   Fillchar(Truoc,sizeof(Truoc),0);
   Fillchar(Sau,sizeof(sau),0);
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

function Ke(u,k: integer): integer;
var i,j,i1,j1: integer;
begin
   Ke:=0;
   DoiDinh(u,i,j);
   i1:=i+dh[k];
   j1:=j+dc[k];
   if (i1<1) or (i1>n) or (j1<1) or (j1>n) then exit;
   if a[i1,j1]=1 then exit;
   Ke:=DoiSo(i1,j1);
end;

function Bien(v: integer): boolean;
var i,j: integer;
begin
   DoiDinh(v,i,j);
   Bien:=(i=1) or (i=n) or (j=1) or (j=n);
end;

procedure FindPath(var ok: boolean);
var i,j,u,k,v: integer;
begin
   InitQ;
   ok:=true;
   Fillchar(Tr,sizeof(Tr),0);
   for i:=2 to N-1 do
      for j:=2 to N-1 do
         if (a[i,j]=1) then
            begin
               u:=DoiSo(i,j);
               if Truoc[u]=0 then
                  begin
                     Put(u);
                     Tr[u]:=Unseen;
                  end;
            end;
   while not Qempty do
      begin
         u:=Get;
         {Cung xuoi}
         if (Truoc[u]=0) or (Tr[u]<0) then
            for k:=1 to 4 do
               begin
                  v:=Ke(u,k);
                  if (v>0) and (Sau[u]<>v) and (Tr[v]=0) then
                     begin
                        Put(v);
                        Tr[v]:=u;
                        if Bien(v) and (Sau[v]=0) then
                           begin
                              kt:=v;
                              exit;
                           end;
                     end;
               end;
         {cung nguoc}
         if (Truoc[u]>0) and (Truoc[u]<>Unseen) then
            begin
               v:=Truoc[u];
               if (Tr[v]=0) then
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
   Sau[v]:=Unseen;
   repeat
      u:=Tr[v];
      if u>0 then
         begin
            Sau[u]:=v;
            Truoc[v]:=u;
         end
      else
         begin
            u:=-u;
            Truoc[u]:=0;
            if Truoc[v]=0 then Sau[v]:=0;
         end;
      v:=u;
   until Tr[v]=Unseen;
   Truoc[v]:=Unseen;
end;

procedure MaxFlow;
var ok: boolean;
    i,j,u: integer;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   mf:=0;
   for i:=2 to N-1 do
      for j:=2 to N-1 do
         begin
            u:=DoiSo(i,j);
            if Truoc[u]=Unseen then inc(mf);
         end;
end;

function Huong(u,v: integer): char;
var i,j,i1,j1: integer;
begin
   DoiDinh(u,i,j);
   DoiDinh(v,i1,j1);
   if j1=j+1 then Huong:='E' else
   if i1=i-1 then Huong:='N' else
   if j1=j-1 then Huong:='W' else Huong:='S';
end;

procedure Inkq;
var u,i,j: integer;
    ch: char;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,mf);
   for i:=2 to N-1 do
      for j:=2 to N-1 do
         begin
            u:=DoiSo(i,j);
            if Truoc[u]=Unseen then
               begin
                  write(fo,u,' ');
                  while Sau[u]<>Unseen do
                     begin
                        ch:=Huong(u,Sau[u]);
                        write(fo,ch);
                        u:=Sau[u];
                     end;
                  writeln(fo);
               end;
         end;
   close(fo);
end;

BEGIN
   Docdl;
   MaxFlow;
   Inkq;
END.