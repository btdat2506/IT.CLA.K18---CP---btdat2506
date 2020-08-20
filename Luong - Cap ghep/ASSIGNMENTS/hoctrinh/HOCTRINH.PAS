{$R-}
const
   tfi                  =     'HocTrinh.INP';
   tfo                  =     'HocTrinh.OUT';
   maxN                 =     100;
   maxT                 =     1000;

type
   mang                 =     array[0..maxN] of byte;

var
   fi, fo               :     text;
   N, T                 :     integer;
   S                    :     array[1..maxN] of integer;
   a                    :     array[1..maxN,1..6] of integer;

   F                    :     array[0..maxT] of Longint;
   Tr                   :     array[0..maxT] of ^mang;

   x                    :     array[1..maxN] of integer;

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

procedure Tinh;
var i,j,k: integer;
begin
   for i:=0 to T do
      begin
         F[i]:=0;
         Tr[i]^[1]:=0;
      end;
   (* Tinh cot so 1 *)
   for i:=0 to T do
      begin
         F[i]:=0;
         Tr[i]^[1]:=0;
         for j:=1 to 6 do
            if (a[1,j]<=i) and (F[i]<(j+4)*s[1]) then
               begin
                  F[i]:=(j+4)*s[1];
                  Tr[i]^[1]:=j;
               end;
      end;
   (* Tinh tu cot 2 den cot N *)
   for j:=2 to N do
      for i:=T downto 0 do
         begin
            tr[i]^[j]:=0;
            F[i]:=-maxlongint;
            for k:=1 to 6 do
               if (a[j,k]<=i) then
                  if (F[i]<F[i-a[j,k]]+(k+4)*s[j]) then
                     begin
                        F[i]:=F[i-a[j,k]]+(k+4)*s[j];
                        Tr[i]^[j]:=k;
                     end
         end;
end;

procedure Tim;
var i,j: integer;
begin
   i:=T;
   for j:=N downto 1 do
      begin
         x[j]:=a[j,Tr[i]^[j]];
         i:=i-a[j,Tr[i]^[j]];
      end;
end;

procedure Inkq;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,F[T]);
   for i:=1 to N do writeln(fo,x[i]);
   close(fo);
end;

procedure CapPhat;
var i: integer;
begin
   for i:=0 to maxT do new(Tr[i]);
end;


BEGIN
   CapPhat;
   Docdl;
   Tinh;
   Tim;
   Inkq;
END.