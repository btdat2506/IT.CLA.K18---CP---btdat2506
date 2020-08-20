{Free Pascal}
{$i-}
{$M $4000,0,0}
uses crt,dos;

const
    f_input          =     'NANGCAP.INP';
    f_output         =     'NANGCAP.OUT';
    dtfi             =     'NANGCAP.IN';
    dtfo             =     'NANGCAP.OU';
    dtfm             =     'NANGCAP.AN';
    kqm: array[0..9] of longint=(12,3,4,8,6,6,9,9,11,11);
    maxn             =     201;

type
   mang1=array[1..maxn] of longint;
   mang2=array[1..maxn] of integer;

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   Tbegin, Tend: array[0..9] of longint;
   TimeLimit: longint;

   N: integer;
   s,t: mang1;
   dis: array[1..maxn] of mang1;

procedure Docdl;
var k,i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N);
   for i:=1 to n do read(fi,s[i]);
   for i:=1 to N do read(fi,t[i]);
   for i:=1 to n do
      for j:=1 to n do read(fi,dis[i,j]);
   close(fi);
   {floy}
   for k:=1 to N do
      for i:=1 to N do
         if (i<>k) then
            for j:=1 to N do
               if (j<>i) and (j<>k) and (dis[i,j]>dis[i,k]+dis[k,j]) then
                  dis[i,j]:=dis[i,k]+dis[k,j];
end;

procedure Cham;
var kqo: longint;
    dd: mang2;
    dem,i,j: integer;
    x: mang2;
    solx: integer;
begin
   if tend[p]-tbegin[p]>timelimit then
      begin
         error[p]:=3;
         exit;
      end;
   readln(fo,kqo);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   if kqo>kqm[p] then
      begin
         error[p]:=4; {Khong toi uu}
         exit;
      end;
   fillchar(dd,sizeof(dd),0);
   dem:=0;
   for i:=1 to kqo do
      begin
         read(fo,solx);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         if solx=0 then
            begin
               error[p]:=5;
               exit;
            end;
         for j:=1 to solx do
            begin
               read(fo,x[j]);
               if (x[j]<1) or (x[j]>N) then
                  begin
                     error[p]:=5;
                     exit;
                  end;
               if ioresult<>0 then
                  begin
                     error[p]:=2;
                     exit;
                  End;
               if dd[x[j]]=1 then
                  begin
                     error[p]:=5; {In ket qua sai}
                     exit;
                  end;
               dd[x[j]]:=1;
               inc(dem);
            end;
         readln(fo);
         for j:=2 to solx do
            if s[x[j-1]]+t[x[j-1]]+dis[x[j-1],x[j]]>s[x[j]] then
               begin
                  error[p]:=6; {Khong the hoan thanh}
                  exit;
               end;
      end;
   if dem<>N then
       begin
          error[p]:=8; {khong nang cap het}
          exit;
       end;
   if kqo<kqm[p] then error[p]:=7; {lap ky luc}
   diem[p]:=1.0;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Time=',(Tend[p]-Tbegin[p])/100:0:2,' s');
      4: writeln('Khong toi uu');
      5: writeln('In ket qua sai');
      6: writeln('Khong the hoan thanh');
      7: writeln('lap ky luc');
      8: writeln('khong nang cap het');
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
   readln;
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

procedure CopyFile(f1,f2: string);
var
  FromF, ToF: file;
  NumRead, NumWritten: Word;
  Buf: array[1..2048] of Char;
begin
  {$i-}
  Assign(FromF, f1); { Open input file }
  Reset(FromF, 1);  { Record size = 1 }
  if ioresult<>0 then exit;
  Assign(ToF, f2); { Open output file }
  Rewrite(ToF, 1);  { Record size = 1 }
  repeat
    BlockRead(FromF, Buf, SizeOf(Buf), NumRead);
    BlockWrite(ToF, Buf, NumRead, NumWritten);
  until (NumRead = 0) or (NumWritten <> NumRead);
  Close(FromF);
  Close(ToF);
end;

procedure Delfile(tf: string);
var f: file;
begin
   FindFirst(tf,archive,d);
   if DosError<>0 then exit;
   assign(f,tf);
   erase(f);
end;


procedure Run;
var programname: string;
    p1,p2: integer;
    gio,phut,giay,giay100: word;
begin
   clrscr;
   write('Nhap ten file chuong trinh:'); readln(Programname);
   write('Nhap thoi gian cham       :'); readln(TimeLimit);
   write('Tu    TEST                :'); readln(p1);
   write('Den   TEST                :'); readln(p2);
   TimeLimit:=TimeLimit*100;
   programname:=programname+'.EXE';
   for p:=p1 to p2 do
      begin
         writeln('Run Test:',p);
         tfi:=dtfi+chr(p+48);
         tfo:=dtfo+chr(p+48);
         CopyFile(tfi,f_input);
         SwapVectors;
         GetTime(gio,phut,giay,giay100);
         Tbegin[p]:=longint(giay100)+longint(giay)*100+longint(phut)*6000+longint(gio)*360000;
         Exec(Programname,'');
         GetTime(gio,phut,giay,giay100);
         Tend[p]:=longint(giay100)+longint(giay)*100+longint(phut)*6000+longint(gio)*360000;;
         SwapVectors;
         CopyFile(f_output,tfo);
         DelFile(f_output);
      end;
   DelFile(f_input);
end;


BEGIN
   Run;
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
