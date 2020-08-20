
Const tfi='XEP.INP';
      tfo='XEP.OUT';
      maxn=100;
      h:array[1..8] of byte=(128,64,32,16,8,4,2,1);

Type
    Arr1=array[1..4] of byte;
    xau=string[4];

Var
   a:array[1..maxn,1..maxn] of byte;
   b:array[1..maxn*maxn] of byte;
   dd:array[1..maxn*maxn] of byte;
   n,m:longint;
   fi,fo:text;
   d:array[1..maxn,1..maxn] of byte;
   c:array[1..maxn,1..maxn] of integer;

Procedure Mofile;
Begin
     Assign(fi,tfi);
     Reset(fi);
     Assign(fo,tfo);
     Rewrite(fo);
End;

Procedure Dongfile;
Begin
     Close(fi);
     Close(fo);
End;

Procedure Docdl;
Var i,j:longint;
begin
     Readln(fi,m,n);
     for i:=1 to m*n do
         read(fi,b[i]);
     for i:=1 to m do
         for j:=1 to n do
             read(fi,a[i,j]);
end;

procedure doi(u:byte;var ma:Arr1);
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

procedure xoay(var ma:Arr1);
var t:byte;
begin
     t:=ma[1];
     ma[1]:=ma[2];
     ma[2]:=ma[3];
     ma[3]:=ma[4];
     ma[4]:=t;
end;

function ke(u,v:byte;var sl:longint):boolean;
var ma1,ma2:Arr1;
    i,l:integer;
begin
     ke:=true;
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
              xoay(ma1);
              for l:=1 to 4 do
                  if ma1[l]<>ma2[l] then break
              else if l=4 then
                   begin
                        sl:=i;
                        exit;
                   end;
         end;
     ke:=false;
end;

Procedure tim(q:byte;var k,t:longint);
Var i,j,p:longint;
Begin
     k:=0;t:=4;
     for i:=1 to m*n do
         if dd[i]=0 then
            begin
                 if ke(b[i],q,p) then
                    Begin if p<t then begin t:=p;
                                            k:=i;
                                            if t=0 then exit;
                                      end;
                    end;
           end;
end;

Procedure Insai;
Begin
     close(fo);
     rewrite(fo);
     writeln(fo,-1);
     close(fo);
     halt;
End;

Procedure Run;
var i,j,k,t:longint;
begin
     Fillchar(dd,sizeof(dd),0);
     for i:=1 to m do
         for j:=1 to n do
             begin Tim(a[i,j],k,t);
                   if k=0 then insai
                          else Begin c[i,j]:=k;
                                     d[i,j]:=t;
                                     dd[k]:=1;
                               end;
             end;
end;

Procedure Inkq;
var i,j,t:longint;
begin
     For i:=1 to m do
         Begin
              for j:=1 to n do
                  write(fo,c[i,j],#32);
              writeln(fo);
         end;
    t:=0;
    For i:=1 to m do
        Begin
             for j:=1 to n do
                 write(fo,d[i,j],#32);
             writeln(fo);
        end;
end;

BEGIN
     Mofile;
     Docdl;
     Run;
     Inkq;
     Dongfile;
END.











