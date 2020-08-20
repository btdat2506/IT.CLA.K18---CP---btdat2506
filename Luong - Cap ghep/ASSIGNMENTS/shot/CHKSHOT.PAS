{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='SHOT.IN';
    dtfo='SHOT.OU';
    kqm: array[0..9] of integer=(1,1,0,1,1,1,0,1,1,1);
    dtfm='';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   Gr: array[1..2,1..1000] of integer;
   M,N: integer;

   dd: array[1..1000] of byte;

procedure Docdl;
var i,j,u: integer;
begin
   assign(fi,tfi); reset(fi);
   fillchar(Gr, sizeof(Gr),0);
   readln(fi,M,N);
   for i:=1 to M do
      begin
         for j:=1 to N do
            begin
               read(fi,u);
               if u=0 then
                  if Gr[1,j]=0 then Gr[1,j]:=i else Gr[2,j]:=i;
            end;
      end;
end;

procedure Cham;
var i,u: integer;
    so: string;
    kqo: integer;
begin
   for i:=1 to M do dd[M]:=0;
   readln(fo,so);
   while (length(so)>0) and (so[1]=' ') do delete(so,1,1);
   while (length(so)>0) and (so[length(so)]=' ') do delete(so,length(so),1);
   if (so<>'YES') and (so<>'NO') then
      begin
         error[p]:=3; {Thong bao Khong hop le}
         exit;
      end;
   if so='YES' then kqo:=1 else kqo:=0;
   if kqo=1 then
      begin
         for i:=1 to N do
            begin
               readln(fo,u);
               if (u<1) or (u>M) then
                  begin
                     error[p]:=4; {Ban ra ngoai bia}
                     exit;
                  end;
               if (Gr[1,i]<>u) and (Gr[2,i]<>u) then
                  begin
                     error[p]:=7; {Ban vao o den}
                     exit;
                  end;
               dd[u]:=1;
            end;
         for i:=1 to M do
            if dd[i]=0 then
               begin
                  error[p]:=5; {Co hang chua duoc ban}
                  exit;
               end;
      end
   else if kqm[p]=1 then
      begin
         error[p]:=6; {Co phuong an. Thong bao NO}
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
      3: writeln('Thong bao Khong hop le');
      4: writeln('Ban ra ngoai bia');
      5: writeln('Co hang chua duoc ban');
      6: writeln('Co phuong an. Thong bao NO');
      7: writeln('Ban vao o den');
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