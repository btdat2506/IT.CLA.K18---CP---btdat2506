{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='TIGER.IN';
    dtfo='TIGER.OU';
    kqm: array[0..9,1..2] of integer=((4,4),
                                      (2,4),
                                      (2,2),
                                      (3,4),
                                      (2,2),
                                      (2,13),
                                      (4,4),
                                      (1,3),
                                      (1,1),
                                      (3,4));

    dtfm='';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   a: array[1..100,1..100] of integer;
   N,M: integer;

   sl: integer;
   x: array[1..100] of integer;

   dd: array[1..100] of byte;

procedure Docdl;
var u,v: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   M:=0;
   while not seekeof(fi) do
      begin
         inc(M);
         readln(fi,u,v);
         a[u,v]:=M;
         a[v,u]:=M;
      end;
   close(fi);
end;

procedure GhiNhanDiemCuoi(k: integer);
var i,j: integer;
begin
   for i:=1 to N-1 do
      for j:=i+1 to n do
         if a[i,j]=k then
            begin
              inc(sl);
              x[sl]:=i;
              inc(sl);
              x[sl]:=j;
            end;
end;

procedure Xoa(k: integer);
var i,j: integer;
begin
   sl:=0;
   for i:=1 to N-1 do
      for j:=i+1 to N do
         if a[i,j]=k then
            begin
                a[i,j]:=0;
                a[j,i]:=0;
            end;
end;

procedure loang(u: integer);
var v: integer;
begin
   dd[u]:=1;
   for v:=1 to N do
      if (a[u,v]<>0) and (dd[v]=0) then loang(v);
end;

function Daxoa(k: integer): boolean;
var i,j: integer;
begin
   Daxoa:=false;
   for i:=1 to N-1 do
      for j:=i+1 to N do
         if a[i,j]=k then exit;
   Daxoa:=true;
end;

function DenDuocCuoi: boolean;
var i: integer;
begin
   DenDuocCuoi:=true;
   for i:=1 to sl do
      if (x[i]>0) and (dd[x[i]]=1) then exit;
   DenDuocCuoi:=false;
end;

procedure Cham;
var k,i,kqo1, kqo2: integer;
begin
   readln(fo,kqo1);
   for i:=1 to kqo1 do
      begin
         read(fo,k);
         GhiNhanDiemCuoi(k);
         xoa(k);
      end;
   readln(fo);
   fillchar(dd,sizeof(dd),0);
   Loang(1);
   for i:=1 to sl do
      if dd[x[i]]=0 then x[i]:=1;
   if dd[N]=1 then
      begin
         error[p]:=3; {Dao ho chua chan het}
         exit;
      end;
   if kqo1>kqm[p,1] then
      begin
         error[p]:=4; {So ho chua toi uu}
         exit;
      end;
   readln(fo,kqo2);
   for i:=1 to kqo2 do
      begin
         read(fo,k);
         if daxoa(k) then
            begin
               error[p]:=5; {Doan duong dat bia khong hop le}
               exit;
            end;
         xoa(k);
      end;
   fillchar(dd,sizeof(dd),0);
   Loang(1);
   if DenDuocCuoi then
      begin
         error[p]:=6; {Den duoc ho, khong uong bia}
         exit;
      end;
   diem[p]:=0.5;
   if kqo2>kqm[p,2] then
      begin
         error[p]:=7; {Dat bia khong toi uu}
         exit;
      end;
   diem[p]:=1.0;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Dao ho chua chan het');
      4: writeln('So ho chua toi uu');
      5: writeln('Doan duong dat bia khong hop le');
      6: writeln('Den duoc ho, khong uong bia');
      7: writeln('Dat bia khong toi uu');
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
   writeln('         *          Ket qua cham bai                            *');
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