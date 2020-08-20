{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
Program Bai_Tap;

Uses crt,dos;

Const fi                   ='Guards.in987654321';
      fo                   ='Guards.ou987654321t';
      vc                   =maxlongint div 3;
      dh                   :array[1..4]of integer = (-1,0,1,0);
      dc                   :array[1..4]of integer = (0,1,0,-1);

Type  mangb                =array[0..201,0..201]of boolean;

Var
      m,n                  :longint;
      f                    :text;
      a                    :array[0..201,0..201]of byte;
      nkq                  :longint;
      cx                   :^mangb;

Procedure Nhap;
Var i,j:longint;
Begin
     Clrscr;
     Assign(f,fi);
     reset(f);
     readln(f,m,n);
     fillchar(a,sizeof(a),2);
     for i:=1 to m do
         for j:=1to n do
             read(f,a[i,j]);
     close(f);
End;

Procedure ChuanBi;
Begin
     new(cx);
End;

Function ok(i,j,k:Longint):boolean;
var u,v:integer;
Begin
     ok:=true;
     u:=i;
     v:=j;
     repeat
           u:=u+dh[k];
           v:=v+dc[k];
           if a[u,v]=2 then exit;
           if a[u,v]=3 then
           begin
                ok:=false;
                exit;
           end;
     until false;
End;

Function tinh(i,j,k:integer;var t:longint):boolean;
var u,v:integer;
begin
     u:=i+dh[k];
     v:=j+dc[k];
     while a[u,v]=1 do
     begin
          u:=u+dh[k];
          v:=v+dc[k];
     end;
     if (a[u,v]=2) then tinh :=false else tinh:=true;
     t:=0;
     u:=i+dh[k];
     v:=j+dc[k];
     while a[u,v]=1 do
     begin
          u:=u+dh[k];
          v:=v+dc[k];
     end;
     while (a[u,v]=2)and(u>=1) and (u<=m) and (v>=1) and (v<=n) do
     begin
     inc(t);
     u:=u+dh[k];
     v:=v+dc[k];
     end;
end;

Function mat(i,j,k:integer):boolean;
Begin
End;

Procedure Run;
label l1;
var i,j,u,v,k,l,p,t,q:longint;
    found,tot:boolean;
    min,mp:longint;
Begin
     Assign(f,fo);
     rewrite(F);
     nkq:=0;
     fillchar(cx^,sizeof(cx^),true);
     repeat
           found:=false;
           min:=vc;
           for i:=1 to m do
               for j:=1 to n do
               if a[i,j]=0 then
               if cx^[i,j] then
               Begin
                    tot:=false;
                    for k:=1 to 4 do
                        if not ok(i,j,k) then goto l1;
                    tot :=true;
                    l1:
                    if tot then
                       begin
                            l:=0;
                            p:=0;
                            for k:=1 to 4 do
                                if tinh(i,j,k,t) then inc(l) else p:=p+t;
                            if (min>l) or ((min=l)and(mp<p)) then
                               begin
                                    min:=l;
                                    mp:=p;
                                    u:=i;
                                    v:=j;
                                    found:=true;
                               end;
                       end;
               End;
           if found then
              begin
                   a[u,v]:=3;
                   inc(nkq);
                   cx^[u,v]:=false;
                   for k:=1 to 4 do
                       begin
                            p:=u+dh[k];
                            q:=v+dc[k];
                            while a[p,q]=0 do
                            begin
                                 cx^[p,q]:=false;
                                 p:=p+dh[k];
                                 q:=q+dc[k];
                            end;
                            cx^[p,q]:=false;
                       end;
              end;
     until not found;
End;

Procedure Inkq;
Var i,j:longint;
Begin
     writeln(f,nkq);
     for i:=1 to m do
         for j:=1 to n do
             if a[i,j]=3 then
                  writeln(f,i,' ',j);
     close(F);
End;

Procedure Gp;
Begin
     dispose(cx);
End;

Procedure sinh;
var i,j:longint;
Begin
     Assign(f,fi);
     rewrite(f);
     writeln(f,50,' ',50);
     randomize;
     for i:=1 to 100 do
     begin
         for j :=1 to 100 do
             write(f,random(3),' ');
         writeln(f);
     end;
     close(f);
End;

(*************************************************************************)
Begin

{     Sinh;}
     ChuanBi;
     Nhap;
     Run;
     Inkq;
     Gp;

End.
