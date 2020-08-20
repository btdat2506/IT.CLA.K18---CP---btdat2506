{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}

const
   tfi='NUMWAYS.INP';
   tfo='NUMWAYS.OUT';
   maxN=50;
   maxM=10;
   Unseen=2*MaxN*MaxM+1;

var
   fi,fo: text;
   N,M: integer;
   a: array[1..maxN,1..maxM,1..maxN] of byte;
   ft,fs: array[1..maxN,1..maxM] of byte;
   Q: array[1..2*maxN*maxM] of integer;
   qf,ql: Integer;
   Tr: array[1..2*maxN*maxN] of integer;
   kt: integer;
   kq: integer;

function DoiSo(i,j,k: integer): integer;
begin
   DoiSo:=(k-1)*(M*N)+(i-1)*M+j;
end;

procedure DoiDinh(u: integer; var i,j,k: integer);
begin
   k:=(u-1) div (M*N)+1;
   u:=(u-1) mod (M*N)+1;
   i:=(u-1) div M+1;
   j:=(u-1) mod M+1;
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
var i,j,k,l,u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N,M);
   for j:=1 to M-1 do
      begin
         for i:=1 to N do
            begin
               read(fi,k);
               for l:=1 to k do
                  begin
                     read(fi,u);
                     a[i,j,u]:=1;
                  end;
               readln(fi);
            end;
      end;
   close(fi);
end;

procedure InitFlow;
var i,j: integer;
begin
   for j:=1 to M do
      for i:=1 to N do
         begin
            ft[i,j]:=0;
            fs[i,j]:=0;
         end;
end;

procedure FindPath(var ok: boolean);
var i,j,k,l,u,v: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to N*M*2 do Tr[i]:=0;
   {dua cac dinh xuat phat vao hang doi}
   for i:=1 to N do
      if Ft[i,1]=0 then
         begin
            u:=DoiSo(i,1,1);
            Put(u);
            Tr[u]:=Unseen;
         end;
   while not Qempty do
      begin
         u:=Get;
         DoiDinh(u,i,j,l);
         if l=1 then {dinh vao}
            begin
               {cung xuoi}
               v:=DoiSo(i,j,2);
               if (Fs[i,j]=0) and (Tr[v]=0) then
                  begin
                     Put(v);
                     Tr[v]:=u;
                  end;
               {Cung nguoc}
               if (Ft[i,j]>0) and (j>1) then
                  begin
                     v:=Doiso(Ft[i,j],j-1,2);
                     if Tr[v]=0 then
                        begin
                           Put(v);
                           Tr[v]:=-u;
                        end;
                  end;
            end
         else {dinh ra}
            begin
               {ket thuc}
               if (j=m) and (fs[i,j]=0) then
                  begin
                     kt:=u;
                     exit;
                  end;
               {cung xuoi}
               if (j<m) then
                  for k:=1 to N do
                     if (a[i,j,k]=1) and (fs[i,j]<>k) then
                        begin
                           v:=Doiso(k,j+1,1);
                           if Tr[v]=0 then
                              begin
                                 Put(v);
                                 Tr[v]:=u;
                              end;
                        end;
               {cung nguoc}
               if Tr[u]<0 then {di den u la cung nguoc}
                  begin
                     v:=DoiSo(i,j,1);
                     if (Tr[v]=0) then
                        begin
                           Put(v);
                           Tr[v]:=-u;
                        end;
                  end;
            end;
      end;
   ok:=false;
end;

procedure IncFlow;
var v,i,j,l,u,i1,j1,l1: integer;
begin
   v:=kt;
   DoiDinh(v,i,j,l);
   Fs[i,j]:=1;
   repeat
      DoiDinh(v,i,j,l);
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            DoiDinh(u,i1,j1,l1);
            if j1>j then
               begin
                  Ft[i1,j1]:=0;
                  if Ft[i,j]=0 then Fs[i,j]:=0;
               end;
         end
      else if u<>Unseen then
         begin
            DoiDinh(u,i1,j1,l1);
            if j1<j then
               begin
                  Fs[i1,j1]:=i;
                  Ft[i,j]:=i1;
               end;
         end;
      if u<>Unseen then v:=u;
   until u=Unseen;
   DoiDinh(v,i,j,l);
   Ft[i,j]:=1;
end;

procedure Solve;
var ok: boolean;
    i: integer;
begin
   initFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   kq:=0;
   for i:=1 to N do
      kq:=kq+ft[i,1];
end;

procedure InDuong(xp: integer);
var k,i: integer;
begin
   k:=xp;
   for i:=1 to m-1 do
      begin
         write(fo,k,' ');
         k:=Fs[k,i];
      end;
   writeln(fo,k);
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,kq);
   for i:=1 to N do
      if ft[i,1]=1 then InDuong(i);
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.