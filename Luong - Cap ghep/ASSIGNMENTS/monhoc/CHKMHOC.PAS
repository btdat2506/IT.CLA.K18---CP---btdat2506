{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='MONHOC.IN';
    dtfo='MONHOC.OU';
    kqm: array[0..9] of integer=(25,3,4,3,7,9,11,17,19,19);
    dtfm='';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   Gr: array[1..100,1..100] of byte;
   a: array[1..100] of integer;
   M,N: integer;

procedure Docdl;
var i,j: integer;
begin
   fillchar(Gr,sizeof(Gr),0);
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         read(fi,a[i]);
         while not seekeoln(fi) do
            begin
               read(fi,j);
               Gr[i,j]:=1;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure Cham;
var kqo,i,j,dem: integer;
    b: array[1..100] of integer;
    tyle: real;
begin
   fillchar(b,sizeof(b),0);
   readln(fo,kqo);
   for i:=1 to N do
      begin
         dem:=0;
         read(fo,j);
         if j>0 then
            begin
               inc(dem);
               if (j>M) or (Gr[j,i]=0) then
                  begin
                     error[p]:=3; {Chon mon khong phu hop}
                     exit;
                  end;
               b[j]:=b[j]+1;
               while not seekeoln(fo) do
                  begin
                     read(fo,j);
                     if (j=0) or (j>M) then
                        begin
                           error[p]:=3;
                           exit;
                        end;
                     inc(dem);
                     b[j]:=b[j]+1;
                  end;
               if dem>kqo then
                  begin
                     error[p]:=4; {Tinh ket qua sai}
                     exit;
                  end;
            end;
         readln(fo);
      end;
   for j:=1 to M do
      if b[j]<a[j] then
         begin
            error[p]:=5; {Hoc khong du yeu cau}
            exit;
         end;
   tyle:=kqo/kqm[p];
   if tyle<=1.0 then diem[p]:=1.0 else
      if tyle<=1.01 then diem[p]:=0.5 else
         if tyle<=1.02 then diem[p]:=0.4 else
            if tyle<=1.03 then diem[p]:=0.3 else
               if tyle<=1.04 then diem[p]:=0.2 else
                  if tyle<=1.05 then diem[p]:=0.1;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Chon mon khong phu hop');
      4: writeln('Tinh ket qua sai');
      5: writeln('Hoc khong du yeu cau');
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