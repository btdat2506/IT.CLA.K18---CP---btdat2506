 {$R+,Q+}
 Const
      fti='hoctrinh.inp';
      fto='hoctrinh.out';
      maxn=100;
      maxT=1000;
      maxm=6;
      VC=maxlongint div 2;
 Type
     inte=integer;
     long=longint;
     mang=array[1..maxn]of inte;
 Var
    A:array[1..maxn,1..maxm]of long;
    C:array[0..maxT]of long;
    Tr:array[0..maxT]of ^mang;
    S,kq:array[1..maxn]of long;
    N,T:inte;
    fi,fo:text;
 Procedure Nhap;
  Var i,j:inte;
  begin
       Assign(fi,fti);Reset(fi);
       readln(fi,N,T);
       For i:=1 to N do Read(fi,S[i]);
       For i:=1 to N do
         begin
           For j:=1 to 6 do read(fi,A[i,j]);
           readln(fi);
         end;
       Close(fi);
  end;
 Procedure Xuly;
  Var i,j,k:inte;
  begin
    For i:=0 to T do
        begin
             New(Tr[i]);
             Fillchar(tr[i]^,sizeof(tr[i]^),0);
        end;
    Fillchar(C,sizeof(C),0);
    For i:=0 to T do
         For j:=1 to 6 do
            If (A[1,j]<=i) and (C[i]<(j+4)*S[1]) then
               begin
                  C[i]:=(j+4)*s[1];
                  Tr[i]^[1]:=j;
               end;
     For j:=2 to N do
       For i:=T downto 0 do
         begin
            Tr[i]^[j]:=0;
            C[i]:=-VC;
            for k:=1 to 6 do
               if (A[j,k]<=i) then
                  if (C[i]<C[i-A[j,k]]+(k+4)*s[j]) then
                     begin
                        C[i]:=C[i-a[j,k]]+(k+4)*s[j];
                        Tr[i]^[j]:=k;
                     end
         end;
   end;
 Procedure Inkq;
  Var i,j,u,v:inte;
      max:long;
  begin
       Assign(fo,fto);Rewrite(fo);
       max:=-1;
       For i:=T downto 0 do
           If max<C[i] then
              begin
                   max:=C[i];
                   u:=i;
              end;
       Writeln(fo,max);
       v:=N;
       Repeat
             kq[v]:=Tr[u]^[v];
             u:=u-A[v,kq[v]];
             dec(v);
       Until v=0;
       For i:=1 to N do Writeln(fo,A[i,kq[i]]);
       Close(fo);
  end;
 BEGIN
      Nhap;
      Xuly;
      Inkq;
 END.
