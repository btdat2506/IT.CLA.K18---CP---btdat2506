{$R-,B-,Q-}
const
   tfi            =     'TIGER.INP';
   tfo            =     'TIGER.OUT';
   maxN           =     100;

var
   a              :     array[1..maxN,1..maxN] of integer;
   fi, fo         :     text;
   N,M            :     integer;

   Fl             :     array[1..maxN,1..maxN] of byte;

   Q              :     array[1..maxN] of integer;
   qf,ql          :     integer;

   Tr             :     array[1..maxN] of integer;

   slH            :     integer;
   H              :     array[1..maxN] of integer;
   slkt           :     integer;
   kt             :     array[1..maxN] of integer;
   ktB            :     integer;
   slB            :     integer;
   B              :     array[1..maxN] of integer;

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

procedure Docdl;
var u,v: integer;
begin
   fillchar(a,sizeof(a),0);
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   M:=0;
   while not seekeof(fi) do
      begin
         inc(M);
         readln(fi,u,v);
         a[u,v]:=M;
         a[v,u]:=M;
      end;
   close(fi);
end;

procedure FindPathH(var ok: boolean);
var u,v: integer;
begin
   ok:=true;
   InitQ;
   fillchar(Tr,sizeof(Tr),0);
   Put(N); Tr[N]:=N+1;
   repeat
      u:=Get;
      (* cung xuoi *)
      for v:=1 to N do
         if (a[u,v]<>0) and (Tr[v]=0) and (Fl[u,v]=0) then
            begin
               Put(v);
               Tr[v]:=u;
               if v=1 then exit;
            end;
      (* cung nguoc *)
      for v:=1 to N do
         if (a[v,u]<>0) and (Tr[v]=0) and (Fl[v,u]=1) then
            begin
               Put(v);
               Tr[v]:=-u;
            end;
   until Qempty;
   ok:=false;
end;

procedure IncFlowH;
var u,v: integer;
begin
   v:=1;
   repeat
      u:=Tr[v];
      if u>0 then Fl[u,v]:=1 else
         begin
            u:=-u;
            Fl[v,u]:=0;
         end;
      v:=u;
   until v=N;
end;

procedure MaxFlowH;
var ok: boolean;
begin
   {Init Flow}
   Fillchar(Fl,sizeof(Fl),0);
   repeat
      FindPathH(ok);
      if ok then IncFlowH;
   until not ok;
end;

procedure ThemKt(v: integer);
var i: integer;
begin
   for i:=1 to slkt do
      if kt[i]=v then exit;
   inc(slkt);
   kt[slkt]:=v;
end;

procedure TimCanhH;
var u,v: integer;
begin
   slH:=0;
   slkt:=0;
   for u:=1 to N do
      if Tr[u]<>0 then
         for v:=1 to N do
            if (a[u,v]<>0) and (Tr[v]=0) then
               begin
                  inc(slH);
                  H[slH]:=a[u,v];
                  ThemKT(v);
               end;
end;

function Stop(v: integer): boolean;
var i: integer;
begin
  Stop:=true;
  for i:=1 to slkt do
     if kt[i]=v then exit;
  Stop:=false;
end;

procedure FindPathB(var ok: boolean);
var u,v: integer;
begin
   ok:=true;
   fillchar(Tr,sizeof(Tr),0);
   InitQ;
   Put(1); Tr[1]:=N+1;
   repeat
      u:=Get;
      (* cung xuoi *)
      for v:=1 to N do
         if (a[u,v]<>0) and (Tr[v]=0) and (Fl[u,v]=0) then
            begin
               Put(v);
               Tr[v]:=u;
               if Stop(v) then
                  begin
                     ktB:=v;
                     exit;
                  end;
            end;
      (* cung nguoc *)
      for v:=1 to N do
         if (a[v,u]<>0) and (Tr[v]=0) and (Fl[v,u]=1) then
            begin
               Put(v);
               Tr[v]:=-u;
            end;
   until Qempty;
   ok:=false;
end;

procedure IncFlowB;
var u,v: integer;
begin
   v:=ktB;
   repeat
      u:=Tr[v];
      if u>0 then Fl[u,v]:=1 else
         begin
            u:=-u;
            Fl[v,u]:=0;
         end;
      v:=u;
   until v=1;
end;

procedure MaxFlowB;
var ok: boolean;
begin
   Fillchar(Fl,sizeof(Fl),0);
   repeat
      FindPathB(ok);
      if ok then IncFlowB;
   until not ok;
end;

procedure TimCanhB;
var u,v: integer;
begin
   slB:=0;
   for u:=1 to N do
       if Tr[u]<>0 then
          for v:=1 to N do
             if (a[u,v]<>0) and (Tr[v]=0) then
                begin
                   inc(slB);
                   B[slB]:=a[u,v];
                end;
end;

procedure Solve;
begin
   MaxFlowH;
   TimCanhH;
   MaxFlowB;
   TimCanhB;
end;

procedure Inkq;
var i: integer;
begin
   assign(fo, tfo); rewrite(fo);
   writeln(fo,slH);
   for i:=1 to slH do write(fo,H[i],' ');
   writeln(fo);
   writeln(fo,slB);
   for i:=1 to slB do write(fo,B[i],' ');
   close(fo);
end;

BEGIN
   Docdl;
   Solve;
   Inkq;
END.