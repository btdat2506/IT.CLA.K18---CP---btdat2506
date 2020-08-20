const
   tfi='in.01';
   tfo='Company.out';
   maxN=1000;

var
   fi, fo: text;
   a: array[1..maxN,1..maxN] of byte;
   N: integer;
   id: integer;
   color: array[1..maxN] of byte;
   x: array[1..maxN] of integer;

   Ds: integer;
   imax: integer;

   d,dem: array[1..maxN] of integer;

procedure Nhap;
var i,m: longint;
    u,v: integer;
begin
   assign(fi,tfi); reset(fi);
   fillchar(a,sizeof(a),0);
   read(fi,N,M);
   for i:=1 to M do
      begin
         read(fi,u,v);
         a[u,v]:=1;
      end;
   close(fi);
end;

procedure Whashall;
var i,j,k: integer;
begin
   for i:=1 to n do
      for j:=1 to n do
        if a[i,j]=0 then
           for k:=1 to n do
              if (a[i,k]=1) and (a[k,j]=1) then
                 begin
                     a[i,j]:=1;
                     break;
                 end;
end;

procedure Dfs(u: integer);
var v: integer;
begin
   color[u]:=1;
   for v:=1 to n do
      if (a[u,v]=1) and (color[v]=0) then
         Dfs(v);
   dec(id);
   x[id]:=u;
end;

procedure Sort;
var i: integer;
begin
   id:=n+1;
   for i:=1 to n do color[i]:=0;
   for i:=1 to n do
      if color[i]=0 then Dfs(i);
end;

procedure Tim;
var i,j,u,v: integer;
begin
   for i:=1 to n do d[i]:=n+1;
   for i:=1 to n do
      begin
         u:=x[i];
         if d[u]=n+1 then d[u]:=1;
         for j:=i+1 to n do
            begin
               v:=x[j];
               if (a[u,v]=1) and (d[v]>d[u]+1) then
                  d[v]:=d[u]+1;
            end;
      end;
   for i:=1 to n do dem[i]:=0;
   for i:=1 to n do inc(dem[d[i]]);
   Ds:=0;
   for i:=1 to n do
      if dem[i]>Ds then
         begin
            Ds:=dem[i];
            imax:=i;
         end;
end;

procedure Xuat;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,Ds);
   for i:=1 to n do
      if d[i]=imax then write(fo,i,#32);
   writeln(fo);
   close(fo);
end;

BEGIN
   Nhap;
   {Whashall;}
   Sort;
   Tim;
   Xuat;
END.