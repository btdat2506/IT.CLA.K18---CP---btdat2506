{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
uses crt;

var tt: integer;
    tfi,tfo,tfm: string[12];
    Error: array[0..9] of integer;
    Diem : array[0..9] of real;
    fi,fo,fm: text;
    a: array[1..100,1..50] of integer;
    DN: array[1..100] of integer;
    N,P,K: integer;
    max: array[1..50] of integer;
    x: array[1..50] of integer;
    dd: array[1..100] of integer;
    d1: array[1..50] of integer;

procedure Docdl;
var i,j,l,u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N,P,K);
   for i:=1 to N do
      begin
         read(fi,DN[i]);
         read(fi,l);
         for j:=1 to l do
            begin
               read(fi,u);
               a[i,u]:=1;
            end;
         readln(fi);
      end;
   for i:=1 to P do read(fi,max[i]);
   close(fi);
end;


procedure Dockq;
var i: integer;
begin
   if tt=1 then
      begin
         read(fo,x[1]);
         exit;
      end;
   for i:=1 to K do read(fo,x[i]);
end;

procedure Cham;
var i: integer;
begin
   if (tt=1) then
      begin
         if x[1]<>-1 then  Error[tt]:=7 else Diem[tt]:=1;
         exit;
      end;
   for i:=1 to K do
      if (x[i]<1) or (x[i]>N) then
         begin
            Error[tt]:=6;
            exit;
         end;
   fillchar(dd,sizeof(dd),0);
   fillchar(d1,sizeof(d1),0);
   for i:=1 to K do
      begin
         if dd[x[i]]=1 then
            begin
               Error[tt]:=2;
               exit;
            end;
         if a[x[i],i]=0 then
            begin
               Error[tt]:=3;
               exit;
            end;
         dd[x[i]]:=1;
         d1[DN[x[i]]]:=d1[DN[x[i]]]+1;
      end;
   for i:=1 to P do
      if d1[i]=0 then
         begin
            Error[tt]:=4;
            exit;
         end;
   for i:=1 to P do
      if d1[i]>max[i] then
         begin
            Error[tt]:=5;
            exit;
         end;
   Diem[tt]:=1.0;
end;

procedure InError(i: integer);
begin
   case Error[i] of
      0: write('Ket qua DUNG                             ');
      1: write('Khong co file ket qua                    ');
      2: write('Mot nguoi dai dien hai lan               ');
      3: write('Chon nguoi cho CLB khong dung            ');
      4: write('Co DN khong co nguoi dai dien            ');
      5: write('Co DN co nhieu nguoi dai dien qua        ');
      6: write('Cu nguoi khong trong pham vi 1..N        ');
      7: write('TEST 1: Vo nghiem');
   end;
end;

procedure Inkq;
var S: real;
    i,k: integer;
begin
   S:=0;
   for i:=0 to 9 do S:=S+diem[i];
   clrscr;
   writeln('          **********************************************************');
   writeln('          *             KET QUA CHAM BAI THUE MAY - BAI SO 2       *');
   writeln('          **********************************************************');
   writeln('          | TEST |      Ket qua cham                       | Diem  |');
   writeln('          |------|-----------------------------------------|-------|');
   for k:=1 to 10 do
      begin
         i:=k mod 10;
         write('          |',i:4,'  |');
         InError(i);
         writeln('|',Diem[i]:6:2,' |');
      end;
   writeln('          |------------------------------------------------|-------|');
   writeln('          |                  TONG  DIEM                    |',S:6:2,' |');
   writeln('          **********************************************************');
   writeln;
   writeln('Da xoa tat ca cac fil ket qua!');
   writeln;
   writeln('Bam ENTER de tiep tuc....');
   Readln;
end;


BEGIN
   for tt:=0 to 9 do
      begin
         tfi:='COUNCIL.IN'+chr(tt+48);
         tfo:='COUNCIL.OU'+chr(tt+48);
         Error[tt]:=0; {Khong co loi}
         Diem[tt]:=0;
         {$I-}
         assign(fo,tfo); reset(fo);
         if IOResult<>0 then
            begin
               {$I+}
               Error[tt]:=1; {khong co fil ket qua}
               continue
            end;
         {$I+}
         Docdl;
         Dockq;
         Cham;
         close(fo);
         erase(fo);
      end;
   Inkq;
END.