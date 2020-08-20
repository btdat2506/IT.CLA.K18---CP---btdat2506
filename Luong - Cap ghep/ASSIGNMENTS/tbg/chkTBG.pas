{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

uses crt,dos;

const
    dtfi='BG.IN';
    dtfo='BG.OU';
    dtfm='BG.AN';
    kqm: array[0..9] of integer=(98,19,39,29,39,45,50,68,78,87);

var
   Error: array[0..9] of integer;
   Diem: array[0..9] of real;
   p: integer;
   tfi,tfo,tfm: string[12];
   d: SearchRec;
   fi,fo,fm: text;
   dd: array[1..10000] of byte;

   N,M: integer;
   x1,y1,x2,y2: array[1..100] of longint;

   K,dem: integer;
   x,y: array[1..200] of longint;

procedure Docdl;
var i: integer;
begin
   assign(fi,tfi); reset(fi);
   read(fi,N,M);
   for i:=1 to N do read(fi,x1[i],y1[i]);
   for i:=1 to M do read(fi,x2[i],y2[i]);
   close(fi);
end;

function ViTri(u,v: longint): integer;
var i: integer;
begin
   for i:=1 to K do
      if (u=x[i]) and (v=y[i]) then
         begin
            ViTri:=i;
            exit;
         end;
   ViTri:=0;
end;

function TimHD(u,v: longint): integer;
var i: integer;
begin
   for i:=1 to M do
      if (u=x2[i]) and (v=y2[i]) then
         begin
            TimHD:=i;
            exit;
         end;
   TimHD:=0;
end;

function Kc(u1,v1,u2,v2: longint): real;
begin
   Kc:=sqrt(sqr(u2-u1)+sqr(v2-v1));
end;

procedure Cham;
var i,u,v,w: integer;
    d1,d2,d3: real;
begin
   read(fo,K);
   if ioresult<>0 then
      begin
         error[p]:=2;
         exit;
      end;
   for i:=1 to K do
      begin
         read(fo,x[i]);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
         read(fo,y[i]);
         if ioresult<>0 then
            begin
               error[p]:=2;
               exit;
            end;
      end;
   dem:=0;
   fillchar(dd,sizeof(dd),0);
   v:=Vitri(x1[1],y1[1]);
   if v<>1 then
      begin
         error[p]:=3; {Duong di khong hop le}
         exit;
      end;
   for i:=2 to N do
      begin
         u:=v;
         v:=ViTri(x1[i],y1[i]);
         if (v<=u) or (v-u>2) then
            begin
               error[p]:=3;
               exit;
            end;
         if v-u=2 then
            begin
               w:=TimHD(x[u+1],y[u+1]);
               if w=0 then
                  begin
                     error[p]:=3;
                     exit;
                  end;
               if dd[w]=0 then inc(dem);
               dd[w]:=1;
               d1:=Kc(x[u],y[u],x[u+1],y[u+1]);
               d2:=Kc(x[u+1],y[u+1],x[v],y[v]);
               d3:=Kc(x[u],y[u],x[v],y[v]);
               if d1+d2>2*d3 then
                  begin
                     error[p]:=4; {Khong di duoc}
                     exit;
                  end;
            end;
      end;
   if v<>K then
      begin
         error[p]:=3;
         exit;
      end;
   if dem<kqm[p] then
      begin
         error[p]:=5; {Khong toi uu}
         diem[p]:=0.3;
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
      3: writeln('Duong di khong hop le');
      4: writeln('Khong di duoc');
      5: writeln('Khong toi uu');
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