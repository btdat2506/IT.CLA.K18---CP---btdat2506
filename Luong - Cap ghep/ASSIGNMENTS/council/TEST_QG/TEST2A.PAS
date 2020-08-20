program Cham_Bai2;
uses crt;
const
      MAXTEST = 6;
      NMAX = 100;
      KPMAX = 50;
      HEX: Array[0..15] of char =
           ('0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f');
type
     ARR = array[0..MAXTEST-1] of integer;
     CLB = set of 1..50;
const
    da: ARR = (-1,1,1,1,1,1);
    dm: Array[0..MAXTEST-1] of real = (2,2,1.5,1.5,1.5,1.5);

var
    finput, foutput: text;
    sInput, sOutput: string;
    sotest: integer;
    i: integer;
    kq: Array[0..MAXTEST-1] of real;
    demdung, demsai: integer;

    {cau truc du lieu cua input}
    n, p, k: integer;
    diem : real;
    lamcty: array[1..NMAX] of integer;  {lamcty[i] la chi so cong ty ma nhan vien thu i lam}
    dsclb: array[1..NMAX] of CLB;    {dsclb[i] cho biet danh sach cac CLB ma nhan vien i tham gia}
    u: array[1..KPMAX] of integer;                 {u[i] cho biet gioi han so luong dai dien cua cong ty i}
    daidien: array[1..KPMAX] of integer;           {danh sach K nguoi dai dien ma output cho ket qua}

{init chuong trinh}
procedure chuanbi;
begin
     demdung := 0;
     demsai := 0;
     diem := 0;
     sotest := MAXTEST;
     fillchar(kq, sizeof(kq), 0);
end;

{chi so cac nguoi dai dien phai khac nhau tung doi mot va co gia tri tu 1->N}
function DungCSDaiDien: boolean;
var i, j: integer;
begin
     {cac chi so dai dien phai tu 1 -> N}
     for i := 1 to k do
         if ((daidien[i] < 1) or (daidien[i] > n)) then
         begin
              writeln(' Chi so cua dai dien thu ', i, ' khong hop le.');
              DungCSDaiDien := false;
              exit;
         end;

     {cac chi so phai khac nhau tung doi mot}
     for i := 1 to k - 1 do
         for j := i + 1 to k do
             if (daidien[i] = daidien[j]) then
             begin
                  writeln(' Dai dien thu ', i, ' trung dai dien ', j, '.');
                  DungCSDaiDien := false;
                  exit;
             end;
     DungCSDaiDien := true;
end;

