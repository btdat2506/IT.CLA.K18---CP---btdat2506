Program Xephinh;

 const
  tfi='Xep.inp';
  tfo='Xep.out';
  nmax=100;

 type
  so=array[1..8] of byte;

 var
  fi,fo:Text;
  m,n:integer;
  ovuong:array[1..nmax*nmax] of byte;
  B:array[1..nmax,1..nmax] of byte;
  Slquay:array[1..nmax*nmax] of integer;
  dd:array[1..nmax,1..nmax] of integer;
  Ok:boolean;

 procedure Init;
  var i,j:integer;
  begin
   assign(fi,tfi);reset(fi);
   readln(fi,m,n);
   for i:=1 to m*n do read(fi,Ovuong[i]);
   for i:=1 to m do
       for j:=1 to n do read(fi,B[i,j]);
   close(fi);
  end;

 procedure Chuanbi;
  var i,j:integer;
  begin
   for i:=1 to m*n do slquay[i]:=0;
   for i:=1 to m do
       for j:=1 to n do dd[i,j]:=0;
  end;

 procedure Dat;
  var i,j,k:integer;
  begin
  for i:=1 to m do
   for j:=1 to n do
    if dd[i,j]=0 then
    for k:=1 to m*n do
     if B[i,j]=Ovuong[k] then
       if slQuay[k]>=0 then
          begin
           dd[i,j]:=k;
           slquay[k]:=-slquay[k];
           if slQuay[k]=0 then slQuay[k]:=-4;
           break;
          end;
  end;

 procedure Chuyen2(u:byte;var l:so);
  var i:integer;
  begin
   i:=8;
   repeat
    l[i]:=u mod 2;
    u:=u div 2;
    dec(i);
   until i=0;
  end;

 procedure Chuyen10(l:so;var u:byte);
  var i,j:integer;
  begin
   u:=0;
   for i:=1 to 8 do u:=u*2+l[i];
  end;

 procedure Quay(var u:byte);
  var i,v:integer;
      l,l1:so;
  begin
   Chuyen2(u,l);
   i:=1;
   for i:=3 to 8 do l1[i]:=l[i-2];
   l1[1]:=l[7];
   l1[2]:=l[8];
   Chuyen10(l1,u);
  end;

 procedure Xuli;
  var i,d:integer;
  begin
   Chuanbi;
   d:=0;
   repeat
    Dat;
    Ok:=true;
    inc(d);
    for i:=1 to m*n do
        if slquay[i]>=0 then
           begin
            Ok:=false;
            Quay(Ovuong[i]);
            inc(slQuay[i]);
           end;
   until (Ok) or (d=4);
  end;

 procedure Inkq;
  var i,j:integer;
  begin
   assign(fo,tfo);rewrite(fo);
   if Ok then
   begin
   for i:=1 to m do
      begin
       for j:=1 to n do write(fo,dd[i,j],' ');
       writeln(fo);
      end;
   for i:=1 to m do
     begin
      for j:=1 to n do
          begin
           slQuay[dd[i,j]]:=-slQuay[dd[i,j]];
           if slQuay[dd[i,j]]=4 then write(fo,0,' ')
                                else write(fo,slquay[dd[i,j]],' ');
          end;
      writeln(fo);
     end;
  end
  else writeln(fo,-1);
   close(fo);
  end;

 BEGIN
  Init;
  Xuli;
  Inkq;
 END.