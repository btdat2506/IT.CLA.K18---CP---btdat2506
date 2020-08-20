uses dos;

const
   tfk='BienBan.TXT';

var
   DirInfor: SearchRec;
   fk,fd: text;
   tong,diem: real;
   error,id: integer;

   Tmau,Tout: longint;
   Tyle: real;


BEGIN
   FindFirst('KETQUA.TXT',Archive,DirInfor);
   if DosError<>0 then Halt;
   FindFirst(Tfk,Archive,DirInfor);
   if DosError<>0 then
      begin
         assign(fk,tfk); rewrite(fk);
         close(fk);
      end;
   assign(fk,tfk); append(fk);
   assign(fd,'KETQUA.TXT'); reset(fd);
   writeln(fk);
   writeln(fk,'===================================================');
   writeln(fk,'Ket qua cham bai cua hoc sinh: ',paramstr(1));
   Tong:=0.0;
   while not seekeof(fd) do
      begin
         readln(fd,id,Tmau,Tout,error);
         diem:=0.0;
         if (error=0) or (error=5) then
            begin
               Tyle:=Tmau/Tout;
               if Tyle<=1 then diem:=1.0 else
                  if Tyle<=1.01 then diem:=0.5 else
                    if Tyle<=1.02 then diem:=0.3 else
                      if tyle<=1.03 then diem:=0.2;
            end;
         Tong:=Tong+diem;
         write(fk,'Test ',id,': KQ mau=',Tmau,' KQ HS=',Tout,' Diem=',diem:4:1,' ');
         case error of
            0: writeln(fk);
            1: writeln(fk,'Loi doc file Output');
            2: writeln(fk,'So hieu khong hop le');
            3: writeln(fk,'Trung VDV hoac mon thi');
            4: writeln(fk,'Tinh tong diem sai');
            5: writeln(fk,'Ghi nhan ky luc !!!');
         end;
      end;
   writeln(fk,'---------------------------------------------------');
   writeln(fk,' Tong so diem =  ',Tong:4:1);
   close(fk);
END.