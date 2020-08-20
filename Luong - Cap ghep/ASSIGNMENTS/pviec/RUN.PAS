{$M $4000,0,0}

Uses crt,Dos;

const
    f_input          =     'Pviec.inp';
    f_output         =     'Pviec.out';
    dtfi             =     'IN.';
    dtfo             =     'OUT.';
    dtfm             =     'ANS.';
    Pmin             =     1;
    Pmax             =     10;

var
   Error: array[Pmin..Pmax] of integer;
   Diem: array[Pmin..Pmax]  of integer;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   Tbegin, Tend: array[Pmin..Pmax] of longint;
   TimeLimit: longint;
   Time: longint absolute 0:$046c;

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
    cp: string[2];
begin
   clrscr;
   write('Nhap ten file chuong trinh:'); readln(Programname);
   write('Nhap thoi gian cham (s)   :'); readln(TimeLimit);
   write('Tu    TEST                :'); readln(p1);
   write('Den   TEST                :'); readln(p2);
   TimeLimit:=TimeLimit*19;
   programname:=programname+'.EXE';
   for p:=p1 to p2 do
      begin
         writeln('Run Test:',p);
         str(p,cp);
         if p<10 then cp:='0'+cp;
         tfi:=dtfi+cp;
         tfo:=dtfo+cp;
         CopyFile(tfi,f_input);
         SwapVectors;
         TBegin[p]:= Time;
         Exec(Programname,'');
         TEnd[p]:= Time;
         SwapVectors;
         CopyFile(f_output,tfo);
         DelFile(f_output);
      end;
   DelFile(f_input);
end;

var cp: string[2];
    ft: text;

procedure savetime;
begin
   assign(ft,'Time.TXT'); rewrite(ft);
   writeln(ft,timelimit);
   for p:=pmin to pmax do
      writeln(ft,Tbegin[p],' ',Tend[p]);
   close(ft);
end;


BEGIN
   Run;
   savetime;
END.
