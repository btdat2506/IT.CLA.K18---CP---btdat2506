{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='NASA.IN';
    dtfo='NASA.OU';
    dtfm='NASA.AN';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   N,M: integer;
   a,b: array[1..101] of longint;
   c: array[1..101,1..101] of byte;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,M);
   for i:=1 to N do read(fi,a[i]);
   for i:=1 to M do read(fi,b[i]);
   for i:=1 to N do
      for j:=1 to M do read(fi,c[i,j]);
   close(fi);
end;

procedure Cham;
var T1, T2, kqm,kqo: longint;
    x,y,z: array[1..101] of byte;
    u,i,j: integer;
begin
   assign(fm,tfm); reset(fm);
   read(fm,kqm);
   close(fm);
   readln(fo,kqo);
   if kqo<kqm then
      begin
         error[p]:=3;
         exit;
      end;
   fillchar(x,sizeof(x),0);
   while not seekeoln(fo) do
      begin
         read(fo,u);
         if (u<1) or (u>N) or (x[u]=1) then
            begin
               error[p]:=4;
               exit;
            end;
         x[u]:=1;
      end;
   readln(fo);
   fillchar(y,sizeof(y),0);
   while not seekeoln(fo) do
      begin
         read(fo,u);
         if (u<1) or (u>M) or (y[u]=1) then
            begin
               error[p]:=4;
               exit;
            end;
         y[u]:=1;
      end;
   T1:=0;
   for i:=1 to N do
      T1:=T1+a[i]*x[i];
   T2:=0;
   for i:=1 to M do
      T2:=T2+b[i]*y[i];
   if T1-T2<>kqo then
      begin
         error[p]:=5;
         exit;
      end;
   fillchar(z,sizeof(z),0);
   for i:=1 to N do
      if x[i]=1 then
         for j:=1 to M do
            if c[i,j]=1 then z[j]:=1;
   for i:=1 to M do
      if z[i]<>y[i] then
         begin
            error[p]:=6;
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
      3: writeln('Khong tot nhat');
      4: writeln('In sai qui cach');
      5: writeln('Tinh tong sai');
      6: writeln('In thieu hoac thua');
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