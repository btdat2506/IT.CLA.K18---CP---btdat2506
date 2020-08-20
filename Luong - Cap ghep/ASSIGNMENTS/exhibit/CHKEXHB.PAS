{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='EXHIBIT.IN';
    dtfo='EXHIBIT.OU';
    dtfm='';

type
   mang=array[1..200] of byte;

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   M,N: integer;
   a: array[1..200] of ^mang;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         for j:=1 to N do read(fi,a[i]^[j]);
         readln(fi);
      end;
   close(fi);
end;

function Cot(i: integer): boolean;
var k: integer;
    dd: array[1..200] of byte;
begin
   cot:=false;
   for k:=1 to N do dd[k]:=0;
   for k:=1 to N do
      begin
         if dd[a[k]^[i]]>0 then exit;
         dd[a[k]^[i]]:=1;
      end;
   cot:=true;
end;

function Hang(i: integer): boolean;
var k: integer;
    dd: array[1..200] of byte;
begin
   Hang:=false;
   for k:=1 to N do dd[k]:=0;
   for k:=1 to N do
      begin
         if dd[a[i]^[k]]>0 then exit;
         dd[a[i]^[k]]:=1;
      end;
   Hang:=true;
end;

procedure Cham;
var kqo,i,j: integer;
begin
   readln(fo,kqo);
   if kqo<>N-M then
      begin
         error[p]:=3; {So hang them vao khong dung!'}
         exit;
      end;
   for i:=M+1 to N do
      begin
         for j:=1 to N do read(fo,a[i]^[j]);
         readln(fo);
      end;
   for i:=M+1 to N do
      for j:=1 to N do
         if (a[i]^[j]<1) or (a[i]^[j]>N) then
            begin
               error[p]:=4; {Loai hoa chon sai}
               exit;
            end;
   for i:=1 to N do
      if not Cot(i) then
         begin
            error[p]:=5; {co cot torng hoa sai}
            exit;
         end;
   for i:=M+1 to N do
      if not Hang(i) then
         begin
            error[p]:=6; {co hang torng hoa sai}
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

procedure CapPhat;
var i: integer;
begin
   for i:=1 to 200 do new(a[i]);
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
         assign(fo,tfo); reset(fo);
         Cham;
         close(fo);
      end;
   Inkq;
   XoaFile;
END.