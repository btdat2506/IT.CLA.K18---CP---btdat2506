uses crt,dos;

const
   tfi='THUETHO.INP';
   tfo='THUETHO.OUT';
   tfk='KETQUA.TXT';
   dtfm='THUETHO.AN';
   maxN=101;

var
   fi, fo, fm: text;
   N,M: integer;
   a: array[1..maxN,0..maxN] of integer;
   b: array[1..maxN] of integer;

   error: integer;
   sotho,kqoa,kqob: integer;
   x,y: array[1..maxN] of integer;

   maua, maub: integer;


procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,M);
   for i:=1 to M do
      begin
         read(fi,b[i]);
         a[i,0]:=0;
         while not seekeoln(fi) do
            begin
               inc(a[i,0]);
               read(fi,a[i,a[i,0]]);
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure PhanTich;
var
   dd: array[1..maxN] of byte;
   i,u,j: integer;
begin
   error:=0;
   {$I-}
   assign(fo,tfo); reset(fo);
   if ioresult<>0 then
      begin
         error:=1;
         exit;
      end;
   Kqoa:=0;
   while not seekeoln(fo) do
      begin
         inc(kqoa);
         read(fo,x[kqoa]);
         if ioresult<>0 then
            begin
               error:=1;
               exit;
            end;
         if (x[kqoa]<1) or (x[kqoa]>M) then
            begin
               error:=2; {So hieu khong hop le}
               exit;
            end;
      end;
   readln(fo);
   Kqob:=0;
   while not seekeoln(fo) do
      begin
         inc(kqob);
         read(fo,y[kqob]);
         if ioresult<>0 then
            begin
               error:=1;
               exit;
            end;
         if (y[kqob]<1) or (y[kqob]>M) then
            begin
               error:=2; {So hieu khong hop le}
               exit;
            end;
      end;
   readln(fo);
   close(fo);
   {$I+}
   {Kiem tra phu cau a}
   fillchar(dd,sizeof(dd),0);
   for i:=1 to kqoa do
      begin
         u:=x[i];
         for j:=1 to a[u,0] do
            dd[a[u,j]]:=1;
      end;
   for i:=1 to N do
      if dd[i]=0 then
         begin
            error:=3; {Cau a chua phu het}
            exit;
         end;
   {Kiem tra phu cau b}
   fillchar(dd,sizeof(dd),0);
   for i:=1 to kqob do
      begin
         u:=y[i];
         for j:=1 to a[u,0] do
            dd[a[u,j]]:=1;
      end;
   for i:=1 to N do
      if dd[i]=0 then
         begin
            error:=4; {Cau B chua phu het}
            exit;
         end;
   sotho:=0;
   for i:=1 to kqob do
      sotho:=sotho+b[y[i]];
end;

procedure Inkq;
var f: text;
    DirInfo: SearchRec;
begin
   FindFirst(tfk, Archive, DirInfo);
   if DosError<>0 then
      begin
         assign(f,tfk); rewrite(f);
         close(f);
      end;
   assign(f,tfk); append(f);
   writeln(f,paramstr(1),' ',Maua,' ',MauB,' ', Kqoa,' ',sotho,' ',error);
   close(f);
end;

procedure DocMau;
var id,code: integer;
    tfm: string[12];
    st: string;
    u: integer;
    ft: text;
begin
   val(paramstr(1),id,code);
   tfm:=dtfm+chr(id+48);
   assign(fm,tfm); reset(fm);
   maua:=0;
   while not seekeoln(fm) do
      begin
         inc(maua);
         read(fm,u);
      end;
   readln(fm);
   maub:=0;
   while not seekeoln(fm) do
      begin
         read(fm,u);
         maub:=maub+b[u];
      end;
   readln(fm);
   if ((kqoa<maua) or (sotho<maub)) and (error=0) then  error:=5; {Lap ky luc !!!}
   close(fm);
   if error=5 then
      begin
         if (kqoa<maua) and (sotho<maub) then
            begin
               assign(fo,tfo); reset(fo);
               rewrite(fm);
               while not seekeof(fo) do
                  begin
                     while not seekeoln(fo) do
                        begin
                           read(fo,u);
                           write(fm,u,' ');
                        end;
                     writeln(fm);
                     readln(fo);
                  end;
               close(fm);
               close(fo);
            end
         else if kqoa<maua then {chep dong 1, de lai dong 2}
            begin
               assign(ft,'TAM.TXT'); rewrite(ft);
               assign(fo,tfo); reset(fo);
               while not seekeoln(fo) do
                  begin
                     read(fo,u);
                     write(ft,u,' ');
                  end;
               writeln(ft);
               close(fo);
               reset(fm);
               readln(fm);
               while not seekeoln(fm) do
                  begin
                     read(fm,u);
                     write(ft,u,' ');
                  end;
               writeln(ft);
               close(fm); close(ft);
               reset(ft); rewrite(fm);
               while not seekeof(ft) do
                  begin
                     while not seekeoln(ft) do
                        begin
                           read(ft,u);
                           write(fm,u,' ');
                        end;
                     readln(ft);
                     writeln(fm);
                  end;
               close(fm); close(ft);
               erase(ft);
            end
         else  (* ghi dong 2 de lai dong 1 *)
            begin
               assign(ft,'TAM.TXT'); rewrite(ft);
               reset(fm);
               while not seekeoln(fm) do
                  begin
                     read(fm,u);
                     write(ft,u,' ');
                  end;
               writeln(ft);
               close(fm);
               assign(fo,tfo); reset(fo);
               readln(fo);
               while not seekeoln(fo) do
                  begin
                     read(fo,u);
                     write(ft,u,' ');
                  end;
               writeln(ft);
               close(fo); close(ft);
               reset(ft); rewrite(fm);
               while not seekeof(ft) do
                  begin
                     while not seekeoln(ft) do
                        begin
                           read(ft,u);
                           write(fm,u,' ');
                        end;
                     readln(ft);
                     writeln(fm);
                  end;
               close(fm); close(ft);
               erase(ft);
            end;
      end;
end;

BEGIN
   Docdl;
   PhanTich;
   DocMau;
   Inkq;
END.