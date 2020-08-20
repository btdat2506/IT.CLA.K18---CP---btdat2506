(* TRINH ANH DUONG - 11 Tin *)

{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}

Program Tro_choi_xep_hinh;
const   input             =               'xep.inp';
        output            =               'xep.out';
        maxn              =               10001;
type    m1by              =               array [0..maxn] of integer;
        m1i               =               array [0..maxn] of integer;
        m2by              =               array [0..maxn,0..3] of byte;
var     n,m               :               integer;
        tho,viec,s,t      :               ^m1by;
        fx,fy             :               m1i;
        a                 :               ^m2by;
        d                 :               m1by;
        codt              :               boolean;
{--------------------------------------------------------------------}
Procedure init;
begin
     new(tho);   new(viec);  new(s);   new(t);
     new(a);
     fillchar (tho^, sizeof(tho^), 0);
     fillchar (viec^, sizeof(viec^), 0);
     fillchar (fx, sizeof(fx), 0);
     fillchar (fy, sizeof(fy), 0);
end;
{--------------------------------------------------------------------}
Procedure nhap;
var f: text;
    i,j,k: integer;
begin
     k:=0;
     assign (f, input);   reset (f);
            readln (f, n, m);
            if n*m>maxn then exit;
            for i:=1 to n*m do read (f, a^[i,0]);
            readln (f);
            for i:=1 to n do
                begin
                     for j:=1 to m do
                         begin inc(k); read (f, d[k]); end;
                     readln (f);
                end;
     close (f);
end;
{--------------------------------------------------------------------}
Function canh (i,j: integer): integer;
var k: integer;
begin
     canh:=255;
     for k:=0 to 3 do
         if a^[i,k]=d[j] then
            begin canh:=k; exit; end;
end;
{--------------------------------------------------------------------}
Procedure inkq;
var f: text;
    i,j: integer;
    ok: boolean;
begin
     ok:=true;
     for i:=1 to n*m do
         if canh(i,tho^[i])=255 then
            begin ok:=false; break; end;
     assign (f, output);   rewrite (f);
            if not ok then write (f, -1)
            else
            begin
            for i:=1 to n*m do
                begin
                     write (f, viec^[i],' ');
                     if i mod m=0 then writeln (f);
                end;
            for i:=1 to n*m do
                begin
                     write (f, canh(viec^[i],i),' ');
                     if i mod m=0 then writeln (f);
                end;
            end;
     close (f);
end;
{--------------------------------------------------------------------}
Function getbit (x,k: byte): byte;
begin
     getbit:=(x shr k) and 1;
end;
{--------------------------------------------------------------------}
Procedure putonbit (var x: byte; k: byte);
begin
     x:=x or (1 shl k);
end;
{--------------------------------------------------------------------}
Function dichbit (x: byte): byte;
var y0,y1,y2,y3,y4,y5,y6,y7: byte;
    k: byte;
begin
     y0:=getbit(x,0);       y1:=getbit(x,1);
     y2:=getbit(x,2);       y3:=getbit(x,3);
     y4:=getbit(x,4);       y5:=getbit(x,5);
     y6:=getbit(x,6);       y7:=getbit(x,7);
     k:=0;
     if y1=1 then putonbit(k,7);
     if y0=1 then putonbit(k,6);
     if y7=1 then putonbit(k,5);
     if y6=1 then putonbit(k,4);
     if y5=1 then putonbit(k,3);
     if y4=1 then putonbit(k,2);
     if y3=1 then putonbit(k,1);
     if y2=1 then putonbit(k,0);
     dichbit:=k;
end;
{--------------------------------------------------------------------}
Procedure khoitao;
var i,j,k: integer;
begin
     for i:=1 to n*m do
         for j:=1 to 3 do a^[i,j]:=dichbit(a^[i,j-1]);
end;
{--------------------------------------------------------------------}
Procedure ktghepcap;
var i,j: integer;
begin
     for i:=1 to n*m do fx[i]:=255;
     for i:=1 to n*m do
         for j:=1 to n*m do
             if fx[i]>canh(i,j) then fx[i]:=canh(i,j);
     for i:=1 to n*m do
         for j:=1 to n*m do
             if (viec^[j]=0) and (fx[i]=canh(i,j)) then
                begin
                     tho^[i]:=j;
                     viec^[j]:=i;
                     break;
                end;
end;
{--------------------------------------------------------------------}
Procedure tangcap (j: integer);
var i,jn: integer;
begin
     while j>0 do
           begin
                i:=t^[j];
                jn:=tho^[i];
                tho^[i]:=j;
                viec^[j]:=i;
                j:=jn;
           end;
end;
{--------------------------------------------------------------------}
Procedure dfs (i: integer);
var j: integer;
begin
     s^[i]:=1;
     for j:=1 to n*m do
         if (t^[j]=0) and (fx[i]+fy[j]=canh(i,j)) then
            begin
                 t^[j]:=i;
                 if viec^[j]=0 then
                    begin
                         tangcap(j);
                         codt:=true;
                         exit;
                    end;
                 dfs(viec^[j]);
                 if codt then exit;
            end;
end;
{--------------------------------------------------------------------}
Function min (x,y: integer): integer;
begin
     if x<y then min:=x else min:=y;
end;
{--------------------------------------------------------------------}
Procedure suanhan;
var i,j,delta: integer;
begin
     delta:=maxint;
     for i:=1 to n*m do
         if s^[i]=1 then
            for j:=1 to n*m do
                if t^[j]=0 then delta:=min(delta,-fx[i]-fy[j]+canh(i,j));
     for i:=1 to n*m do
         if s^[i]=1 then fx[i]:=fx[i]+delta;
     for j:=1 to n*m do
         if t^[j]>0 then fy[j]:=fy[j]-delta;
end;
{--------------------------------------------------------------------}
Procedure main;
var i,j: integer;
begin
     if n*m>maxn then exit;
     khoitao;
     ktghepcap;
     for i:=1 to n*m do
         while tho^[i]=0 do
            begin
                 fillchar (t^, sizeof(t^), 0);
                 fillchar (s^, sizeof(s^), 0);
                 codt:=false;
                 dfs(i);
                 if not codt then suanhan;
            end;
end;
{--------------------------------------------------------------------}
begin
     init;
     nhap;
     main;
     inkq;
end.