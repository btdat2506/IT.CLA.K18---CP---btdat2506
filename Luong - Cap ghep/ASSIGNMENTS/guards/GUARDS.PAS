{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt;

const
   tfi='GUARDS.INP';
   tfo='GUARDS.OUT';
   NN=200;
   MM=200;
   maxN=200;
   maxQ=20000;
   Unseen=65000;

type
   mangB=array[1..maxN,1..maxN] of byte;
   mangW=array[1..maxN] of word;
   mangQ=array[1..maxQ] of byte;

var
   fi,fo: text;
   m,n: word;
   a: array[1..maxN,1..maxN] of byte;
   kcH,kcC: ^mangB;
   ok: boolean;
   Q: array[1..2] of ^mangQ;
   qf,ql: word;
   Tr: array[1..maxN] of ^mangW;
   kttH,kttC,ktpH,ktpC: word;

procedure CapPhat;
var i: word;
begin
   New(kcH);
   new(kcC);
   for i:=1 to 2 do New(Q[i]);
   for i:=1 to maxN do New(Tr[i]);
end;

procedure SinhDL;
var ch: char;
    i,j: integer;
begin
   clrscr;
   writeln('Ban co tao file ',tfi,' (C/K)?');
   repeat ch:=readkey until upcase(ch) in ['C','K'];
   if upcase(ch)='K' then exit;
   randomize;
   N:=NN;
   M:=MM;
   for i:=1 to m do
      for j:=1 to n do
         begin
            a[i,j]:=random(7);
            if a[i,j]>2 then a[i,j]:=0;
         end;
   assign(fi,tfi); rewrite(fi);
   writeln(fi,M,' ',N);
   for i:=1 to m do
      begin
         for j:=1 to n do write(fi,a[i,j],' ');
         writeln(fi);
      end;
   close(fi);
end;


function Doiso(i,j: word): word;
begin
   Doiso:=(i-1)*n+j;
end;

procedure DoiDinh(u: word; var i,j: word);
begin
   i:=(u-1) div n+1;
   j:=(u-1) mod n+1;
end;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(i,j: word);
begin
   q[1]^[ql]:=i;
   q[2]^[ql]:=j;
   inc(ql);
end;

procedure Get(var i,j: word);
begin
   i:=q[1]^[qf];
   j:=q[2]^[qf];
   inc(qf);
end;

function Qempty: boolean;
begin
   Qempty:=(qf=ql);
end;

procedure Docdl;
var i,j: word;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,m,n);
   for i:=1 to m do
      begin
         for j:=1 to n do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
end;

procedure InitFlow;
var i,j: word;
begin
   for i:=1 to m do
      for j:=1 to n do kcH^[i,j]:=0;
   for i:=1 to m do
      for j:=1 to n do kcC^[i,j]:=0;
end;

function DauHang(i,j: word): word;
var k: word;
begin
   k:=j;
   while (k>=1) and (a[i,k]<>2) do dec(k);
   inc(k);
   DauHang:=k;
end;

function DauCot(i,j: word): word;
var k: word;
begin
   k:=i;
   while (k>=1) and (a[k,j]<>2) do dec(k);
   inc(k);
   DauCot:=k;
end;

function TimHang(i,k: word): word;
var l: word;
begin
   for l:=i downto 1 do
      begin
         if a[l,k]=2 then break;
         if a[l,k]=3 then
            begin
               TimHang:=l;
               exit;
            end;
      end;
   for l:=i to m do
      begin
         if a[l,k]=2 then break;
         if a[l,k]=3 then
            begin
               TimHang:=l;
               exit;
            end;
      end;
   TimHang:=0;
end;

function TimCot(i,k: word): word;
var l: word;
begin
   for l:=k to n do
      begin
         if a[i,l]=2 then break;
         if a[i,l]=3 then
            begin
               TimCot:=l;
               exit;
            end;
      end;
   for l:=k downto 1 do
      begin
         if a[i,l]=2 then exit;
         if a[i,l]=3 then
            begin
               TimCot:=l;
               exit;
            end;
      end;
   TimCot:=0;
