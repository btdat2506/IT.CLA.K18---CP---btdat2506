{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='BV.IN';
    dtfo='BV.OU';
    dtfm='BV.AS';

type
   mang=array[1..10000] of longint;
   mang1=array[1..5001] of integer;

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   dd: array[1..10000] of byte;

   N,M: longint;
   c,dau,cuoi,nguoc: ^mang;
   tro,troN: mang1;
   mfout,Mfmau: longint;
   q: array[1..5001] of longint;
   qf,ql: longint;
   den: array[1..5001] of byte;

procedure CapPhat;
begin
   new(c);
   new(dau);
   new(cuoi);
   new(nguoc);
end;

procedure GiaiPhong;
begin
   dispose(c);
   dispose(dau);
   dispose(cuoi);
   dispose(nguoc);
end;


procedure Docdl;
var w,u,v: longint;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   M:=0;
   while not seekeof(fi) do
      begin
         readln(fi,u,v,w);
         inc(M);
         c^[m]:=w;
         dau^[m]:=u;
         cuoi^[m]:=v;
      end;
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Mfmau);
   close(fm);
end;

procedure DoiCho(var u,v: longint);
var t: longint;
begin
   t:=u;
   u:=v;
   v:=t;
end;

procedure Sort(k,l: longint);
var i,j,rd,rc: longint;
begin
   rd:=dau^[(k+l) div 2];
   rc:=cuoi^[(k+l) div 2];
   i:=k; j:=l;
   repeat
      while (dau^[i]<rd) or ((dau^[i]=rd) and (cuoi^[i]<rc)) do inc(i);
      while (dau^[j]>rd) or ((dau^[j]=rd) and (cuoi^[j]>rc)) do dec(j);
      if i<=j then
         begin
            DoiCho(Dau^[i],Dau^[j]);
            DoiCho(Cuoi^[i],Cuoi^[j]);
            DoiCho(c^[i],c^[j]);
            inc(i); dec(j);
         end;
   until i>j;
   if k<j then Sort(k,j);
   if i<l then Sort(i,l);
end;

procedure SortN(k,l: longint);
var i,j,rd,rc: longint;
begin
   rc:=cuoi^[nguoc^[(k+l) div 2]];
   i:=k; j:=l;
   repeat
      while (cuoi^[nguoc^[i]]<rc) do inc(i);
      while (cuoi^[nguoc^[j]]>rc) do dec(j);
      if i<=j then
         begin
            DoiCho(nguoc^[i],nguoc^[j]);
            inc(i); dec(j);
         end;
   until i>j;
   if k<j then SortN(k,j);
   if i<l then SortN(i,l);
end;


procedure InitGraph;
var i,j,u,v: longint;
begin
   Sort(1,M); {sap xep theo dau tang dan}

   {bo di cac canh trung}
   i:=1;
   while (i<M) do
      begin
         while (i<M) and (dau^[i]=dau^[i+1]) and (cuoi^[i]=cuoi^[i+1]) do
            begin
               c^[i]:=c^[i]+c^[i+1];
               for j:=i+1 to M-1 do
                  begin
                     c^[j]:=c^[j+1];
                     dau^[j]:=dau^[j+1];
                     cuoi^[j]:=cuoi^[j+1];
                  end;
               dec(m);
            end;
         inc(i);
      end;

   {tao lap mang tro}
   for i:=1 to N do Tro[i]:=0;
   for i:=1 to M do
      begin
         u:=dau^[i];
         tro[u]:=tro[u]+1;
      end;
   u:=1;
   for i:=1 to N do
      begin
         v:=Tro[i];
         Tro[i]:=u;
         u:=u+v;
      end;
   Tro[n+1]:=u;

   {tao mang tro nguoc}
   for i:=1 to M do nguoc^[i]:=i;
   SortN(1,M);
   for i:=1 to N do TroN[i]:=0;
   for i:=1 to M do
      begin
         u:=cuoi^[nguoc^[i]];
         TroN[u]:=troN[u]+1;
      end;
   u:=1;
   for i:=1 to N do
      begin
         v:=TroN[i];
         TroN[i]:=u;
         u:=u+v;
      end;
   TroN[n+1]:=u;
