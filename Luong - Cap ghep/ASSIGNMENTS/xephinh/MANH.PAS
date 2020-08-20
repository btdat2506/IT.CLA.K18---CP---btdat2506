{$Q+,R-}
type
     mang=array[1..4] of byte;
     mang1=array[1..101,1..101] of integer;
const
     tfi='xep.inp';
     tfo='xep.out';
var
     fi,fo:text;
     a:array[1..10001] of byte;
     dda:array[1..10001] of byte;
     b:array[1..101,1..101] of byte;
     ddb:array[1..101,1..101] of byte;
     kq:^mang1;
     m,n:integer;
     tx,ty:byte;

procedure docdl;
var i,j:integer;
begin
     readln(fi,m,n);
     new(kq);
     fillchar(kq^,sizeof(kq^),0);
     for i:=1 to m*n do
         read(fi,a[i]);
     for i:=1 to m do
         begin
              for j:=1 to n do
                  read(fi,b[i,j]);
         end;
end;

procedure doi(u:byte;var ma:mang);
var i,sl,r:byte;
begin
     fillchar(ma,sizeof(ma),0);
     for i:=1 to 4 do
         begin
              sl:=0;
              repeat
                    inc(sl);
                    r:=u mod 2;
                    ma[i]:=r+ma[i]*10;
                    u:=u div 2;
              until sl=2;
         end;
end;

procedure xoay(var ma:mang);
var t:byte;
begin
     t:=ma[1];
     ma[1]:=ma[2];
     ma[2]:=ma[3];
     ma[3]:=ma[4];
     ma[4]:=t;
end;

function thoaman(u,v:byte;var sl:byte):boolean;
var ma1,ma2:mang;
    i,l:integer;
begin
     thoaman:=true;
     sl:=0;
     if u=v then
        begin
             sl:=0;
             exit;
        end;
     doi(u,ma1);
     doi(v,ma2);
     for i:=1 to 3 do
         begin
              xoay(ma2);
              for l:=1 to 4 do
                  if ma1[l]<>ma2[l] then break
              else if l=4 then
                   begin
                        sl:=i;
                        exit;
                   end;
         end;
     thoaman:=false;
end;

procedure tim(var ok:boolean);
var t,knho,k:integer;
    sl:byte;
begin
     ok:=false;
     t:=9;
     for k:=1 to m*n do
     if dda[k]=0 then
         if thoaman(b[tx,ty],a[k],sl) then
            if sl<t then
               begin
                    ok:=true;
                    t:=sl;
                    knho:=k;
               end;
     if ok then
        begin
             ddb[tx,ty]:=t;
             kq^[tx,ty]:=knho;
             dda[knho]:=1;
        end;
end;

procedure xuli;
var ok:boolean;
begin
     tx:=1;
     ty:=0;
     repeat
           inc(ty);
           tim(ok);
           if ty=n then
              begin
                   ty:=0;
                   inc(tx);
              end;
     until (tx=m+1)or (ok=false);
end;

procedure inkq;
var i,j:integer;
begin
     for i:=1 to m do
         for j:=1 to n do
             if kq^[i,j]=0 then
                begin
                     writeln(fo,-1);
                     exit;
                end;
     for i:=1 to m do
         begin
              for j:=1 to n do
                  write(fo,kq^[i,j],' ');
              writeln(fo);
         end;
     for i:=1 to m do
     begin
          for j:=1 to n do
              write(fo,ddb[i,j],' ');
          writeln(fo);
     end;
end;

begin
     assign(fi,tfi);reset(fi);
     assign(fo,tfo);rewrite(fo);
     docdl;
     xuli;
     inkq;
     dispose(kq);
     close(fi);close(fo);
end.