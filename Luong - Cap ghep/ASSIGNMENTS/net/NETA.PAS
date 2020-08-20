{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 63840,0,655360}

uses   crt;
const  inp      = 'net.in5';
       out      = 'net.ou5';

       nmax     = 4000 ;

var    f, g             : text;
       a                : array[0.. nmax] of integer ;
       n                : integer;
       den              : array[0.. nmax] of boolean  ;
       svong            : integer;
       dau, cuoi        : array[0.. nmax] of integer;
       chua             : array[0.. nmax ] of boolean;
       ok               : boolean ;

procedure  khoitri;
begin
     assign(f, inp ) ;
     reset( f) ;
     assign(g, out ) ;
     rewrite(g ) ;
end;

procedure   ketthuc;
begin
     close(f ) ;
     close(g );
     halt;
end;

procedure  nhap ;
var i,x : integer ;
begin
     fillchar( a, sizeof( a) ,0 ) ;
     readln(f, n ) ;
     while not seekeof( f) do
     begin
         readln(f, i,x) ;
         if (i=0) and (x=0) then exit
         else a[i] := x;
     end;
end;

procedure chbi ;
var i : integer;
begin
     fillchar(den ,sizeof(den ), false ) ;
     for i := 1 to n do
         if a[i] > 0  then
            den[ a[i]]:= true ; {co dinh i den duoc a[i]}
     svong := 0 ;
     fillchar( chua ,sizeof( chua ), true  ) ;
end;

procedure loang(k  : integer )    ;
begin
     inc( svong ) ;
     dau[svong] := k ;
     chua[k] := false;
     while  ( a[k] >0 ) and ( chua[a[k]] ) do
            begin
                 k := a[k] ;
                 chua[k] := false;
            end;
     cuoi[svong] := k ;
end;

procedure xuly ;
var i : integer;
begin
     ok := false;
     for  i := 1 to n do       {tim so 6, bat dau tu dinh khong co cung vao}
          if  not den[i] then
              begin
                   loang(i ) ;
                   ok := true ;
              end;

     for i :=  1 to n do       {tim so 0, bat dau tu dinh con lai chua xet}
         if chua[i]  then
            loang(i ) ;
end;

procedure  inkq  ;
var i : integer ;
begin
     if  ( not ok  ) and ( svong = 1) then   {truong hop co dung 1 chu trinh}
         begin
              writeln(g, 0 );
              ketthuc;
         end;

     writeln(g , svong );   {truong hop con lai}

     for i := 1 to svong - 1 do
         writeln(g, cuoi[i],' ', a[cuoi[i]],' ', dau[i+1] );

     writeln(g, cuoi[ svong], ' ',a[cuoi[svong]] ,' ',dau[1] );
end;

BEGIN
     khoitri;
     nhap ;
     chbi;
     xuly;
     inkq ;
     ketthuc;
END.
