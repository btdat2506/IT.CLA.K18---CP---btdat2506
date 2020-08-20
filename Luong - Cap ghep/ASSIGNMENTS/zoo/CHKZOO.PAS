{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='ZOO.IN';
    dtfo='ZOO.OU';
    dtfm='ZOO.AS';
    dh: array[1..4] of integer=(-1,0,1,0);
    dc: array[1..4] of integer=(0,-1,0,1);

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   M,N,x,y,t: integer;
   dd: array[1..50,1..50] of byte;
   RN,RaNgoai: boolean;
   a: array[1..50,1..50] of byte;
   Smau,Sout: LongInt;
   q: array[1..2,1..2500] of integer;
   qf,ql: integer;

function RaDuoc(i,j: integer): boolean;
begin
   RaDuoc:=True;
   if (i=1) and ((a[i,j] and 1)=0) then exit;
   if (i=M) and ((a[i,j] and 4)=0) then exit;
   if (j=1) and ((a[i,j] and 2)=0) then exit;
   if (j=N) and ((a[i,j] and 8)=0) then exit;
   RaDuoc:=false;
end;

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

function Cua(i,j,k: integer): boolean;
begin
   Cua:=(a[i,j] and (1 shl (k-1)))=0;
end;

function Inside(i,j: integer): boolean;
begin
   Inside:=(i>=1) and (i<=M) and (j>=1) and (j<=N);
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
                  if dd[ii,jj]<>1 then dd[ii,jj]:=2;
               end;
   for i:=1 to M do
      for j:=1 to N do
         if dd[i,j]=2 then dd[i,j]:=1;
end;

procedure DanhDauXP;
var i: integer;
begin
   Fillchar(dd,sizeof(dd),0);
   dd[x,y]:=1;
   RaNgoai:=false;
   for i:=1 to T do
      begin
         MoRong;
         if RaNgoai then exit;
      end;
end;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N,x,y,t);
   for i:=1 to M do
      for j:=1 to N do read(fi,a[i,j]);
   DanhDauXP;
   if not RaNgoai then
      begin
         assign(fm,tfm); reset(fm);
         readln(fm,Smau);
         close(fm);
      end
   else Smau:=-1;
   close(fi);
end;

procedure Loang;
var i,j,k,ii,jj: integer;
begin
   initQ;
   for i:=1 to M do
      for j:=1 to N do
         if dd[i,j]=1 then Put(i,j);
   while not Qempty do
      begin
         Get(i,j);
         for k:=1 to 4 do
            if Cua(i,j,k) then
               begin
                  ii:=i+dh[k];
                  jj:=j+dc[k];
                  if not inside(ii,jj) then
                     begin
                        RN:=true;
                        exit;
                     end;
                  if (dd[ii,jj]=0) then
                     begin
                        Put(ii,jj);
                        dd[ii,jj]:=1;
                     end;
               end;
      end;
end;

procedure Cham;
var i: integer;
    ch: char;
begin
   readln(fo,Sout);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   if ((Sout=-1) and (Smau<>-1)) or (Sout>Smau) then
      begin
         error[p]:=3; {so cua dong khong toi uu}
         exit;
      end;
   if Sout<>-1 then
      begin
         for i:=1 to Sout do
            begin
               read(fo,x,y);
               if ioresult<>0 then
                  begin
                     error[p]:=2;
                     exit;
                  end;
               repeat read(fo,ch) until ch<>' ';
               if not (ch in ['B','T','N','D']) then
                  begin
                     error[p]:=4; {in sai qui cach}
                     exit;
                  end;
               readln(fo);
               case ch of
                  'B': a[x,y]:=a[x,y] or 1;
                  'T': a[x,y]:=a[x,y] or 2;
                  'N': a[x,y]:=a[x,y] or 4;
                  'D': a[x,y]:=a[x,y] or 8;
               end;
            end;
      end;
   if Not RaNgoai then
      begin
         RN:=false;
         Loang;
         if RN then
            begin
               error[p]:=5; {van chay thoat}
               exit;
            end;
      end;
   Diem[p]:=1.0;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('So cua dong khong toi uu');
      4: writeln('In sai qui cach');
      5: writeln('van chay thoat');
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
   writeln('         *          Ket qua cham bai    ZOO                     *');
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
         assign(fo,tfo); reset(fo);
         Cham;
         close(fo);
      end;
   Inkq;
   XoaFile;
END.