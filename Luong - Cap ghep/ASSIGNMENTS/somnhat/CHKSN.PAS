{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='SOMNHAT.IN';
    dtfo='SOMNHAT.OU';
    dtfm='SOMNHAT.AS';
    maxN=200;

type
   mang=array[1..maxN] of longint;

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   N,M,K: longint;
   Gr: array[1..maxN] of ^mang;
   yc: array[1..maxN,1..2] of longint;
   ST,Sout,Smau: longint;
   x: array[1..maxN] of longint;

procedure LapRap(nv,u,t1,t2,t3: longint);
var i,j: longint;
begin
   for i:=1 to N do
      if yc[i,1]=u then
         case yc[i,2] of
            1: Gr[i]^[nv]:=t1;
            2: Gr[i]^[nv]:=t2;
            3: Gr[i]^[nv]:=t3;
         end;
end;

procedure Docdl;
var i,j,r,u,t1,t2,t3: longint;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,M,K);
   for i:=1 to N do
      for j:=1 to N do Gr[i]^[j]:=-1;
   for i:=1 to N do read(fi,yc[i,1],yc[i,2]);
   for i:=1 to M do
      begin
         read(fi,r);
         for j:=1 to r do
            begin
               read(fi,u,t1,t2,t3);
               LapRap(i,u,t1,t2,t3);
            end;
      end;
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Smau);
   close(fm);
end;

procedure Cham;
var i: longint;
begin
   {Kiem tra doc file}
   readln(fo,Sout);
   if IOresult<>0 then
      begin
         Error[p]:=2;
         exit;
      end;
   if (Sout=-1) then
      begin
         if Smau<>-1 then
            begin
               Error[p]:=5; {Co nghiem, TBao VN}
               exit;
            end
         else Diem[p]:=1.0;
         exit;
      end;
   for i:=1 to N do
      begin
         readln(fo,x[i]);
         if IOresult<>0 then
            begin
               Error[p]:=2;
               exit;
            end;
         if (x[i]<1) or (x[i]>M) then
            begin
               Error[p]:=3; {du lieu khong hop le}
               exit;
            end;
      end;
   {Kiem tra dung dan}
   ST:=0;
   for i:=1 to N do
      if Gr[i]^[x[i]]>ST then ST:=Gr[i]^[x[i]];
   if ST<>Sout then
      begin
         Error[p]:=4; {thoi gian khong dung}
         exit;
      end;
   if (Smau=-1) or (Sout<=Smau) then Diem[p]:=1.0 else Diem[p]:=int(Smau/Sout*10)/10;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Du lieu sai qui cach');
      4: writeln('Tinh khong dung TG min');
      5: writeln('Co nghiem, TBao VN');
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
   writeln('         *          Ket qua cham bai THAM HOI CHO (HSGQG 2000)  *');
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
var i: longint;
begin
   for i:=1 to maxN do new(Gr[i]);
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