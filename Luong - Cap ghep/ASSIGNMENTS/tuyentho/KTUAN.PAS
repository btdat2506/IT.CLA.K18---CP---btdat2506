program tuyennhancong;

const
	fin = 'assign.inp';
   fout= 'assign.out';
   max = 300;

type
	arr1 = array[1..max] of boolean;
   arr2 = array[1..max] of integer;

var
	fi, fo: text;
   m, n, r: integer;
   kind: array[1..max] of integer;
   a: array[1..max] of ^arr1;
   c: array[1..max] of ^arr2;
   by, x, y: array[1..max] of integer;
   bx: array[1..max] of boolean;
   fx, fy: array[1..max] of longint;
   q: array[1..max] of integer;
   left, right: integer;
   thomax, socap: integer;
   viec: array[1..max] of integer;
   res: longint;

procedure khoitao;
   var
   	i: integer;
	begin
		for i:= 1 to r do
      	begin
            new( a[i]);
            fillchar( a[i]^, sizeof(a[i]^) ,0);
            new( c[i]);
            fillchar( c[i]^, sizeof(c[i]^) ,0);
         end;
	end;

procedure nhap;
   var
   	i, j, x: integer;
	begin
		assign( fi, fin); reset( fi);
   	readln( fi, m, n, r);
      khoitao;
      for i:= 1 to m do read( fi, kind[i]);
      while not seekeof( fi) do
      	begin
            readln( fi, i, j, x);
            a[i]^[j]:= true;
            c[i]^[j]:= x;
         end;
      close( fi);
   end;

procedure tangcap( v: integer);
   var
   	u, k: integer;
	begin
   	thomax := thomax + 1;
		while v<>0 do
      	begin
            u:= by[v];
            k:= x[u];
            x[u]:= v;
            y[v]:= u;
            v:= k;
         end;
   end;

procedure tangcapts( v: integer);
   var
   	u, k: integer;
	begin
   	dec( socap );
		while v<>0 do
      	begin
            u:= by[v];
            k:= x[u];
            x[u]:= v;
            y[v]:= u;
            v:= k;
         end;
   end;

procedure timcap( i : integer );
   var
   	u, v: integer;
	begin
		fillchar( by, sizeof( by), 0);
      q[1]:= i ;
      left:= 1;
      right:= 1;
      while left <= right do
      	begin
            u:= q[left];
            left := left + 1;
            for v:= 1 to n do if (by[v] = 0) and a[kind[u]]^[v] then
            	begin
                  by[v]:= u;
                  if y[v] = 0 then
                  	begin
                        tangcap( v );
                        exit;
                     end;
                  right:= right + 1;
                  q[ right ]:= y[v];
               end;
         end;
   end;

procedure cgdon;
   var
   	i: integer;
	begin
   	thomax:= 0;
      for i:= 1 to m do timcap(i);
   end;

procedure init;
   var
   	i: integer;
	begin
      fillchar( by, sizeof(by), 0);
      left:=  1;
      right:= 0;
      for i:= 1 to m do if x[i] = 0 then
      	begin
         	right:= right + 1;
            q[right]:= i;
            bx[i]:= true;
         end;
   end;

function BFS: boolean;
   var
   	u, v: integer;
	begin
		while left<=right do
      	begin
            u:= q[left];
            left:= left + 1;
            for v:= 1 to n do if (by[v]=0) and a[kind[u]]^[v] and ((fx[u] + c[kind[u]]^[v] - fy[v])=0) then
            	begin
                  by[v]:= u;
                  if y[v]=0 then
                  	begin
                        tangcapts (v);
                        BFS:=true;
                        exit;
                     end;
                  inc( right );
                  q[right]:= y[v];
                  bx[y[v]]:= true;
               end;
         end;
      BFS:= false;
   end;

procedure suanhan;
   var
   	i , j : integer;
      dt: longint;
	begin
   	dt:= maxlongint;
      for i:= 1 to m do if bx[i] then
      	for j:= 1 to n do if (by[j]=0) and a[kind[i]]^[j] then
         	if dt> (fx[i]+c[kind[i]]^[j]-fy[j]) then dt:= fx[i]+c[kind[i]]^[j]-fy[j];
		for i:= 1 to m do if not bx[i] then fx[i]:= fx[i] + dt;
		for i:= 1 to n do if by[i]=0 then fy[i]:= fy[i] + dt;
   end;

procedure cgts;
	begin
		socap:= thomax;
   	fillchar( x, sizeof(x), 0);
      fillchar( y, sizeof(y), 0);
      while socap>0 do
      	begin
         	init;
            if not BFS then suanhan;
         end;
   end;

procedure update;
   var
   	i, j, min, rmin: integer;
	begin
      for i:= 1 to n do if y[i]<>0 then viec[i]:= kind[y[i]];
      for i:= 1 to n do if y[i]= 0 then
      	begin
         	min:= maxint;
            for j:= 1 to r do if a[j]^[i] and (c[j]^[i]<min) then
            	begin
                  rmin:= j;
                  min:= c[j]^[i];
               end;
            viec[i]:=rmin;
         end;
      res:= 0;
      for i:= 1 to n do res:= res + c[viec[i]]^[i];
   end;

procedure xuly;
	begin
   	cgdon;
      cgts;
      update;
   end;

procedure ghi;
   var
   	i: integer;
	begin
      assign( fo, fout); rewrite( fo);
		writeln( fo, n - thomax , ' ' , res );
      for i:= 1 to n do writeln( fo, viec[i]);
      close( fo);
   end;

begin
   nhap;
   xuly;
   ghi;
end.