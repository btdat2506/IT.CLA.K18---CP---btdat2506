{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

var
   diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   N,K: Integer;
   c: array[1..200] of integer;
   a: array[1..100,1..100] of LongInt;
   LMau,Lout: integer;
   dd: array[1..100] of byte;

procedure Docdl;
var i,j: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,K);
   for i:=1 to K do read(fi,c[i]);
   for i:=1 to N do
      for j:=1 to N do read(fi,a[i,j]);
   close(fi);
   assign(fm,tfm); reset(fm);
   readln(fm,Lmau);
   close(fm);
end;

procedure Cham;
var i,u: integer;
begin
   Lout:=0;
   fillchar(dd,sizeof(dd),0);
   for i:=1 to K do
      begin
         read(fo,u);
         if IOResult<>0 then exit;
         if (u<1) or (u>N) then exit;
         dd[u]:=1;
         if a[c[i],u]>Lout then Lout:=a[c[i],u];
      end;
   for i:=1 to N do
      if dd[i]=0 then exit;
   if Lout<=Lmau then Diem[p]:=1.0
                 else Diem[p]:=int(Lmau/Lout*10)/10;
end;

procedure Inkq;
var i: integer;
    Tong: real;
begin
   clrscr;
   writeln;
   writeln;
   writeln;
   writeln('********************************************************');
   writeln('*           KET QUA CHAM BAI SEAGAMES                  *');
   writeln('********************************************************');
   Tong:=0;
   for i:=1 to 10 do
      begin
         p:=i mod 10;
         Tong:=Tong+diem[p];
         writeln('         TEST :',diem[p]:4:1,' Diem');
      end;
   writeln('-------------------------------------------------------');
   writeln('   Tong cong = ',Tong:4:1,' Diem');
end;

procedure XoaFile;
begin
  for p:=0 to 9 do
     begin
        tfo:='SEAGAMES.OU'+chr(p+48);
        findfirst(tfo,archive,d);
        if DosError=0 then
           begin
              assign(fo,tfo);
              erase(fo);
           end;
     end;
end;


BEGIN
   fillchar(diem,sizeof(diem),0);
   for p:=0 to 9 do
      begin
         tfi:='SEAGAMES.IN'+chr(p+48);
         tfm:='SEAGAMES.AS'+chr(p+48);
         tfo:='SEAGAMES.OU'+chr(p+48);
         FindFirst(tfo,archive,d);
         if DosError<>0 then continue;
         Docdl;
         assign(fo,tfo); reset(fo);
         Cham;
         close(fo);
      end;
   Inkq;
   XoaFile;
END.
