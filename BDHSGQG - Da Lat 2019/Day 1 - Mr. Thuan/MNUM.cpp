const fi='shorten.inp';
      fo='shorten.out';

function dodai(n:longint):longint;
var      i,j,m,d:longint;
begin
     if n<10 then
     begin    dodai:=n;    exit;     end;
     d:=10;m:=0;i:=1;
     repeat
          m:=m+(d- d div 10 )*i;
          d:=d*10;
          i:=i+1;
     until d>n;
     d:=d div 10;
     m:=m+(n-d+1)*i;
     dodai:=m;
end;

function dem(m:longint):longint;
var      i,j,d,u:longint;
begin
     u:=m;d:=0;
     while u>1 do
     begin
          d:=d+1;
          if d mod 2=1 then
             u:=u div 2+u mod 2
          else u:=u div 2;
     end;
     dem:=d;
end;

function chiso(d:longint):longint;
var      i,k:longint;
begin
     k:=1;
     for i:=d downto 1 do
         if i mod 2=1 then
            k:=k*2-1
         else
            k:=k*2;
     chiso:=k;
end;
function digit(nx,d:longint):longint;
var      i,tmp:longint;
begin
     tmp:=nx;
     for i:=1 to d do
         tmp:=tmp div 10;
     digit:=tmp mod 10;
end;
function chuso(k:longint):longint;
var      i,d,m,nx,j:longint;
begin
     d:=1;m:=0;i:=0;
     repeat
           d:=d*10; i:=i+1;
           m:=m+(d-d div 10)*i;
     until m>k;
     m:=m-(d-d div 10)*i;
     d:=d div 10;
     nx:=d+(k-m-1) div i;
     j:=(k-m-1) mod i +1;
     chuso:=digit(nx,i-j);
end;

procedure process;
var       f1,f2:text;
          n,m,d,k,x:longint;
begin
     assign(f1,fi);reset(f1);
     assign(f2,fo);rewrite(f2);
     while not(eof(f1)) do
     begin
          readln(f1,n);
          m:=dodai(n);
          d:=dem(m);
          k:=chiso(d);
          x:=chuso(k);
          writeln(f2,x);
     end;
     close(f1);close(f2);
end;
begin
     process;
end.
