uses crt,dos;

const
   tfi='ATHLETE.INP';
   tfo='ATHLETE.OUT';
   tfk='KETQUA.TXT';
   dtfm='ATHLETE.AN';

var
   fi, fo, fm: text;
   error: integer;

   N,M,K: integer;
   a: array[1..21,1..21] of integer;

   Tout,Tmau: longint;
   x: array[1..2,1..21] of integer;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,M);
   for i:=1 to N do
      begin
         for j:=1 to M do read(fi,a[i,j]);
         readln(fi);
      end;
   read(fi,K);
   close(fi);
end;

procedure PhanTich;
var i,j: integer;
    T: longint;
begin
   error:=0;
   {$I-}
   assign(fo,tfo); reset(fo);
   if ioresult<>0 then
      begin
         error:=1;
         exit;
      end;
   readln(fo,Tout);
   if ioresult<>0 then
      begin
         error:=1;
         exit;
      end;
   for i:=1 to K do
      begin
         readln(fo,x[1,i],x[2,i]);
         if ioresult<>0 then
            begin
               error:=1;
               exit;
            end;
         exit;
      end;
   close(fo);
   {$I+}
   {Kiem tra cac van dong vien khac nhau va cac mon khac nhau}
   for i:=1 to K do
      begin
         if (x[1,i]<1) or (x[1,i]>N) or (x[2,i]<1) or (x[2,i]>M) then
            begin
               error:=2;
               exit;
            end;
         for j:=i-1 downto 1 do
            if (x[1,j]=x[1,i]) or (x[2,j]=x[2,i]) then
               begin
                  error:=3;
                  exit;
               end;
      end;
   {Kiem tra tinh tong dung khong}
   T:=0;
   for i:=1 to K do
      T:=T+a[x[1,i],x[2,i]];
   if T<>Tout then
      begin
         error:=4;
         exit;
      end;
end;

procedure inkq;
var
    DirInfo: SearchRec;
    f: text;
begin
   FindFirst(tfk, Archive, DirInfo);
   if DosError<>0 then
      begin
         assign(f,tfk); rewrite(f);
         close(f);
      end;
   assign(f,tfk); append(f);
   writeln(f,paramstr(1),' ',Tmau,' ',Tout,' ',error);
   close(f);
end;

procedure DocMau;
var
   id, code: integer;
   tfm: string[12];
   st: string;
begin
   val(paramstr(1),id,code);
   tfm:=dtfm+chr(id+48);
   assign(fm,tfm); reset(fm);
   readln(fm,Tmau);
   close(fm);
   if (error=0) and (Tout>Tmau) then error:=5;
   if error=5 then
      begin
         assign(fo,tfo); reset(fo);
         rewrite(fm);
         while not seekeof(fo) do
            begin
               readln(fo,st);
               writeln(fm,st);
            end;
         close(fo); close(fm);
      end;
end;

BEGIN
   Docdl;
   PhanTich;
   DocMau;
   Inkq;
END.