end;

procedure FindPath(var ok: boolean);
var i,j,k,l,r: word;
begin
   ok:=true;
   InitQ;
   for i:=1 to m do
      for j:=1 to n do Tr[i]^[j]:=0;

   {dua cac phan tu xuat phat vao hang doi}
   for i:=1 to m do
      for j:=1 to n do
         if (a[i,j]<>2) and (kcH^[i,j]=0) then
            begin
               k:=DauHang(i,j);
               if Tr[i]^[k]=0 then
                  begin
                     Put(i,k);
                     Tr[i]^[k]:=Unseen;
                  end;
            end;

   while not Qempty do
      begin
         Get(i,j);
         for k:=j to n do
            begin
               if a[i,k]=2 then break;
               if (a[i,k]=0) then
                  begin
                     if kcC^[i,k]=0 then
                        begin
                           l:=DauCot(i,k);
                           ktpH:=l; ktpC:=k;
                           kttH:=i; kttC:=j;
                           exit;
                        end;
                     l:=TimHang(i,k);
                     r:=kcH^[l,k];
                     if Tr[l]^[r]=0 then
                        begin
                           Put(l,r);
                           Tr[l]^[r]:=Doiso(i,j);
                        end;
                  end;
            end;
      end;
   ok:=false;
end;

procedure DatLinh(i,j: word);
var l,r: word;
begin
   r:=DauHang(i,j);
   for l:=j to n do
      begin
         if a[i,l]=2 then break;
         kcH^[i,l]:=r;
      end;
   for l:=j downto 1 do
      begin
         if a[i,l]=2 then break;
         kcH^[i,l]:=r;
      end;
   r:=DauCot(i,j);
   for l:=i downto 1 do
      begin
         if a[l,j]=2 then break;
         kcC^[l,j]:=r;
      end;
   for l:=i to m do
      begin
         if a[l,j]=2 then break;
         kcC^[l,j]:=r;
      end;
end;

procedure DoLinh(i,j: word);
var l: word;
begin
   for l:=j to n do
      begin
         if a[i,l]=2 then break;
         kcH^[i,l]:=0;
      end;
   for l:=j downto 1 do
      begin
         if a[i,l]=2 then break;
         kcH^[i,l]:=0;
      end;
   for l:=i downto 1 do
      begin
         if a[l,j]=2 then break;
         kcC^[l,j]:=0;
      end;
   for l:=i to m do
      begin
         if a[l,j]=2 then break;
         kcC^[l,j]:=0;
      end;
end;

procedure IncFlow;
var u1,v1,u2,v2,k: word;
begin
   u2:=ktpH; v2:=ktpC;
   u1:=kttH; v1:=kttC;
   while Tr[u1]^[v1]<>Unseen do
      begin
         k:=TimCot(u1,v1);
         a[u1,k]:=0;
         DoLinh(u1,k);
         a[u1,v2]:=3;
         DatLinh(u1,v2);
         u2:=DauCot(u1,k);
         v2:=k;
         DoiDinh(Tr[u1]^[v1],u1,v1);
      end;
   a[u1,v2]:=3;
   DatLinh(u1,v2);
end;

procedure Ghep;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
end;

procedure Inkq;
var sol,i,j: word;
begin
   sol:=0;
   for i:=1 to m do
      for j:=1 to n do
         if a[i,j]=3 then inc(sol);
   assign(fo,tfo); rewrite(fo);
   writeln(fo,sol);
   for i:=1 to m do
      for j:=1 to n do
         if a[i,j]=3 then  writeln(fo,i,' ',j);
   close(fo);
end;

BEGIN
   CapPhat;
   {SinhDl;}
   Docdl;
   Ghep;
   Inkq;
END.