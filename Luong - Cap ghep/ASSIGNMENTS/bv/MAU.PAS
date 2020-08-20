{$R+,Q+,B-}
const
   tfi          =       'BV.INP';
   tfo          =       'BV.OUT';
   maxM         =       10000;
   maxN         =       5001;

type
   mangM        =       array[1..maxM] of longint;

var
   fi,fo        :       text;
   N            :       integer;
   M            :       integer;
   c            :       ^mangM;
   dau,cuoi     :       ^mangM;
   Tro          :       array[1..maxN] of integer;
   nguoc        :       ^mangM;
   TroN         :       array[1..maxN] of integer;
   Flow         :       ^mangM;
   Tr           :       array[1..maxN] of integer;
   Q            :       array[1..maxN] of integer;
   qf,ql        :       longint;
   Ep           :       array[1..maxN] of longint;
   slx          :       longint;
   x            :       array[1..maxM] of integer absolute q;
   mf           :       longint;

procedure CapPhat;
begin
   new(c);
   new(nguoc);
   new(flow);
   new(dau);
   new(cuoi);
end;

procedure GiaiPhong;
begin
   dispose(c);
   dispose(nguoc);
   dispose(flow);
   dispose(dau);
   dispose(cuoi);
end;

procedure Docdl;
var w,u,v: longint;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N);
   M:=0;
   while not seekeof(fi) do
      begin
         readln(fi,u,v,w);
         inc(M);
         c^[m]:=w;
         dau^[m]:=u;
         cuoi^[m]:=v;
      end;
   close(fi);
end;

procedure DoiCho(var u,v: longint);
var t: longint;
begin
   t:=u;
   u:=v;
   v:=t;
end;

procedure Sort(k,l: longint);
var i,j,rd,rc: longint;
begin
   rd:=dau^[(k+l) div 2];
   rc:=cuoi^[(k+l) div 2];
   i:=k; j:=l;
   repeat
      while (dau^[i]<rd) or ((dau^[i]=rd) and (cuoi^[i]<rc)) do inc(i);
      while (dau^[j]>rd) or ((dau^[j]=rd) and (cuoi^[j]>rc)) do dec(j);
      if i<=j then
         begin
            DoiCho(Dau^[i],Dau^[j]);
            DoiCho(Cuoi^[i],Cuoi^[j]);
            DoiCho(c^[i],c^[j]);
            inc(i); dec(j);
         end;
   until i>j;
   if k<j then Sort(k,j);
   if i<l then Sort(i,l);
end;

procedure SortN(k,l: longint);
var i,j,rd,rc: longint;
begin
   rc:=cuoi^[nguoc^[(k+l) div 2]];
   i:=k; j:=l;
   repeat
      while (cuoi^[nguoc^[i]]<rc) do inc(i);
      while (cuoi^[nguoc^[j]]>rc) do dec(j);
      if i<=j then
         begin
            DoiCho(nguoc^[i],nguoc^[j]);
            inc(i); dec(j);
         end;
   until i>j;
   if k<j then SortN(k,j);
   if i<l then SortN(i,l);
end;


procedure InitGraph;
var i,j,u,v: longint;
begin
   Sort(1,M); {sap xep theo dau tang dan}

   {bo di cac canh trung}
   i:=1;
   while (i<M) do
      begin
         while (i<M) and (dau^[i]=dau^[i+1]) and (cuoi^[i]=cuoi^[i+1]) do
            begin
               c^[i]:=c^[i]+c^[i+1];
               for j:=i+1 to M-1 do
                  begin
                     c^[j]:=c^[j+1];
                     dau^[j]:=dau^[j+1];
                     cuoi^[j]:=cuoi^[j+1];
                  end;
               dec(m);
            end;
         inc(i);
      end;

   {tao lap mang tro}
   for i:=1 to N do Tro[i]:=0;
   for i:=1 to M do
      begin
         u:=dau^[i];
         tro[u]:=tro[u]+1;
      end;
   u:=1;
   for i:=1 to N do
      begin
         v:=Tro[i];
         Tro[i]:=u;
         u:=u+v;
      end;
   Tro[n+1]:=u;

   {tao mang tro nguoc}
   for i:=1 to M do nguoc^[i]:=i;
   SortN(1,M);
   for i:=1 to N do TroN[i]:=0;
   for i:=1 to M do
      begin
         u:=cuoi^[nguoc^[i]];
         TroN[u]:=troN[u]+1;
      end;
   u:=1;
   for i:=1 to N do
      begin
         v:=TroN[i];
         TroN[i]:=u;
         u:=u+v;
      end;
   TroN[n+1]:=u;
