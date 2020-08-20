program tuyen_nhan_cong;

const fi = 'assign.in0987654321';
      fo = 'assign.ou0987654321';
      maxn = 303;  {300}
      vc = 10000000;

type arr = array[0..maxn]of integer;

var a : array[0..maxn]of ^arr;
    loai,nmin,dx,dy,luu,lmin,q : array[0..maxn]of integer;
    fx,fy,dmin : array[0..maxn]of longint;
    n,m,r,k,dq,cq,bd,kt,sl : integer;
    f : text;

(*********************************)

procedure getmem;
var i : integer;
begin
     for i:=0 to maxn do new(a[i]);
end;
(*********************************)

procedure enter;
var i,j,val : integer;
begin
     assign(f,fi);
     reset(f);

     readln(f,m,n,r);
     for i:=0 to maxn do
         for j:=0 to maxn do a[i]^[j]:=-1;
     for i:=1 to m do read(f,loai[i]);
     readln(f);
     while not seekeof(f) do
           begin
                readln(f,i,j,val);
                a[i]^[j]:=val;
           end;

     close(f);
end;
(*********************************)

function c(i,j : integer) : longint;
begin
     if a[loai[i]]^[j]=-1 then c:=vc
     else c:=a[loai[i]]^[j];
end;
(*********************************)

procedure init;
var i,j : integer;
    min : longint;
begin
     for i:=1 to n do
         begin
              min:=vc;
              for j:=1 to r do
                  if (a[j]^[i]>-1)and(a[j]^[i]<min) then
                     begin
                          min:=a[j]^[i];
                          nmin[i]:=j;
                     end;
              if min=vc then a[0]^[i]:=-1
              else a[0]^[i]:=min;
         end;
     k:=m;
     if n>k then k:=n;
     for i:=m+1 to k do loai[i]:=m+1;
end;
(*********************************)

procedure init1;
var i,j : integer;
    cc : longint;
begin
     fillchar(dx,sizeof(dx),0);
     fillchar(dy,sizeof(dy),0);
     for i:=1 to k do
         begin
              fx[i]:=vc;
              for j:=1 to k do
                  begin
                       cc:=c(i,j);
                       if cc<fx[i] then fx[i]:=cc;
                  end;

              fy[j]:=vc;
              for j:=1 to k do
                  begin
                       cc:=c(i,j)-fx[i];
                       if cc<fy[i] then fy[i]:=cc;
                  end;
         end;
end;
(*********************************)

procedure init2;
var i : integer;
begin
     fillchar(luu,sizeof(luu),0);
     for i:=1 to k do
         begin
              dmin[i]:=vc;
              lmin[i]:=bd;
         end;
     dq:=1;
     cq:=1;
     q[dq]:=bd;
end;
(*********************************)

procedure findpath;
var i,j : integer;
    canh : longint;
begin
     kt:=0;
     while dq<=cq do
           begin
                i:=q[dq];
                inc(dq);

                for j:=1 to k do
                    if luu[j]=0 then
                    begin
                         canh:=c(i,j);
                         canh:=canh-fx[i]-fy[j];
                         if canh=0 then
                            begin
                                 luu[j]:=i;
                                 if dy[j]=0 then
                                    begin
                                         kt:=j;
                                         exit;
                                    end;
                                 inc(cq);
                                 q[cq]:=dy[j];
                            end;
                         if canh<dmin[j] then
                            begin
                                 dmin[j]:=canh;
                                 lmin[j]:=i;
                            end;
                    end;
           end;
end;
(*********************************)

procedure tangcapghep;
var kk : integer;
begin
     repeat
           dy[kt]:=luu[kt];
           kk:=dx[dy[kt]];
           dx[dy[kt]]:=kt;
           kt:=kk;
     until kt=0;
end;
(*********************************)

procedure suacanh;
var i,j : integer;
    min : longint;
begin
     min:=vc;
     for i:=1 to k do
         if (luu[i]=0)and(dmin[i]<min) then min:=dmin[i];

     for j:=1 to k do
         if (luu[j]<>0)then
            begin
                 dec(fy[j],min);
                 inc(fx[dy[j]],min);
            end
         else dec(dmin[j],min);
     inc(fx[bd],min);

     for j:=1 to k do

         if dmin[j]=0 then
         if luu[j]=0 then
            begin
                 luu[j]:=lmin[j];
                 if dy[j]=0 then
                    begin
                         kt:=j;
                         exit;
                    end;
                 inc(cq);
                 q[cq]:=dy[j];
            end;
end;
(*********************************)

procedure capghep;
var i : integer;
begin
     for i:=1 to k do
         begin
              bd:=i;
              init2;

              repeat
                    findpath;
                    if kt=0 then suacanh;
              until kt<>0;
              tangcapghep;
         end;
end;
(*********************************)

procedure solve;
var i : integer;
begin
     init1;
     capghep;
     sl:=0;
     for i:=1 to m do
         if c(i,dx[i])<>vc then
            begin
                 inc(sl);
                 loai[sl]:=loai[i];
            end;
     m:=sl;
     sl:=n-sl;
     k:=m;
     if n>k then k:=n;
     for i:=m+1 to k do loai[i]:=0;
     init1;
     capghep;
end;
(*********************************)

procedure result;
var i : integer;
    tong : longint;
begin
     assign(f,fo);
     rewrite(f);

     tong:=0;
     for i:=1 to n do tong:=tong + c(dy[i],i);
     writeln(f,sl,' ',tong);
     for i:=1 to n do
         begin
              if loai[dy[i]]=0 then writeln(f,nmin[i])
              else writeln(f,loai[dy[i]]);
         end;

     close(f);
end;
(*********************************)
(*********************************)

begin
     getmem;
     enter;
     init;
     solve;
     result;
end.

