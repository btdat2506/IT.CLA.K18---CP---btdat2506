{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='ASSIGN.IN';
    dtfo='ASSIGN.OU';
    dtfm='';
    kqm: array[0..9,1..3] of integer=(( 11, 103, 63),
                                      (  0,  12,  5),
                                      (  0,  17, 17),
                                      (  0,  30, 19),
                                      (  0,  41, 26),
                                      (  0,  54, 28),
                                      (  0,  65, 32),
                                      (  0,  64, 48),
                                      (  8,  83, 44),
                                      ( 11,  93, 51));



var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   N: integer;
   a: array[1..3,1..200] of integer;
   PV: array[1..200] of byte;

procedure Docdl;
var i:integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do readln(fi,a[1,i],a[2,i],a[3,i]);
   close(fi);
end;

procedure Cham;
var dem,kqo: array[1..3] of integer;
    ok: boolean;
    i,j,u: integer;
begin
   fillchar(PV,sizeof(PV),0);
   readln(fo,kqo[1],kqo[2],kqo[3]);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   ok:=true;
   for i:=1 to 3 do
      if kqo[i]<>kqm[p,i] then
         begin
            ok:=false;
            break;
         end;
   if not ok then
      begin
         error[p]:=3; {So luong khong dung}
         exit;
      end;
   dem[1]:=0; dem[2]:=0; dem[3]:=0;
   for i:=1 to N do
      begin
         readln(fo,u);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         if (u<1) or (u>N) then
            begin
               error[p]:=4; {Phan cong sai}
               exit;
            end;
         if PV[u]<>0 then
            begin
               error[p]:=4;
               exit;
            end;
         ok:=false;
         for j:=1 to 3 do
            if a[j,i]=u then
               begin
                  ok:=true;
                  if j<3 then dem[j+1]:=dem[j+1]+1;
                  break;
               end;
         if not ok then dem[1]:=dem[1]+1;
         PV[u]:=i;
      end;
   ok:=true;
   for i:=1 to 3 do
      if kqo[i]<>dem[i] then
         begin
            ok:=false;
            break;
         end;
   if not ok then
      begin
         error[p]:=5; {Dem sai}
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
      3: writeln('So luong khong dung');
      4: writeln('Phan cong sai');
      5: writeln('Dem sai');
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