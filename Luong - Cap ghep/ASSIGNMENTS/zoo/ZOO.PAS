{*********************************************************************
                          CLOSE THE DOORS
*********************************************************************}
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
uses crt;

const
   tfi                  =       'ZOO.INP';
   tfo                  =       'ZOO.OUT';
   MN                   =       50;
   LT                   :       array[1..4] of byte=(1,2,4,8);
   dh                   :       array[1..4] of integer=(-1,0,1,0);
   dc                   :       array[1..4] of integer=(0,-1,0,1);
   name                 :       array[1..4] of char=('B','T','N','D');

var
   fi,fo                :       text;
   M,N,uxp,vxp,T        :       integer;
   Gr                   :       array[1..MN,1..MN] of byte;
   Fl                   :       array[1..MN,1..MN] of byte;
   ok                   :       boolean;
   Q                    :       array[1..MN*MN] of integer;
   qf,ql                :       integer;
   Tr                   :       array[1..MN*MN] of integer;
   slxp                 :       integer;
   xp                   :       array[1..MN*MN] of integer;
   kt                   :       integer;
   sol                  :       integer;
   Dire,x,y             :       array[1..MN*MN] of integer;
   RaNgoai              :       boolean;

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
var i,j: integer;
begin
   readln(fi,M,N,uxp,vxp,T);
   for i:=1 to M do
     begin
        for j:=1 to N  do read(fi,Gr[i,j]);
        readln(fi);
     end;
end;

procedure InitFlow;
begin
   fillchar(fl,sizeof(fl),0);
end;

procedure Doidinh(u: integer; var i,j: integer);
begin
   i:=(u-1) div N+1;
   j:=(u-1) mod N+1;
end;
function Doiso(i,j: integer): integer;
begin
   Doiso:=(i-1)*N+j;
end;

function Inside(i,j: integer): boolean;
begin
   Inside:=(i>=1) and (i<=M) and (j>=1) and (j<=N);
end;


procedure TimDuong(var ok: boolean);
var i,j,u,v,k,ii,jj: integer;
begin
   ok:=true;
   InitQ;
   fillchar(tr,sizeof(Tr),0);
   for i:=1 to slxp do
      begin
         Put(xp[i]);
         Tr[xp[i]]:=M*N+1;
      end;
   while not Qempty do
      begin
         u:=Get;
         DoiDinh(u,i,j);
         (* canh xuoi *)
         for k:=1 to 4 do
            if (Gr[i,j] and LT[k]=0) and (Fl[i,j] and LT[k]=0) then
               begin
                  ii:=i+dh[k]; jj:=j+dc[k];
                  if Not Inside(ii,jj) then
                     begin
                        kt:=u;
                        exit;
                     end;
                  v:=Doiso(ii,jj);
                  if Tr[v]=0 then
                     begin
                        Tr[v]:=u;
                        Put(v);
                     end;
               end;
         (* canh nguoc *)
         for k:=1 to 4 do
            if (Gr[i,j] and LT[k]=0) then
               begin
                  ii:=i+dh[k]; jj:=j+dc[k];
                  if Inside(ii,jj) and
                     (Fl[ii,jj] and LT[(k mod 4+1) mod 4+1]>0) then
                     begin
                        v:=Doiso(ii,jj);
                        if Tr[v]=0 then
                           begin
                              Put(v);
                              Tr[v]:=-u;
                           end;
                     end;
               end;
      end;
   ok:=false;
end;

procedure TangLuong;
var v,u,ii,jj,iu,ju,iv,jv,k: integer;
begin
   v:=kt;
   Doidinh(v,iv,jv);
   for k:=1 to 4 do
      begin
         ii:=iv+dh[k]; jj:=jv+dc[k];
         if (not inside(ii,jj)) and (Gr[iv,jv] and LT[k]=0) then
         begin
            Fl[iv,jv]:=Fl[iv,jv] or LT[k];
            break;
         end;
      end;
   repeat
      u:=Tr[v];
      if u<0 then
         begin
            u:=-u;
            Doidinh(u,iu,ju);
            Doidinh(v,iv,jv);
            for k:=1 to 4 do
               if (iu=iv+dh[k]) and (ju=jv+dc[k]) then
                  begin
                     Fl[iv,jv]:=Fl[iv,jv] and (16-LT[k]);
                     break;
                  end;
          end
      else if u<=M*N then
         begin
            Doidinh(u,iu,ju);
            Doidinh(v,iv,jv);
            for k:=1 to 4 do
               if (iv=iu+dh[k]) and (jv=ju+dc[k]) then
                  begin
                     Fl[iu,ju]:=Fl[iu,ju] or LT[k];
                     break;
                  end;
         end;
      v:=u;
   until v=M*N+1;
end;

procedure TimLatCat;
var i,j,u,v,k,ii,jj: integer;
begin
   for i:=1 to M do
      for j:=1 to N do
         begin
            u:=Doiso(i,j);
            if Tr[u]<>0 then
               for k:=1 to 4 do
                  begin
                     ii:=i+dh[k]; jj:=j+dc[k];
                     if (Gr[i,j] and LT[k]=0) then
                        begin
                           if not Inside(ii,jj) then
                              begin
                                 sol:=sol+1;
                                 x[sol]:=i; y[sol]:=j;
                                 dire[sol]:=k;
                              end else
                              begin
                                 v:=Doiso(ii,jj);
                                 if Tr[v]=0 then
                                    begin
                                       sol:=sol+1;
                                       x[sol]:=i; y[sol]:=j;
                                       dire[sol]:=k;
                                    end;
                              end;
                        end;
                  end;
         end;
end;

procedure MaxFlow;
var ok: boolean;
begin
   InitFlow;
   repeat
      TimDuong(ok);
      if ok then  TangLuong;
   until not ok;
end;

procedure Inkq;
var i: integer;
begin
   if RaNgoai then
      begin
         writeln(fo,-1);
         exit;
      end;
   writeln(fo,sol);
   for i:=1 to sol do writeln(fo,x[i],' ',y[i],' ',name[dire[i]]);
end;

procedure NapXP;
var u,v,i,j,k,ii,jj: integer;
begin
   InitQ;
   fillchar(tr,sizeof(Tr),0);
   u:=Doiso(uxp,vxp);
   x[u]:=1; y[u]:=0;
   Put(u);
   RaNgoai:=false;
   slxp:=0;
   repeat
      u:=Get;
      inc(slxp);
      xp[slxp]:=u;
      Doidinh(u,i,j);
      if y[u]<T then
         begin
            for k:=1 to 4 do
               begin
                  ii:=i+dh[k]; jj:=j+dc[k];
                  if (not inside(ii,jj)) and (Gr[i,j] and LT[k]=0) then
                     begin
                        RaNgoai:=true;
                        exit;
                     end;
                  v:=Doiso(ii,jj);
                  if (Gr[i,j] and LT[k]=0) and (x[v]=0) then
                     begin
                        x[v]:=1; y[v]:=y[u]+1;
                        Put(v);
                     end;
               end;
         end;
   until Qempty;
end;

BEGIN
   assign(fi,tfi); reset(fi);
   assign(fo,tfo); rewrite(fo);
   Docdl;
   NapXP;
   if not RaNgoai then
      begin
         MaxFlow;
         TimLatCat;
      end;
   Inkq;
   close(fi); close(fo);
END.