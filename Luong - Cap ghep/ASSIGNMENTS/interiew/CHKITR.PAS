{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='INTERIEW.IN';
    dtfo='INTERIEW.OU';
    dtfm='INTERIEW.AS';

type
   alphabet=set of 'A'..'Z';

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   N: integer;
   yc: array[1..30] of alphabet;
   M: integer;
   kn: array[1..1500] of alphabet;
   Sout,Smau: integer;
   Pout,Pmau: integer;
   dd: array[1..1500] of byte;
   ct: array[1..30] of byte;

procedure Docdl;
var i,K,u,v: integer;
    ch: char;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         yc[i]:=[];
         while not seekeoln(fi) do
            begin
               read(fi,ch);
               yc[i]:=yc[i]+[ch];
            end;
         readln(fi);
      end;
   readln(fi,M);
   for i:=1 to M do
      begin
         kn[i]:=[];
         while not seekeoln(fi) do
            begin
               read(fi,ch);
               kn[i]:=kn[i]+[ch];
            end;
         readln(fi);
      end;
   close(fi);
   Smau:=0;
   Pmau:=0;
   assign(fm,tfm); reset(fm);
   readln(fm,K);
   for i:=1 to K do
      begin
         readln(fm,u,v);
         Smau:=Smau+v;
         if v>Pmau then Pmau:=v;
      end;
   close(fm);
end;

procedure Cham;
var K,i,u,v,j,w: integer;
begin
   Sout:=0;
   Pout:=0;
   fillchar(dd,sizeof(dd),0);
   fillchar(ct,sizeof(ct),0);
   readln(fo,K);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   for i:=1 to K do
      begin
         read(fo,u,v);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         if ct[u]=1 then
            begin
               error[p]:=6; {cong ty in 2 lan}
               exit;
            end;
         ct[u]:=1;
         Sout:=Sout+v;
         if v>Pout then Pout:=v;
         if (u<1) or (u>N) or (v<1) or (v>60) then
            begin
               error[p]:=3; {Cong ty sai hoac khong du thoi gian}
               exit;
            end;
         for j:=1 to v do
            begin
               read(fo,w);
               if ioresult<>0 then
                  begin
                     error[p]:=2;
                     exit;
                  end;
               if not (yc[u]<=kn[w]) then
                  begin
                     error[p]:=4; {PV nguoi khong du yeu cau}
                     exit;
                  end;
               if dd[w]=1 then
                  begin
                     error[p]:=5; {1 nguoi PV hai lan}
                     exit;
                  end;
               dd[w]:=1;
            end;
         readln(fo);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
      end;
   if Sout>=Smau then
      begin
         Diem[p]:=0.5;
         if Pout<=Pmau then Diem[p]:=1.0;
      end
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Cong ty sai hoac khong du thoi gian');
      4: writeln('PV nguoi khong du yeu cau');
      5: writeln('1 nguoi PV hai lan');
      6: writeln('cong ty in 2 lan');
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