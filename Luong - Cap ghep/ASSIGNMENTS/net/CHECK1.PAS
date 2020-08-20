uses    crt;  {net.in4}  {net.ou1}
const
        max 	= 4001;
        ds      : array['1'..'5'] of integer = (3,2,6,1457,1496);
var
		a,b		: array[1..max] of integer;
        n,sl,diem,dem	: integer;
        fi,fo	: string;
        test	: char;
        f		: text;

{procedure make_test;
var  f : text;
	i,x : integer;
begin
    n := 4000;
    assign(f,'net.in');
    rewrite(f);
    writeln(f,n);
    randomize;
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
    if a[i]= 0 then
    begin
        x := random(n)+1;
        if x<>i then writeln(f,i,' ',x);
        a[i] := x;
    end;
    close(f);
    halt;
end;    }

procedure  read_inp;
var   f : text;
      i,x : integer;
begin
    fillchar(a,sizeof(a),0);
    assign(f,fi);
    reset(f);
    readln(f,n);
    write(n:4,' : ');
    while true do
    begin
        readln(f,i,x);
        if i<>0 then a[i] := x;
        if (i=0) and (x=0) then break;
        if seekeof(f) then break;
	end;
    close(f);
end;

procedure  read_out;
var
      i,x,y,z : integer;
begin
    b := a;
    diem := 0;
    readln(f,sl);
    if sl<> ds[test] then exit;
    for i:=1 to sl do
    begin
    	readln(f,x,y,z);
        if (x<1) or (x>n) then
        begin
            write(' Dong ',i, ' Ghi Dinh ',x,' -> ');
            close(f);
            exit;
        end;
        if (y<>0) and ((y<0) or (y>n)) then
        begin
            write(' Dong ',i,' Ghi Dinh ',y,' -> ');
            close(f);
            exit;
        end;
        if (z<1) or (z>n) then
        begin
            write(' Dong ',i,' Ghi Dinh ',z,' -> ');
            close(f);
            exit;
        end;


        if (a[x]<>y) then
        begin
            write(' cung (',x,',',y,') -> ');
            close(f);erase(f);
            exit;
        end;
        b[x] := z;
    end;
    close(f);
    erase(f);

    i := 1;  dem := 1;
    while b[i]<>1 do
	begin
        i := b[i];
        if i=1 then break
        else inc(dem);
	end;
    if dem<>n then exit;
    if b[i]=1 then diem := 1
end;

var tong : integer;


BEGIN
     clrscr;
     textcolor(3);
     writeln('CHUONG TRINH CHAM BAI TOKEN_RING - TEST 1..5 (1 DIEM/1 test)');
     textcolor(15);
     writeln;
     for test := '1' to '5' do
     begin
            write('TEST',test:2,': N=');
          	fi := 'NET.IN' + test;
          	fo := 'NET.OU' + test;
     	  	diem := 0;
     		assign(f,fo);
     		{$I-} reset(f); {$I+}
     		if ioresult<>0 then
     		begin
         		writeln('Chua co file ',fo);
                continue;
     		end;
            read_inp;
            read_out;
            if diem=1 then writeln(' Dung!')
            else writeln('Sai!');
            tong := tong + diem;
    end;
    writeln;
    writeln('*************');textcolor(12);
    writeln(' D I E M: ',2*tong);textcolor(15);
    writeln('*************');
    readln;
END.