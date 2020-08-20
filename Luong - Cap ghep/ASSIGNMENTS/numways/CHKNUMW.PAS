{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='NUMWAYS.IN';
    dtfo='NUMWAYS.OU';
    dtfm='NUMWAYS.AS';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   a: array[1..50,1..10,1..50] of byte;
   N,M: integer;
   Smau,Sout: integer;

procedure Docdl;
var i,j,k,l,u: integer;
begin
   assign(fi,tfi); reset(fi);
   fillchar(a,sizeof(a),0);
   readln(fi,N,M);
   for j:=1 to M-1 do
      for i:=1 to N do
         begin
            read(fi,k);
            for l:=1 to k do
               begin
                  read(fi,u);
                  a[i,j,u]:=1;
               end;
            readln(fi);
         end;
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Smau);
   close(fm);
end;

procedure Cham;
var dd: array[1..50,1..10] of byte;
    i,j,u,v: integer;
begin
   readln(fo,Sout);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   fillchar(dd,sizeof(dd),0);
   for i:=1 to Sout do
      begin
         read(fo,u);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         if (u<1) or (u>n) then
            begin
               error[p]:=3; {Duong di khong hop le}
               exit;
            end;
         if dd[u,1]=1 then
            begin
               error[p]:=4; {Hai duong di qua 1 dinh}
               exit;
            end;
         dd[u,1]:=1;
         for j:=2 to m do
            begin
               read(fo,v);
               if ioresult<>0 then
                  begin
                     error[p]:=2;
                     exit;
                  end;
               if (v<1) or (v>n) then
                  begin
                     error[p]:=3;
                     exit;
                  end;
               if (dd[v,j]=1) then
                  begin
                     error[p]:=4;
                     exit;
                  end;
               if a[u,j-1,v]=0 then
                  begin
                     error[p]:=5; {Di tren cung =0}
                     exit;
                  end;
               dd[v,j]:=1;
               u:=v;
            end;
         readln(fo);
      end;
   if Sout<Smau then
      begin
         error[p]:=6; {So duong khong toi uu}
         exit;
      end;
   Diem[p]:=1.0;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Duong di khong hop le');
      4: writeln('Hai duong di qua 1 dinh');
      5: writeln('Di tren cung =0');
      6: writeln('So duong khong toi uu');
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
   writeln('         *          Ket qua cham bai NUMWAYS                    *');
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
         tfm:=dtfm+chr(p+48);
         tfo:=dtfo+chr(p+48);
         tfi:=dtfi+chr(p+48);
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