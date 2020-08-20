{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='CHESS.IN';
    dtfo='CHESS.OU';
    dtfm='';
    kq: array[0..9] of longint=(1832,14,376,564,722,960,1152,1344,1570,1736);

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   N: integer;
   a,b,x: array[1..1000] of longint;

procedure Docdl;
var i: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do readln(fi,a[i],b[i]);
   close(fi);
end;

procedure Cham;
var Tout: longint;
    dd: array[1..1000] of byte;
    i: integer;
    T: longint;
begin
   readln(fo,Tout);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   fillchar(dd,sizeof(dd),0);
   for i:=1 to N do
      begin
         readln(fo,x[i]);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         if (x[i]<1) and (x[i]>n) then
            begin
               error[p]:=3; {so hieu khong dung}
               exit;
            end;
         if dd[x[i]]=1 then
            begin
               error[p]:=4; {trung cap dau}
               exit;
            end;
         dd[x[i]]:=1;
      end;
   T:=0;
   for i:=1 to N do
     if a[i]<b[x[i]] then inc(T,2) else
       if a[i]=b[x[i]] then inc(T,1);
   if T<>Tout then
      begin
         error[p]:=5; {tinh tong diem khong dung}
         exit;
      end;
   if Tout<Kq[p] then
      begin
         diem[p]:=0.3;
         error[p]:=6; {Khong toi uu}
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
   writeln('         *               KET QUA CHAM BAI                       *');
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