{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}

uses crt;

const
   tfi                  =       'ZOO.INP';
   tfo                  =       'ZOO.OUT';
   maxN                 =       50;
   dh                   :       array[1..4] of integer=(-1,0,1,0);
   dc                   :       array[1..4] of integer=(0,-1,0,1);

var
   fi,fo                :       text;
   M,N                  :       integer;
   a                    :       array[1..maxN,1..maxN] of integer;
   x,y,t                :       integer;
   dd                   :       array[1..maxN,1..maxN] of byte;
   RaNgoai              :       boolean;
   fl                   :       array[1..maxN,1..maxN] of byte;
   Tr                   :       array[1..maxN,1..maxN] of shortint;
   Q                    :       array[1..2,1..2500] of integer;
   qf,ql                :       integer;
   kth,ktc,ktd          :       integer;
   slkq                 :       integer;
   row,col,dir          :       array[1..4*maxN*maxN] of byte;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(i,j: integer);
begin
   q[1,ql]:=i;
   q[2,ql]:=j;
   inc(ql);
end;

procedure Get(var i,j: integer);
begin
   i:=q[1,qf];
   j:=q[2,qf];
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
   readln(fi,M,N,x,y,t);
   for i:=1 to M do
      for j:=1 to N do read(fi,a[i,j]);
   close(fi);
end;

function Cua(i,j,k: integer): boolean;
begin
   Cua:=(a[i,j] and (1 shl (k-1)))=0;
end;

function Inside(i,j: integer): boolean;
begin
   Inside:=(i>=1) and (i<=M) and (j>=1) and (j<=N);
end;

function RaDuoc(i,j: integer): boolean;
begin
   RaDuoc:=true;
   if (i=1) and (a[i,j] and 1=0) then exit;
   if (i=M) and (a[i,j] and 4=0) then exit;
   if (j=1) and (a[i,j] and 2=0) then exit;
   if (j=N) and (a[i,j] and 8=0) then exit;
   RaDuoc:=false;
end;

procedure MoRong;
var i,j,k,ii,jj: integer;
begin
   for i:=1 to M do
      for j:=1 to N do
         if dd[i,j]=1 then
            for k:=1 to 4 do
               if Cua(i,j,k) then
                  begin
                     ii:=i+dh[k];
                     jj:=j+dc[k];
                     if not inside(ii,jj) then
                        begin
                           RaNgoai:=true;
                           exit;
                        end;
                     if (dd[ii,jj]<>1) then dd[ii,jj]:=2;
                  end;
   for i:=1 to M do
      for j:=1 to N do
         if dd[i,j]=2 then dd[i,j]:=1;
end;

procedure DanhDauXP;
var i: integer;
begin
   fillchar(dd,sizeof(dd),0);
   dd[x,y]:=1;
   RaNgoai:=false;
   for i:=1 to t do
      begin
         MoRong;
         if RaNgoai then exit;
      end;
end;

procedure InitFlow;
var i,j: integer;
begin
   for i:=1 to M do
      for j:=1 to N do fl[i,j]:=0;
end;

procedure TimDuong(var ok: boolean);
var i,j,k,ii,jj,kk: integer;
begin
   ok:=true;
   for i:=1 to M do
      for j:=1 to N do tr[i,j]:=0;
   InitQ;
   for i:=1 to M do
      for j:=1 to N do
         if dd[i,j]=1 then
            begin
               Put(i,j);
               Tr[i,j]:=5;
            end;
   while not Qempty do
      begin
         Get(i,j);
         {cung xuoi}
         for k:=1 to 4 do
            if Cua(i,j,k) and (fl[i,j] and (1 shl (k-1))=0) then
               begin
                  ii:=i+dh[k];
                  jj:=j+dc[k];
                  if not Inside(ii,jj) then
                     begin
                        kth:=i;
                        ktc:=j;
                        ktd:=k;
                        exit;
                     end;
                  if (Tr[ii,jj]=0) then
                     begin
                        Put(ii,jj);
                        Tr[ii,jj]:=k;
                     end;
               end;
         {cung nguoc}
         for k:=1 to 4 do
            begin
               kk:=1+(1+k mod 4) mod 4;
               ii:=i+dh[k];
               jj:=j+dc[k];
               if Cua(i,j,k) and inside(ii,jj) and (fl[ii,jj] and (1 shl (kk-1))<>0) and (Tr[ii,jj]=0) then
                  begin
                     Put(ii,jj);
                     Tr[ii,jj]:=-k;
                  end;
            end;
      end;
   ok:=false;
end;

procedure IncFlow;
var i,j,k,ii,jj,kk: integer;
begin
   i:=kth;
   j:=ktc;
   Fl[i,j]:=Fl[i,j] or (1 shl (ktd-1));
   while Tr[i,j]<>5 do
      begin
         if Tr[i,j]>0 then
            begin
               k:=Tr[i,j];
               kk:=1+(1+k mod 4) mod 4;
               ii:=i+dh[kk];
               jj:=j+dc[kk];
               Fl[ii,jj]:=Fl[ii,jj] or (1 shl (k-1));
            end
         else
           begin
              k:=-Tr[i,j];
              kk:=1+(1+k mod 4) mod 4;
              ii:=i+dh[kk];
              jj:=j+dc[kk];
              Fl[i,j]:=Fl[i,j] and (15 xor (1 shl (kk-1)));
           end;
         i:=ii;
         j:=jj;
      end;

end;

procedure MaxFlow;
var ok: boolean;
begin
   InitFlow;
   repeat
      TimDuong(ok);
      if ok then IncFlow;
   until not ok;
end;

procedure TimLatCat;
var i,j,k,ii,jj: integer;
begin
   slkq:=0;
   for i:=1 to M do
      for j:=1 to N do
         if Tr[i,j]<>0 then
            for k:=1 to 4 do
               if Cua(i,j,k) then
                  begin
                     ii:=i+dh[k];
                     jj:=j+dc[k];
                     if inside(ii,jj) and (Tr[ii,jj]=0) then
                        begin
                           inc(slkq);
                           row[slkq]:=i;
                           col[slkq]:=j;
                           dir[slkq]:=k;
                        end;
                  end;
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if RaNgoai then writeln(fo,-1) else
      begin
         writeln(fo,slkq);
         for i:=1 to slkq do
            begin
               write(fo,row[i],' ',col[i],' ');
               case dir[i] of
                  1: writeln(fo,'B');
                  2: writeln(fo,'T');
                  3: writeln(fo,'N');
                  4: writeln(fo,'D');
               end;
            end;
      end;
   close(fo);
end;

BEGIN
   Docdl;
   DanhDauXP;
   if not RaNgoai then
      begin
         MaxFlow;
         TimLatCat;
      end;
   inkq;
END.