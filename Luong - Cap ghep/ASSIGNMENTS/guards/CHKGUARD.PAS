{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='GUARDS.IN';
    dtfo='GUARDS.OU';
    dtfm='GUARDS.AN';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   m,n: integer;
   a: array[1..200,1..200] of byte;
   Sout,Smau: integer;
   ok: boolean;


procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,m,n);
   for i:=1 to m do
      begin
         for j:=1 to n do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Smau);
   close(fm);
end;

procedure Dat(u,v: integer);
var i: integer;
begin
   for i:=v to n do
      begin
         if a[u,i]=2 then break;
         a[u,i]:=3;
      end;
   for i:=v downto 1 do
      begin
         if a[u,i]=2 then break;
         a[u,i]:=3;
      end;
   for i:=u downto 1 do
      begin
         if a[i,v]=2 then break;
         a[i,v]:=3;
      end;
   for i:=u to m do
      begin
         if a[i,v]=2 then break;
         a[i,v]:=3;
      end;
end;

procedure Cham;
var i,u,v: integer;
begin
   ok:=false;
   readln(fo,Sout);
   if ioresult<>0 then exit;
   if Sout<Smau then exit;
   for i:=1 to Sout do
      begin
         readln(fo,u,v);
         if ioresult<>0 then exit;
         if (a[u,v]<>0) then exit;
         Dat(u,v);
      end;
   ok:=true;
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