end;

procedure InitFlow;
var i: longint;
begin
   for i:=1 to M do Flow^[i]:=0;
end;

procedure InitQ;
begin
   qf:=1;
   ql:=1;
end;

procedure Put(u: longint);
begin
   q[ql]:=u;
   inc(ql);
end;

function Get: longint;
begin
   Get:=q[qf];
   inc(qf);
end;

function Qempty: boolean;
begin
   Qempty:=(qf=ql);
end;

function Min(u,v: longint): longint;
begin
   if u<v then min:=u else min:=v;
end;

procedure FindPath(var ok: boolean);
var i,u,v: longint;
begin
   ok:=true;
   InitQ;
   for i:=1 to n do Tr[i]:=0;
   Put(N); Tr[N]:=M+1; Ep[N]:=maxlongint;
   repeat
      u:=Get;
      {cung xuoi}
      for i:=Tro[u] to Tro[u+1]-1 do
         begin
            v:=cuoi^[i];
            if (c^[i]>flow^[i]) and (Tr[v]=0) then
               begin
                  Put(v);
                  Tr[v]:=i; {phia truoc theo i}
                  Ep[v]:=min(Ep[u],c^[i]-flow^[i]);
                  if v=1 then exit;
               end;
         end;
      {cung nguoc}
      for i:=TroN[u] to TroN[u+1]-1 do
         begin
            v:=Dau^[nguoc^[i]];
            if (Flow^[nguoc^[i]]>0) and (Tr[v]=0) then
               begin
                  Put(v);
                  Tr[v]:=-Nguoc^[i];
                  Ep[v]:=min(Ep[u],flow^[nguoc^[i]]);
               end;
         end;
   until Qempty;
   ok:=false;
end;

procedure IncFlow;
var v,i,delta: longint;
begin
   delta:=Ep[1];
   v:=1;
   repeat
      i:=Tr[v];
      if i<=M then
         begin
            if i>0 then {cung xuoi}
               begin
                  flow^[i]:=flow^[i]+delta;
                  v:=dau^[i];
               end
            else
               begin
                  i:=-i;
                  flow^[i]:=flow^[i]-delta;
                  v:=cuoi^[i];
               end;
         end;
   until i=M+1;
end;

procedure MaxFlow;
var ok: boolean;
begin
   InitFlow;
   repeat
      FindPath(ok);
      if ok then IncFlow;
   until not ok;
end;

procedure TimLatCat;
var i: longint;
begin
   Mf:=0;
   slx:=0;
   for i:=1 to M do
      if ((Tr[dau^[i]]<>0) and (Tr[cuoi^[i]]=0)) then
         begin
            mf:=mf+c^[i];
            inc(slx);
            x[slx]:=i;
         end;
end;

procedure Inkq;
var i: longint;
begin
   assign(fo,tfo); rewrite(fo);
   writeln(fo,mf);
   for i:=1 to slx do
      writeln(fo,dau^[x[i]],' ',cuoi^[x[i]],' ',c^[x[i]]);
   close(fo);
end;

BEGIN
   CapPhat;
   Docdl;
   InitGraph;
   MaxFlow;
   TimLatCat;
   Inkq;
   GiaiPhong;
END.