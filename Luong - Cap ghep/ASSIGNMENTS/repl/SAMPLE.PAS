const
   tfi='Repl.inp';
   tfo='Repl.out';
   maxN=201;

type
   xau=string[20];

var
   fi, fo: text;
   N,L: integer;
   s: array[1..maxN] of xau;
   a: array[1..2*maxN] of xau;
   M: integer;
   c: array[0..2,1..2*maxN] of integer;

   Mf: integer;
   Ft: array[1..maxN] of integer;
   Fp: array[1..2*maxN] of integer;

   Q: array[1..maxN] of integer;
   qf,ql: integer;

   Tr: array[1..maxN] of integer;
   ktp,ktt: integer;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(u: integer);
begin
   q[ql]:=u;
   inc(ql);
end;

function Get: integer;
begin
   Get:=q[qf];
   inc(qf);
end;

function Qempty: boolean;
begin
   Qempty:=(qf=ql);
end;

procedure doc;
var i: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,L);
   for i:=1 to N do readln(fi,s[i]);
   close(fi);
end;

function Tim(t: xau): integer;
var dau,cuoi,giua: integer;
begin
   if t=a[1] then
      begin
         tim:=1;
         exit;
      end;
   dau:=1;
   cuoi:=M;
   repeat
      giua:=(dau+cuoi) div 2;
      if a[giua]=t then
         begin
            tim:=giua;
            exit;
         end;
      if t<a[giua] then cuoi:=giua-1 else dau:=giua+1;
   until cuoi<dau;
end;

procedure chuanbi;
var i,j: integer;
    t: xau;
begin
   for i:=1 to N do
      begin
         a[2*i-1]:=s[i];
         a[2*i]:=s[i];
         for j:=1 to L do
            begin
               if a[2*i-1][j]='*' then a[2*i-1][j]:='0';
               if a[2*i][j]='*' then a[2*i][j]:='1';
            end;
      end;
   for i:=1 to 2*n-1 do
      for j:=i+1 to 2*n do
         if a[i]>a[j] then
            begin
               t:=a[i];
               a[i]:=a[j];
               a[j]:=t;
            end;
   M:=2*N;
   i:=1;
   while (i<M) do
      begin
         while (i<M) and (a[i]=a[i+1]) do
            begin
               move(a[i+1],a[i],sizeof(a[i+1])*(M-i));
               dec(M);
            end;
         inc(i);
      end;
   {Dung Do thi}
   fillchar(c,sizeof(c),0);
   for i:=1 to N do
      if pos('*',s[i])=0 then c[2,i]:=Tim(s[i])
      else
         begin
            t:=s[i];
            for j:=1 to L do if t[j]='*' then t[j]:='0';
            c[0,i]:=Tim(t);
            t:=s[i];
            for j:=1 to L do if t[j]='*' then t[j]:='1';
            c[1,i]:=Tim(t);
         end;
end;

procedure InitFlow;
begin
   Fillchar(Ft,sizeof(ft),0);
   Fillchar(Fp,sizeof(fp),0);
end;

procedure FindPath(var ok: boolean);
var i,u,v,w: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   for i:=1 to N do
      if Tr[i]=0 then
         begin
            Put(i);
            Tr[i]:=-1;
         end;
    while not Qempty do
       begin
          u:=Get;
          for i:=0 to 2 do
             if c[i,u]>0 then
                begin
                   v:=c[i,u];
                   if fp[v]=0 then
                      begin
                         ktp:=v;
                         ktt:=u;
                         exit;
                      end;
                   w:=fp[v];
                   if Tr[w]=0 then
                      begin
                         Put(w);
                         Tr[w]:=u;
                      end;
                end;
       end;
   ok:=false;
end;

procedure IncFlow;
var u,v,v1: integer;
begin
   v:=ktp;
   u:=ktt;
   repeat
      v1:=Ft[u];
      Ft[u]:=v;
      Fp[v]:=u;
      v:=v1;
      u:=Tr[u];
   until u=-1;
end;

procedure Ghep;
var ok: boolean;
    i: integer;
begin
   Mf:=0;
   if M<N then exit;
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
   for i:=1 to N do
      if ft[i]<>0 then inc(Mf);
end;

procedure Viet;
var i,j: integer;
begin
   assign(fo,tfo); rewrite(fo);
   if Mf<N then writeln(fo,-1) else
     begin
        writeln(fo,1);
        for i:=1 to N do
           begin
              j:=-1;
              repeat inc(j) until c[j,i]=Ft[i];
              writeln(fo,j);
           end;
     end;
   close(fo);
end;

BEGIN
   doc;
   ChuanBi;
   Ghep;
   viet;
END.