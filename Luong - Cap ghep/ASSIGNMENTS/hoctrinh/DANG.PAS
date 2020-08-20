{$R+,Q+}
program hoctrinh;
const
  nfi='hoctrinh.inp';
  nfo='hoctrinh.out';
  limitn=100;
  limitt=1000;
type
  ar=array[0..limitt]of longint;
  arr=array[0..limitt]of shortint;
var
  fi,fo:text;
  n,t,rn:longint;
  s,r:array[1..limitn]of longint;
  a:array[1..limitn,5..10]of longint;
  f:array[0..limitn]of ^ar;
  p:array[0..limitn]of ^arr;
procedure surface;
  var
    i:longint;
  begin
    for i:=0 to limitn do
    begin
      new(f[i]);
      fillchar(f[i]^,sizeof(f[i]^),0);
      new(p[i]);
      fillchar(p[i]^,sizeof(p[i]^),0);
    end;
  end;
procedure input;
  var
    i,j:longint;
  begin
    assign(fi,nfi);reset(fi);
    readln(fi,n,t);
    for i:=1 to n do read(fi,s[i]);
    for i:=1 to n do
      for j:=5 to 10 do read(fi,a[i,j]);
    close(fi);
  end;
procedure dynamic;
  var
    i,j,k:longint;
  begin
    for i:=1 to n do
      for j:=0 to t do
        for k:=5 to 10 do
          if j>=a[i,k] then
            if f[i-1]^[j-a[i,k]]+s[i]*k>f[i]^[j] then
            begin
              f[i]^[j]:=f[i-1]^[j-a[i,k]]+s[i]*k;
              p[i]^[j]:=k;
            end;
  end;
procedure output;
  var
    i,j,k:longint;
  begin
    assign(fo,nfo);rewrite(fo);
    writeln(fo,f[n]^[t]);
    i:=n;
    j:=t;
    repeat
      k:=p[i]^[j];
      inc(rn);
      r[rn]:=a[i,k];
      j:=j-a[i,k];
      i:=i-1;
    until i=0;
    for i:=rn downto 1 do
      writeln(fo,r[i]);
    close(fo);
  end;
begin
  surface;
  input;
  dynamic;
  output;
end.
