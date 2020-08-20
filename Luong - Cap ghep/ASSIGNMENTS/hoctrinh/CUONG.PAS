{$R+,Q+}

Const tfi='HOCTRINH.INP';
      tfo='HOCTRINH.OUT';
      maxn=100;
      maxt=1000;
      di:array[1..6] of integer=(5,6,7,8,9,10);

Type
    Arr=array[0..maxt] of integer;

Var s:array[1..maxn] of longint;
    a:array[1..maxn,1..6] of integer;
    fi,fo:text;
    d,c:array[0..maxt] of longint;
    n,t:integer;
    tr:array[1..maxn] of ^Arr;
    l:array[1..maxn] of integer;
    kq:longint;

Procedure Mofile;
begin Assign(fi,tfi);
      reset(fi);
      Assign(fo,tfo);
      rewrite(fo);
end;

Procedure Dongfile;
begin close(fi);
      closE(fo);
end;

Procedure Docdl;
Var i,j:integer;
begin
     Readln(fi,n,t);
     for i:=1 to n do
         read(fi,s[i]);
     for i:=1 to n do
         for j:=1 to 6 do
             read(fi,a[i,j]);
end;

Procedure Chuanbi;
Var i:integer;
Begin
     for i:=1 to maxn do
         Begin new(tr[i]);
               Fillchar(tr[i]^,sizeof(tr[i]^),0);
         end;
     Fillchar(c,sizeof(c),0);
     d[0]:=1;
end;

Procedure Xuli;
Var i,j,k:integer;
begin
     For i:=1 to n do
     Begin
         Move(d,c,sizeof(d));
         Fillchar(d,sizeof(d),0);
         For j:=t downto 0 do
             if c[j]>0 then
                for k:=1 to 6 do
                    if j+a[i,k]<=t then
                       if d[j+a[i,k]]<c[j]+s[i]*di[k] then
                          Begin d[j+a[i,k]]:=c[j]+s[i]*di[k];
                                tr[i]^[j+a[i,k]]:=k;
                          end;
     end;
end;

Procedure Timnguoc;
var i,j,u,v:integer;
Begin
     kq:=0;v:=0;
     for j:=t downto 0 do
         if d[j]>kq then Begin kq:=d[j];
                               v:=j;
                         end;
     Fillchar(l,sizeof(l),0);
     u:=n;
     Repeat
           i:=tr[u]^[v];
           l[u]:=a[u,i];
           v:=v-a[u,i];
           dec(u);
     Until u=0;
     Dec(kq);
end;

Procedure Run;
begin
     Chuanbi;
     Xuli;
     Timnguoc;
end;

Procedure Inkq;
Var i:integer;
Begin
     writeln(fo,kq);
     For i:=1 to n do
         writeln(fo,l[i]);
end;

BEGIN
     Mofile;
     Docdl;
     Run;
     Inkq;
     Dongfile;
END.

