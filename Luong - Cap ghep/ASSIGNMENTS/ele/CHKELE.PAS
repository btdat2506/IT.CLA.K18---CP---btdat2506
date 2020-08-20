{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='ELE.IN';
    dtfo='ELE.OU';
    dtfm='ELE.AN';
    maxN=15;
    dh: array[1..4] of integer=(0,-1,0,1);
    dc: array[1..4] of integer=(1,0,-1,0);


var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   N: integer;
   a: array[1..maxN,1..maxN] of byte;
   Mfout,Mfmau: integer;
   ok: boolean;
   fl: array[1..maxN,1..maxN] of byte;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         for j:=1 to N do read(fi,a[i,j]);
         readln(fi);
      end;
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Mfmau);
   close(fm);
end;

procedure Cham;
var dem,u,i,k,l,k1,l1,h: integer;
    s: string;
begin
   ok:=false;
   Readln(fo,Mfout);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   if Mfout<Mfmau then exit;
   fillchar(fl,sizeof(fl),0);
   dem:=0;
   while not seekeof(fo) do
      begin
         inc(dem);
         readln(fo,s);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         u:=0;
         i:=1;
         while s[i]<>' ' do
            begin
               u:=u*10+ord(s[i])-48;
               inc(i);
            end;
         inc(i);
         k:=(u-1) div N+1;
         l:=(u-1) mod N+1;
         if a[k,l]=0 then exit;
         while i<=length(s) do
             begin
                case s[i] of
                   'E': h:=1;
                   'N': h:=2;
                   'W': h:=3;
                   'S': h:=4;
                end;
                k1:=k+dh[h];
                l1:=l+dc[h];
                if (k1<1) or (k1>n) or (l1<1) or (l1>n) then exit;
                if a[k1,l1]=1 then exit;
                if fl[k,l] and (1 shl (h-1))<>0 then exit;
                fl[k,l]:=fl[k,l] or (1 shl (h-1));
                k:=k1;
                l:=l1;
                inc(i);
             end;
         if (k<>1) and (k<>n) and (l<>1) and (l<>n) then exit;
      end;
   if dem<>Mfout then exit;
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
