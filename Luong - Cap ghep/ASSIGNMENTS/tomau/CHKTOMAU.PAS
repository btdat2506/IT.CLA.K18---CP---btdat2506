{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='TOMAU.IN';
    dtfo='TOMAU.OU';
    dtfm='';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   M,N: integer;
   a: array[1..101,1..101] of byte;

   xanh, vang: array[1..201] of integer;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         for j:=1 to N do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
end;

procedure Cham;
var i,j: integer;
    ch: char;
begin
   for i:=1 to M+N do xanh[i]:=0;
   for i:=1 to M+N do vang[i]:=0;
   for i:=1 to M do
      begin
         for j:=1 to N do
            begin
               read(fo,ch);
               case ch of
                  'D': begin
                          if a[i,j]=0 then
                             begin
                                 error[p]:=3; {Khong dung mau DEN}
                                 exit;
                              end;
                       end;
                  'X': begin
                          if a[i,j]=1 then
                             begin
                                error[p]:=4; {To vao do DEN}
                                exit;
                             end;
                          xanh[i]:=xanh[i]+1;
                          xanh[j+M]:=xanh[j+M]+1;
                       end;
                  'V': begin
                          if a[i,j]=1 then
                             begin
                                error[p]:=4; {To vao o DEN}
                                exit;
                             end;
                          vang[i]:=vang[i]+1;
                          vang[j+M]:=vang[j+M]+1;
                       end;
                  else
                       begin
                          error[p]:=5; {Mau dung khong hop le}
                          exit;
                       end;
               end;
            end;
         readln(fo);
      end;
   for i:=1 to M+N do
      if abs(xanh[i]-vang[i])>1 then
         begin
            error[p]:=6; {Do chenh mau >1}
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
      3: writeln('Mau dung khong hop le');
      4: writeln('To vao do DEN');
      5: writeln('Mau dung khong hop le');
      6: writeln('Do chenh mau >1');
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
