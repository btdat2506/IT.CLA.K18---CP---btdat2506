{$M 16384,0,655360}
{$r-,q-,b-}
Const
     tfi='xep.inp';
     tfo='xep.out';
     maxn=100;
     max=5000;

Type
    inte=integer;
    long=longint;
    boo=boolean;
    mang=array[1..maxn*maxn*2] of inte;

Var
   fi,fo        :text;
   m,n          :inte;
   a            :array[1..maxn*maxn] of byte;
   b            :array[1..maxn*maxn] of byte;
   ft,fp        :array[1..maxn*maxn] of inte;
   tr           :^mang;
   q,nhan       :^mang;
   qf,ql        :INTE;
   good         :boo;
   kt,mf        :inte;

Procedure docdl;
var i,j:inte;
begin
     assign(fi,tfi);reset(fi);
     readln(fi,m,n);
     for i:=1 to m*n do read(fi,a[i]);
     for i:=1 to m do
            for j:=1 to n do
                 read(fi,b[(i-1)*n+j]);
     close(fi);
end;

Procedure initflow;
begin
     fillchar(ft,sizeof(ft),0);
     fillchar(fp,sizeof(fp),0);
end;

Function trongso(i,j:inte):inte;
var u,i1,u1:inte;
begin
     u:=a[i];
     trongso:=1;
     if a[i]=b[j] then exit;
     for i1:=1 to 3 do
       begin
{            u:=(u shl 1) or (u shr 7);
            u:=(u shl 1) or (u shr 7);}
{            u:=(u shl 2) or (u shr 6);}
            u1:=u and 3;
            u:=u shr 2;
            u:=u or (u1 shl 6);
            if u=b[j] then begin trongso:=1+i1;exit;end;
       end;
     trongso:=maxint;
end;

Procedure initnhan;
var i,j,u:inte;
begin
     good:=false;
     for i:=1 to n*m do nhan^[i]:=0;
     for i:=n*m+1 to n*m*2 do
       begin
            nhan^[i]:=maxint;
            for j:=1 to m*n do
              begin
                 u:=trongso(j,i-m*n);
                 if nhan^[i]>u then nhan^[i]:=u;
              end;
            if nhan^[i]=maxint then exit;
       end;
     good:=true;
end;

Procedure initq;
begin
     qf:=1;ql:=1;
end;

Procedure put(u:inte);
begin
     q^[ql]:=u;inc(ql);
end;

Function get:inte;
begin
     get:=q^[qf];inc(qf);
end;

Function qempty:boo;
begin
     qempty:=(qf=ql);
end;

Procedure findpath(xp:inte;var ok:boo);
var u,v,l:inte;
begin
     ok:=true;
     initq;
{     fillchar(tr,sizeof(tr),0);}
      for u:=1 to m*n*2 do tr^[u]:=0;
     put(xp);tr^[xp]:=m*n*2+1;
     repeat
           u:=get;
           if u<=m*n then
              for v:=1 to m*n do
               begin
                    l:=trongso(u,v);
                    if (l<>maxint) and (nhan^[u]+nhan^[v+m*n]=l) and (tr^[v+m*n]=0) then
                      begin
                           put(v+m*n);tr^[v+m*n]:=u;
                      end;
               end
           else
              begin
                   if fp[u-n*m]=0 then
                     begin
                          kt:=u;
                          exit;
                     end;
                   v:=fp[u-n*m];
                   if tr^[v]=0 then
                     begin
                          put(v);tr^[v]:=-u;
                     end;
              end;
     until qempty;
     ok:=false;
end;

Procedure repairflow;
var dmin,i,j,l:inte;
begin
     dmin:=maxint;
     for i:=1 to m*n do if tr^[i]<>0 then
      for j:=1 to m*n do if tr^[j+m*n]=0 then
        begin
             l:=trongso(i,j);
             if dmin>l-nhan^[i]-nhan^[j+m*n] then dmin:=l-nhan^[i]-nhan^[j+m*n];
        end;
      for i:=1 to m*n do
        if tr^[i]<>0 then
          nhan^[i]:=nhan^[i]+dmin;
      for i:=1 to m*n do
       if tr^[i+m*n]<>0 then
         nhan^[i+m*n]:=nhan^[i+m*n]-dmin;
end;

Procedure incflow;
var u,v:inte;
begin
     v:=kt;
     repeat
           u:=tr^[v];
           if u<0 then u:=-u
           else if u<m*n*2+1 then
                   begin
                        ft[u]:=v-n*m;
                        fp[v-n*m]:=u;
                   end;
           v:=u;
     until v=m*n*2+1;
end;

Procedure maxflow;
var u,i:inte;
    ok:boo;
begin
     good:=true;
     initflow;
     initnhan;
     if not good then exit;
     for u:=1 to n*M do
         begin
              repeat
                    findpath(u,ok);
                    if not ok then repairflow;
              until ok;
              incflow;
         end;
     mf:=0;
     for i:=1 to n*m do
        if ft[i]=0 then exit;
     for i:=1 to n*m do mf:=mf+trongso(i,ft[i]);
end;

Procedure inkq;
var i,j:inte;
begin
     assign(fo,tfo);rewrite(fo);
     if not good then writeln(fo,-1)
     else
       begin
            for i:=1 to m do
             begin
                for j:=1 to n do write(fo,fp[(i-1)*n+j],' ');
                writeln(fo);
              end;
            for i:=1 to m do
              begin
                   for j:=1 to n do write(fo,trongso(fp[(i-1)*n+j],(i-1)*n+j)-1,' ');
                   writeln(fo);
              end;
       end;
     close(fo);
end;

Procedure khoitao;
begin
     new(q);new(tr);new(nhan);
end;

Begin
     khoitao;
     docdl;
     maxflow;
     inkq;
end.
