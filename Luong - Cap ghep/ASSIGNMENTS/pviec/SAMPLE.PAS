const
   tfi= 'pviec.inp';
   tfo= 'pviec.out';
   MN=501;

type
   mang1=array[1..MN] of byte;
   mang2=array[1..MN] of integer;
   mang3=array[1..2*MN] of integer;

var
   fi, fo: text;
   M,N: integer;
   c: array[1..MN] of ^mang1;
   maxK: integer;
   Lim: integer;

   fs: mang2;
   fp: mang2;
   fl: array[1..MN] of ^mang1;
   mf: integer;

   q: mang3;
   qf,ql: integer;
   tr: mang3;
   kt: integer;

   good: boolean;

procedure cp;
var i: integer;
begin
   for i:=1 to MN do new(c[i]);
   for i:=1 to MN do new(fl[i]);
end;

procedure initq;
begin
   qf:=1;
   ql:=1;
end;

function get: integer;
begin
   get:=q[qf];
   inc(qf);
end;

procedure put(u: integer);
begin
   q[ql]:=u;
   inc(ql);
end;

function qempty: boolean;
begin
   qempty:=(qf=ql);
end;

procedure Nhap;
var i,j,u,k: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,M,N);
   for i:=1 to N do
      for j:=1 to M do c[i]^[j]:=0;
   maxK:=0;
   for i:=1 to N do
      begin
         K:=0;
         repeat
            read(fi,u);
            if u>0 then
               begin
                  inc(k);
                  c[i]^[u]:=1;
               end;
         until u=0;
         readln(fi);
         if K>maxK then maxK:=K;
      end;
   close(fi);
end;

procedure initflow;
var i,j: integer;
begin
   fillchar(fs,sizeof(fs),0);
   for i:=1 to n do
      for j:=1 to m do fl[i]^[j]:=0;
   fillchar(fp,sizeof(fp),0);
end;

procedure findpath(var ok: boolean);
var u,v: integer;
begin
   ok:=true;
   fillchar(tr,sizeof(tr),0);
   initq;
   for u:=1 to n do
      if fs[u]<Lim then
         begin
            Put(u);
            tr[u]:=(n+m+1);
         end;
   while not qempty do
      begin
         u:=Get;
         if u<=n then {ben trai}
            begin
               for v:=1 to m do
                  if (Tr[v+n]=0) and (fl[u]^[v]=0) and (c[u]^[v]=1) then
                     begin
                        Put(v+n);
                        tr[v+n]:=u;
                        if fp[v]=0 then
                           begin
                              kt:=v+n;
                              exit;
                           end;
                     end;
            end
         else  {ben phai}
            begin
               v:=fp[u-n];
               if Tr[v]=0 then
                  begin
                     Put(v);
                     tr[v]:=-u;
                  end;
            end;
      end;
   ok:=false;
end;

procedure incflow;
var u,v: integer;
begin
   v:=kt;
   repeat
      u:=tr[v];
      if u<0 then
         begin
            u:=-u;
            fl[v]^[u-n]:=0;
            fp[u-n]:=0;
            v:=u;
         end
      else if u<>m+n+1 then
         begin
            fl[u]^[v-n]:=1;
            fp[v-n]:=u;
            v:=u;
         end;
   until u=m+n+1;
   inc(fs[v]);
end;

procedure maxflow;
var ok: boolean;
    i: integer;
begin
   initflow;
   repeat
      findpath(ok);
      if ok then incflow;
   until not ok;
   mf:=0;
   for i:=1 to m do
      if fp[i]>0 then inc(mf);
end;

procedure Tim;
var s,t: integer;
begin
   Lim:=maxK;
   maxflow;
   if mf<m then
      begin
         good:=false;
         exit;
      end;
   good:=true;
   s:=0;
   t:=maxK;
   repeat
      Lim:=(t+s) div 2;
      maxflow;
      if mf=M then t:=Lim else s:=lim;
   until t-s=1;
   Lim:=t;
   maxflow;
end;

procedure Xuat;
var i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if not good then writeln(fo,'NO') else
      begin
         writeln(fo,'YES');
         writeln(fo,Lim);
         for i:=1 to n do
            begin
               for j:=1 to m do
                  if fl[i]^[j]=1 then write(fo,j,#32);
               writeln(fo,0);
            end;
      end;
   close(fo);
end;

BEGIN
   cp;
   Nhap;
   Tim;
   Xuat;
END.