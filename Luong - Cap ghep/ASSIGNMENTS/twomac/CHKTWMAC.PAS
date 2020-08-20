{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='TWOMAC.IN';
    dtfo='TWOMAC.OU';
    dtfm='TWOMAC.AN';
    BatDau: array[0..9] of integer=(60,7,16,21,30,34,36,43,55,59);

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;

   a: array[1..100,1..100] of byte;
   N: integer;

   kqm, kqo: array[0..9] of integer;
   M: integer;
   x: array[1..100,1..2] of integer;

   ok: boolean;

   time: array[1..100] of integer;

   KyLuc: boolean;


procedure Docdl;
var i,u: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   for i:=1 to N do
      begin
         read(fi,u);
         if u=0 then
            begin
               readln(fi);
               continue;
            end;
         a[u,i]:=1;
         while not seekeoln(fi) do
            begin
               read(fi,u);
               a[u,i]:=1;
            end;
         readln(fi);
      end;
   close(fi);
end;

procedure Check;
var i,j: integer;
begin
   fillchar(time,sizeof(time),0);
   ok:=false;
   (* Bo tri may dung khong *)
   for i:=1 to N do
      if (x[i,1]<>1) and (x[i,1]<>2) then
         begin
            error[p]:=5; {Phan may khong dung}
            exit;
         end;

   for i:=1 to N do
      begin
         time[i]:=x[i,2];
         if (time[i]<0) or (time[i]>kqo[p]-1) then
            begin
               error[p]:=6; {Thong bao thoi gian hoan thanh SAI}
               exit;
            end;
      end;

   (* Kiem tra mau thuan *)
   for i:=1 to N do
      for j:=1 to N do
         if (a[i,j]=1) and (Time[i]>=Time[j]) then
             begin
                error[p]:=7; {Vi pham tinh TRUOC-SAU}
                exit;
             end;

   (* Kiem tra tai mot thoi diem mot may co lam hai viec khong *)
   for i:=1 to N do
      for j:=1 to N do
         if (i<>j) and (x[i,1]=x[j,1]) and (Time[i]=Time[j]) then
            begin
               error[p]:=8; {Co may lam 2 viec cung 1 thoi diem}
               exit;
            end;

   ok:=true;
end;

procedure Cham;
var i: integer;
    tyle: real;
begin
   readln(fm,kqm[p]);
   readln(fo,kqo[p]);
   M:=kqo[p];
   for i:=1 to N do
      readln(fo,x[i,1],x[i,2]);
   Check;
   if not ok then  exit;
   if kqo[p]>BatDau[p] then
      begin
         tyle:=kqo[p]/batdau[p];
         if tyle<=1.01 then diem[p]:=0.5 else
         if tyle<=1.02 then diem[p]:=0.4 else
         if tyle<=1.03 then diem[p]:=0.3 else
         if tyle<=1.04 then diem[p]:=0.2 else
         if tyle<=1.05 then diem[p]:=0.1 else
            begin
               diem[p]:=0;
               error[p]:=3; {Vuot chuan tren 5%}
            end;
         exit;
      end;
   diem[p]:=1.0;
   if kqo[p]<kqm[p] then
      begin
         error[p]:=4; {Ghi nhan ky luc!!!'}
         KyLuc:=true;
         exit;
      end;
end;

procedure InError(p: LongInt);
begin
   textcolor(red);
   case Error[p] of
      0: writeln;
      1: writeln('Khong co file OUTPUT');
      2: writeln('Loi doc file OUTPUT');
      3: writeln('Vuot chuan tren 5%');
      4: writeln('Ghi nhan ky luc!!!');
      5: writeln('So hieu may khac 1, 2');
      6: writeln('Thong bao thoi gian hoan thanh SAI');
      7: writeln('Vi pham tinh TRUOC-SAU');
      8: writeln('Co may lam 2 viec cung 1 thoi diem');
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
         write('              TEST ',p,': ',Diem[p]:4:1,' Diem.',':',kqm[p]:5,':',kqo[p]:5,':');
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

procedure GhiNhan;
var
   st: string;
begin
   reset(fo); rewrite(fm);
   while not seekeof(fo) do
      begin
         readln(fo,st);
         writeln(fm,st);
      end;
   close(fm);
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
         KyLuc:=false;
         assign(fo,tfo); reset(fo);
         assign(fm,tfm); reset(fm);
         Cham;
         close(fo); close(fm);
         if KyLuc then GhiNhan;
      end;
   Inkq;
   XoaFile;
END.