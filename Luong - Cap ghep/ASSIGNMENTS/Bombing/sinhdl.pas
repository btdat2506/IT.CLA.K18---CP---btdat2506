const
   tfo=       'in.07';
   nn =           100;
var
   fo: text;
   i: integer;
   n,m: integer;
   a: array[1..101,1..101] of byte;
   k: integer;
   u,v,w: integer;

begin
   randomize;
   assign(fo,tfo); rewrite(fo);
   for i:=1 to 1 do
      begin
         n:=nn;
         if i=2 then n:=nn;
         m:=10*n;
         writeln(fo,n);
         writeln(fo,m);
         fillchar(a,sizeof(a),0);
         for k:=1 to m do
            begin
               repeat
                  u:=random(n)+1;
                  v:=random(n)+1;
               until (u<>v) and (a[u,v]=0);
               w:=random(1000)+1;
               writeln(fo,u,' ',v,' ',w);
               a[u,v]:=1;
               a[v,u]:=1;
            end;
      end;
   close(fo);
end.
