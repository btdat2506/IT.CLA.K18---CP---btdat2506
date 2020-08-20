
{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='TIEPTHI.IN';
    dtfo='TIEPTHI.OU';
    dtfm='TIEPTHI.AN';
    maxN=200;
    kqm: array[0..9] of longint=(0,8,99,173,375,705,530,651,5757,29340);

type
   mang=array[1..maxN] of longint;

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   N,K: integer;
   c: array[1..maxN] of ^mang;
   dau,cuoi: array[1..maxN] of integer;

   kqo: longint;

   xp, kt: array[1..maxN] of byte;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,K);
   for i:=1 to N do
      begin
         for j:=1 to N do read(fi,c[i]^[j]);
         readln(fi);
      end;
   for i:=1 to K do read(fi,dau[i]);
   readln(fi);
   for i:=1 to K do read(fi,cuoi[i]);
   close(fi);
end;

procedure Cham;
var tong: longint;
    i,u,ut: integer;
begin
   readln(fo,kqo);
   fillchar(xp,sizeof(xp),0);
   fillchar(kt,sizeof(kt),0);
   Tong:=0;
   for i:=1 to K do
      begin
         read(fo,u);
         if (u<1) or (u>N) then
            begin
               error[p]:=7; {Ten dia diem sai}
               exit;
            end;
         if xp[u]<>0 then
            begin
               error[p]:=4; {Mot nguoi di chuyen 2 lan}
               exit;
            end;
         xp[u]:=1;
         if seekeoln(fo) then
            begin
               error[p]:=5; {hanh trinh sai}
               exit;
            end;
         while not seekeoln(fo) do
            begin
               ut:=u;
               read(fo,u);
               if (u<1) or (u>N) then
                  begin
                     error[p]:=7; {Ten dia diem sai}
                     exit;
                  end;
               Tong:=Tong+c[ut]^[u];
            end;
         if kt[u]<>0 then
            begin
               error[p]:=6; {1 dia diem den 2 nguoi}
               exit;
            end;
         kt[u]:=1;
         readln(fo);
      end;
   if Tong<>kqo then
      begin
         error[p]:=8; {Tinh tong do dai sai}
         exit;
      end;
   for i:=1 to K do
      if xp[dau[i]]=0 then
         begin
            error[p]:=9; {van con nguoi chua di}
            exit;
         end;
   for i:=1 to K do
      if kt[cuoi[i]]=0 then
         begin
             error[p]:=10; {van con noi chua den}
             exit;
         end;
   diem[p]:=0.2;
   if kqo>kqm[p] then
      begin
         error[p]:=3; {Khong toi uu}
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
      3: writeln('Khong toi uu');
      4: writeln('Mot nguoi di chuyen 2 lan');
      5: writeln('hanh trinh sai');
      6: writeln('1 dia diem den 2 nguoi');
      7: writeln('Ten dia diem sai');
      8: writeln('Tinh tong do dai sai');
      9: writeln('van con nguoi chua di');
     10: writeln('van con noi chua den');
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
   for i:=1 to maxN do new(c[i]);
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