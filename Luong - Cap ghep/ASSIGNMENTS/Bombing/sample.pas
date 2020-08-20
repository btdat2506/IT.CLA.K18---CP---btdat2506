{**************************************************************************
*  Program  :   OANH KICH (Bombing)                                       *
*  Date     :   7-10-2006                                                 *
*  Group    :   Luong-Cap ghep                                            *
*  N.Ngu    :   Free Pascal                                               *
**************************************************************************}
const
   tfi= 'in.01';
   tfo='out.01';
   maxN=151;

type
   mang1=array[1..maxN,1..maxN] of integer;
   mang2=array[1..maxN] of integer;

var
   fi, fo: text;
   c: mang1;
   n: longint;
   Ds: longint;
   xp,kt: longint;
   fl: mang1;
   mf: longint;
   Q: mang2;
   Ep: mang2;
   qf,ql: integer;
   Tr: mang2;

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

procedure Nhap;
var m,i,u,v,w: longint;
begin
   fillchar(c,sizeof(c),0);
   readln(fi,N);
   readln(fi,m);
   for i:=1 to m do
       begin
          readln(fi,u,v,w);
          c[u,v]:=w;
          c[v,u]:=w;
       end;
end;

function min(u,v: integer): integer;
begin
   if u<v then min:=u else min:=v;
end;

procedure TimDuong(var ok: boolean);
var i,u,v: integer;
begin
   ok:=true;
   InitQ;
   for i:=1 to n do tr[i]:=0;
   Put(xp);
   Tr[xp]:=n+1;
   Ep[xp]:=maxint;
   repeat
      u:=Get;
      (* cung xuoi *)
      for v:=1 to n do
         if (fl[u,v]<c[u,v]) and (Tr[v]=0) then
            begin
               Put(v);
               Tr[v]:=u;
               Ep[v]:=min(Ep[u],c[u,v]-fl[u,v]);
               if v=kt then exit;
            end;
      (* cung nguoc *)
      for v:=1 to n do
         if (fl[v,u]>0) and (Tr[v]=0) then
            begin
               Put(v);
               Tr[v]:=-u;
               Ep[v]:=min(Ep[u],fl[v,u]);
            end;
   until Qempty;
   ok:=false;
end;

procedure TangLuong;
var u,v,delta: integer;
begin
   delta:=Ep[kt];
   mf:=mf+delta;
   if mf>=Ds then exit;
   v:=kt;
   repeat
      u:=tr[v];
      if u<0 then
         begin
            u:=-u;
            fl[v,u]:=fl[v,u]-delta;
         end
      else if u<n+1 then fl[u,v]:=fl[u,v]+delta;
      v:=u;
   until v=n+1;
end;

procedure MaxFlow;
var ok: boolean;
begin
   fillchar(fl,sizeof(fl),0);
   Mf:=0;
   repeat
      TimDuong(ok);
      if ok then TangLuong;
   until not ok;
end;

procedure Tinh;
var i: integer;
    dd: array[1..maxN] of byte;
begin
   Ds:=maxlongint;
   for xp:=1 to n-1 do
      begin
         kt:=xp+1;
         for i:=kt to n do dd[i]:=0;
         while kt<=n do
            begin
               maxflow;
               if Ds>mf then Ds:=mf;
               for i:=kt to n do
                  if tr[i]=0 then dd[i]:=1;
               repeat inc(kt) until (kt>n) or (dd[kt]=0);
            end;
      end;
   if Ds=maxlongint then Ds:=-1;
end;

procedure Main;
begin
   assign(fi,tfi); reset(fi);
   assign(fo,tfo); rewrite(fo);
   Nhap;
   Tinh;
   writeln(fo,Ds);
   close(fi); close(fo);
end;


BEGIN
   Main;
END.