end;

procedure initq;
begin
   qf:=1;
   ql:=1;
end;

procedure put(u: longint);
begin
  q[ql]:=u;
  inc(ql);
end;

function get: longint;
begin
   get:=q[qf];
   inc(qf);
end;

function qempty: boolean;
begin
   qempty:=(qf=ql);
end;

procedure Ktra(var co: boolean);
var u,i,v: longint;
begin
   co:=true;
   initQ;
   for u:=1 to N do den[u]:=0;
   Put(N); den[n]:=1;
   repeat
      u:=get;
      for i:=tro[u] to tro[u+1]-1 do
         if dd[i]=0 then
         begin
            v:=cuoi^[i];
            if v=1 then exit;
            if den[v]=0 then
               begin
                  den[v]:=1;
                  put(v);
               end;
         end;
   until qempty;
   co:=false;
end;

procedure Cham;
var mft,u,v,w,i: longint;
    co: boolean;
begin
   fillchar(dd,sizeof(dd),0);
   readln(fo,Mfout);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   mft:=0;
   while not seekeof(fo) do
      begin
         readln(fo,u,v,w);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
          end;
          co:=false;
          for i:=tro[u] to tro[u+1]-1 do
             if cuoi^[i]=v then
                begin
                   co:=true;
                   if w<c^[i] then
                      begin
                         error[p]:=3; {Khong du quan de chan 1 duong}
                         exit;
                      end;
                   mft:=mft+c^[i];
                   dd[i]:=1;
                   break;
                end;
          if not co then
             begin
                error[p]:=4; {khong co duong de bo tri quan}
                exit;
             end;
      end;
   Ktra(co);
   if co then
      begin
         error[p]:=5; {van di den duoc 1}
         exit;
      end;
   if mft<>mfout then
      begin
         error[p]:=6; {tinh tong sai}
         exit;
      end;
   if mfout<=mfmau then diem[p]:=1.0 else diem[p]:=int(mfmau/mfout*10)/10;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Khong du quan chan 1 duong');
      4: writeln('Khong co duong bo tri quan');
      5: writeln('Van di den duoc');
      6: writeln('Tinh tong sai');
   end;
   textcolor(white);
end;

procedure Inkq;
var T: real;
begin
   clrscr;
   writeln;
   writeln;
   writeln;
   textcolor(white);
   writeln('         ********************************************************');
   writeln('         *          Ket qua cham bai BAO VE THANH PHO           *');
   writeln('         ********************************************************');
   T:=0.0;
   for p:=0 to 9 do
      begin
         write('              TEST ',p,': ',Diem[p]:4:1,' Diem.');
         InError(p);
         T:=T+diem[p];
      end;
   writeln('          --------------------------------------------------------');
   textcolor(green);
   writeln('          Tong cong = ',T:4:1,' Diem');
   textcolor(white);
end;

procedure XoaFile;
begin
   for p:=0 to 9 do
      begin
         tfo:=dtfo+chr(p+48);
         FindFirst(tfo,archive,d);
         if DosError<>0 then continue;
         assign(fo,tfo);
         erase(fo);
      end;
end;

BEGIN
   CapPhat;
   fillchar(Error,sizeof(Error),0);
   fillchar(Diem,sizeof(Diem),0);
   for p:=0 to 9 do
      begin
         tfi:=dtfi+chr(p+48);
         tfm:=dtfm+chr(p+48);
         tfo:=dtfo+chr(p+48);
         FindFirst(tfo,Archive,d);
         if DosError<>0 then
            begin
               Error[p]:=1;
               continue;
            end;
         Docdl;
         InitGraph;
         assign(fo,tfo); reset(fo);
         Cham;
         close(fo);
      end;
   Inkq;
   XoaFile;
   GiaiPhong;
END.