{$M 60000,0,655360}
const                   tfi='xep.inp';
                        tfo='xep.out';
                        maxn=101;

type                    long=longint;
                        inte=integer;
                        boo=boolean;

type                    mang=array[1..maxn,1..maxn]of byte;
                        mang1=array[1..maxn,1..maxn]of inte;

var                     fi,fo                   :text;
                        n,m                     :long;
                        a                       :mang;
                        kq                      :mang1;
                        b                       :mang;
                        sl                      :long;
                        mau                     :mang;

procedure mofile;
 begin
      assign(fi,tfi);reset(fi);
      assign(fo,tfo);rewrite(Fo);
 end;

procedure dongfile;
 begin
      close(fi);close(fo);
 end;

procedure docdl;
var i,j:inte;
 begin
      read(fi,m,n);
      for i:=1 to m do
          for j:=1 to n do read(fi,a[i,j]);
      for i:=1 to m do
          for j:=1 to n do read(fi,mau[i,j]);
 end;

procedure xoay(var u:inte);
var u1:inte;
 begin
      u1:=u mod 4;
      u:=(u1 shl 6) or ( u shr 2);
 end;

function doiso(u,v:inte):inte;
 begin
      doiso:=(u-1)*n+v;
 end;

procedure thamlam;
var i,j,i1,j1,k,u:inte;
    ok:boo;
 begin
      sl:=0;
      for i:=1 to m do
          for j:=1 to n do b[i,j]:=5;
      for i:=1 to m do for j:=1 to n do
          begin
               u:=a[i,j];
               for k:=0 to 3 do
                   begin
                        ok:=false;
                        for i1:=1 to m do
                            begin
                                 for j1:=1 to n do
                                     if (b[i1,j1]=5)and(mau[i1,j1]=u) then
                                        begin
                                             b[i1,j1]:=k;
                                             inc(sl);
                                             kq[i1,j1]:=doiso(i,j);
                                             ok:=true;
                                             break;
                                        end;
                                 if ok then break;
                            end;
                        if ok then break else xoay(u);
                   end;
          end;
 end;

procedure tinh;
 begin
      thamlam;
 end;

procedure inkq;
var i,j:inte;
 begin
      if sl<m*n then
         begin
              writeln(fo,-1);
              exit;
         end;
      for i:=1 to m do
          begin
               for j:=1 to n do write(fo,kq[i,j],' ');
               writeln(fo);
          end;
      for i:=1 to m do
          begin
               for j:=1 to n do write(fo,b[i,j],' ');
               writeln(fo);
          end;
 end;

begin
     mofile;
     docdl;
     tinh;
     inkq;
     dongfile;
end.
