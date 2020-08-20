{$i-}
{$M $4000,0,0}
uses crt,dos;

const
    f_input          =     'HOCTRINH.INP';
    f_output         =     'HOCTRINH.OUT';
    dtfi             =     'HOCTRINH.IN';
    dtfo             =     'HOCTRINH.OU';
    dtfm             =     'HOCTRINH.AN';
    kqm: array[0..9] of longint=(382690,35593,98851,163856,223758,165828,219582,254748,327954,323172);

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo: text;
   Tbegin, Tend: array[0..9] of longint;
   time: longint absolute 0:$046c;
   TimeLimit: longint;

   N, T: integer;
   s: array[1..100] of integer;
   a: array[1..100,1..6] of integer;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,T);
   for i:=1 to N do read(fi,s[i]);
   for i:=1 to N do
      for j:=1 to 6 do read(fi,a[i,j]);
   close(fi);
end;

function Tim(i,u: integer): integer;
var k,j: integer;
begin
   k:=0;
   for j:=1 to 6 do
      if (a[i,j]<=u) then k:=j;
   Tim:=k;
end;

procedure Cham;
var TG, TD, kqo: longint;
    i,u,k: integer;
begin
   if Tend[p]-Tbegin[p]>timelimit then
      begin
         error[p]:=7;
         exit;
      end;
   readln(fo,kqo);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   TD:=0;
   TG:=0;
   for i:=1 to N do
      begin
         readln(fo,u);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         k:=Tim(i,u);
         if k=0 then
            begin
               error[p]:=3; {Co mon hoc khong du thoi gian}
               exit;
            end;
         TD:=TD+(k+4)*s[i];
         TG:=TG+u;
      end;
   if TG>T then
      begin
          error[p]:=4; {Thoi gian hoc vuot qua T}
          exit;
      end;
   if TD<>kqo then
      begin
         error[p]:=5; {Tinh tong diem hoc sai}
         exit;
      end;
   if kqo<kqm[p] then
      begin
         error[p]:=6; {Khong dat so diem max}
         diem[p]:=int(kqo/kqm[p]*10)/10;
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
      3: writeln('Co mon hoc khong du thoi gian');
      4: writeln('Thoi gian hoc vuot qua T');
      5: writeln('Tinh tong diem hoc sai');
      6: writeln('Khong dat so diem max');
      7: writeln('Time=',(Tend[p]-Tbegin[p])/19:0:3,' s');
   end;
   textcolor(white);
end;


procedure inkq;
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
begin
   clrscr;
   write('Nhap ten file chuong trinh:'); readln(Programname);
   write('Nhap thoi gian cham       :'); readln(TimeLimit);
   write('Tu    TEST                :'); readln(p1);
   write('Den   TEST                :'); readln(p2);
   TimeLimit:=TimeLimit*19;
   programname:=programname+'.EXE';
   for p:=p1 to p2 do
      begin
         writeln('Run Test:',p);
         tfi:=dtfi+chr(p+48);
         tfo:=dtfo+chr(p+48);
         CopyFile(tfi,f_input);
         SwapVectors;
         Tbegin[p]:=Time;
         Exec(Programname,'');
         Tend[p]:=Time;
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