{nguoi dai dien cua moi cau lac bo phai sinh hoat tai CLB}
function DungCLB: boolean;
var dd: array[1..KPMAX] of boolean;     {danh dau nhung CLB nao da co nguoi dai dien roi.
                                        {dd[i] = true neu CLB i da co nguoi dai dien}
    i, j, cs: integer;
begin
     for i := 1 to k do
     begin
         cs := daidien[i];     {lay chi so nguoi dai dien thu i}

         if not (i in dsclb[cs]) then
         begin
              writeln('  Nguoi ', cs, ' khong sinh hoat tai CLB ', i);
              DungCLB := false;
              exit;
         end;
     end;
     DungCLB := true;

end;

{moi cong ty i phai co tu 1 -> u[i] nguoi dai dien}
function DungCty: boolean;
var dem: array[1..KPMAX] of integer; {dem[i] cho biet so nguoi dai dien cua cong ty i}
    i, j: integer;
begin
     {dau tien cho so luong dem = 0 het}
     for i := 1 to p do  dem[i] := 0;

     for i := 1 to k do
          inc(dem[lamcty[daidien[i]]]);  {tang so luong dai dien cua cong ty ma nguoi dai dien thu i lam}

     for i := 1 to p do begin
         if (dem[i] < 1) then  {so dai dien cua cong ty i < 1}
         begin
              writeln('  Doanh nghiep ', i, ' khong co dai dien');
              DungCty := false;
              exit;
         end;
         if (dem[i] > u[i]) then  {so dai dien cua cong ty i > u[i]}
         begin
              writeln('  Doanh nghiep ', i, ' co qua nhieu dai dien');
              DungCty := false;
              exit;
         end;
     end;
     DungCty := true;
end;

{cho biet 2 file foutput co dung voi file fdapan hien tai hay khong}
function Dung(l: integer): boolean;
var i: integer;
begin
     {doc len nguoi dai dien dau tien cua output}
     {$I-}
     read(foutput, daidien[1]);
     {$I+}

     if ioresult <> 0 then  {doc bi loi}
     begin
          writeln('  File output sai format');
          Dung := false;
          exit;
     end;

     if (daidien[1] = -1) then     {output khong co ket qua}
     begin
          if (da[l] = 1) then     {dap an lai co ket qua}
          begin
               writeln('  Sai. dang le phai co nghiem');
               Dung := false;
               exit;
          end;
     end
     else       {output co ket qua}
     begin
          if (da[l] = -1) then     {dap an lai khong co ket qua}
          begin
               writeln('  Sai. Dang le vo nghiem');
               Dung := false;
               exit;
          end;

          {doc tiep danh sach nhung nguoi dai dien cua output}
          for i := 2 to k do
          begin
              {$I-}
              read(foutput, daidien[i]);
              {$I+}
              if ioresult <> 0 then  {doc bi loi}
              begin
                   writeln('  File output sai format');
                   Dung := false;
                   exit;
              end;
          end;

          Dung := DungCSDaiDien and DungCLB and DungCty;
     end;
end;

{nhap du lieu cua 1 test tu file input}
procedure Input;
var i, j, soC, Clb: integer;
begin
     readln(finput, n, p, k);
     for i := 1 to n do
     begin
          {doc cong ty ma NV i lam va so luong CLB ma NV i tham gia}
          read(finput, lamcty[i], soC);
          dsclb[i] := [];
          for j := 1 to soC do begin
              read(finput, Clb);
              dsclb[i] := dsclb[i] + [Clb];
          end;
          readln(finput);
     end;

     {doc cac so u gioi han so nguoi dai dien cua cac cong ty}
     for i := 1 to p do
         read(finput, u[i]);
end;

{cham test thu k}
procedure ChamTest(l: integer);
var i: integer;
begin
     writeln('Cham test so: ', l);
     assign(finput, sInput);
     assign(foutput, sOutput);
     reset(fInput);

     {$I-}
     reset(foutput);
     {$I+}

     if ioresult <> 0 then  {file output khong ton tai}
     begin
          writeln('  Khong co File output');
          exit;
     end;
     if seekeof(foutput) then
     begin
          writeln('  File output rong !');
          exit;
     end;

     Input;

     if Dung(l) then begin
        kq[l] := dm[l];
        inc(demdung);
        writeln('    Dung !');
     end else begin
        inc(demsai);
     end;
     close(fInput);
     close(foutput);
     erase(foutput);
     writeln('   Diem cua test = ', kq[l]:0:1);
end;

{hien thi ket qua cham bai len man hinh}
procedure HienThiKQCham;
var i: integer;

begin
     writeln;
     writeln('---------------------------------------------');
     writeln;
     writeln;
     writeln('Co ', demdung, ' test dung');
     writeln('Co ', demsai, ' test sai');
     write('Nhung test dung:');
     for i := 0 to sotest-1 do
         if kq[i] > 0 then  begin
            write(i:4); diem := diem+kq[i];
         end;
     writeln;
     writeln;
     writeln('Co ', demsai, ' test sai');
     write('Nhung test sai:');
     for i := 0 to sotest-1 do
         if kq[i] = 0 then
            write(i:4);
     writeln;
     writeln('Tong so diem: ', diem:0:1);
     writeln;
     writeln('---------------------------------------------');
     writeln;
     writeln('Cac file output da duoc xoa.');
     readln;
end;


begin
     chuanbi;

     clrscr;
     writeln;
     writeln('             CHUONG TRINH CHAM BAI 2 - COUNCIL - KHOI A');
     writeln;

     {voi moi test}
     for i := 0 to sotest-1 do
     begin
          sInput := 'Council.In'+HEX[i];
          sOutput:= 'Council.Ou'+HEX[i];

          {cham test thu i}
          ChamTest(i);
     end;

     {hien thi ket qua cham bai}
     HienThiKQCham;
end.