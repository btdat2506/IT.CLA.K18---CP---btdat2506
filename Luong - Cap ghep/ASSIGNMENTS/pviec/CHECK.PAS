
Uses crt,Dos;

const
    f_input          =     'Pviec.inp';
    f_output         =     'Pviec.out';
    dtfi             =     'IN.';
    dtfo             =     'OUT.';
    dtfm             =     'ANS.';
    Pmin             =     1;
    Pmax             =     10;

type
   mang1=array[1..501] of byte;

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

   M,N: integer;
   a: array[1..501] of ^mang1;
   dd: array[1..501] of byte;

procedure Docdl;
var i,j,u: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to n do
      for j:=1 to m do a[i]^[j]:=0;
   for i:=1 to n do
      begin
         while not seekeoln(fi) do
            begin
               read(fi,u);
               if u<>0 then a[i]^[u]:=1;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure Cham;
var sm,so: string[2];
    kqm,kqo: longint;
    kqmax: longint;
    i,u: integer;
    dem: longint;
begin
   if Tend[p]-Tbegin[p]>Timelimit then
      begin
         error[p]:=3;
         exit;
      end;
   if seekeof(fo) then
      begin
         error[p]:=2;
         exit;
      end;
   readln(fm,sm);
   readln(fo,so);
   if sm<>so then
      begin
         error[p]:=5; {sai dap so (YES/NO)}
         exit;
      end;
   if sm='NO' then
      begin
         diem[p]:=10;
         exit;
      end;
   readln(fm,kqm);
   readln(fo,kqo);
   if kqo>kqm then
      begin
         error[p]:=4; {Khong toi uu}
         exit;
      end;
   fillchar(dd,sizeof(dd),0);
   kqmax:=0;
   for i:=1 to n do
      begin
         dem:=0;
         repeat
            read(fo,u);
            if u>m then
               begin
                  error[p]:=6; {Sai qui cach}
                  exit;
               end;
            if u>0 then
               begin
                  if dd[u]=1 then
                     begin
                        error[p]:=7; {Viec phan 2 nguoi}
                        exit;
                     end;
                  if a[i]^[u]=0 then
                     begin
                        error[p]:=10; {Viec khong the lam}
                        exit;
                     end;
                  inc(dem);
                  dd[u]:=1;
                  if dem>kqo then
                     begin
                        error[p]:=8; {Thoi gian tinh sai}
                        exit;
                     end;
               end;
         until u=0;
         readln(fo);
         if dem>kqmax then kqmax:=dem;
      end;
   if kqmax<>kqo then
      begin
         error[p]:=8;
         exit;
      end;
   for i:=1 to m do
      if dd[i]=0 then
         begin
            error[p]:=9; {Chua lam het viec}
            exit;
         end;
   diem[p]:=10;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Time=',(Tend[p]-Tbegin[p])/18.2:0:3,' s');
      4: writeln('Khong toi uu');
      5: writeln('sai dap so (YES/NO)');
      6: writeln('Sai qui cach');
      7: writeln('Viec phan 2 nguoi');
      8: writeln('Thoi gian tinh sai');
      9: writeln('Chua lam het viec');
     10: writeln('Viec khong the lam');
   end;
   textcolor(white);
end;

procedure Inkq;
var T: Integer;
begin
   clrscr;
   textcolor(white);
   writeln('KET QUA CHAM BAI  : ');
   T:=0;
   for p:=Pmin to Pmax do
      begin
         write('TEST ',p:4,': ',Diem[p]:4,' Diem.');
         InError(p);
         T:=T+diem[p];
      end;
   writeln('--------------------------------------------------------');
   textcolor(green);
   writeln('Tong cong = ',T:4,' Diem');
   textcolor(white);
   readln;
end;

procedure XoaFile;
var cp: string[2];
begin
   for p:=Pmin to Pmax do
      begin
         str(p,cp);
         if p<10 then cp:='0'+cp;
         tfo:=dtfo+cp;
         FindFirst(tfo,archive,d);
         if DosError<>0 then continue;
         assign(fo,tfo);
         erase(fo);
      end;
end;


var cp: string[2];

procedure capphat;
var i: integer;
begin
   for i:=1 to 501 do new(a[i]);
end;

procedure restoretime;
var ft: text;
begin
   assign(ft,'time.txt'); reset(ft);
   readln(ft,timelimit);
   for p:=pmin to pmax do
      readln(ft,tbegin[p],tend[p]);
   close(ft);
   erase(ft);
end;


BEGIN
   restoretime;
   CapPhat;
   fillchar(Error,sizeof(Error),0);
   fillchar(Diem,sizeof(Diem),0);
   for p:=Pmin to Pmax do
      begin
         str(p,cp);
         if p<10 then cp:='0'+cp;
         tfi:=dtfi+cp;
         tfm:=dtfm+cp;
         tfo:=dtfo+cp;
         FindFirst(tfo,Archive,d);
         if DosError<>0 then
            begin
               Error[p]:=1;
               continue;
            end;
         Docdl;
         assign(fo,tfo); reset(fo);
         assign(fm,tfm); reset(fm);
         Cham;
         close(fo); close(fm);
      end;
   Inkq;
   XoaFile;
END.
