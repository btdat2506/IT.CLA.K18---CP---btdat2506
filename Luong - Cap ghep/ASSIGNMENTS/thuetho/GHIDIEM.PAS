uses dos;

const
   tfk='BienBan.TXT';

var
   DirInfor: SearchRec;
   fk,fd: text;
   tong,diema,diemb: real;
   id, maua, maub, kqoa,kqob,error: integer;
   Sa,Sb: longint;

function SoSanh(u,v,error: integer): real;
begin
   if (error<>0) and (error<>5) then
      begin
         sosanh:=0;
         exit;
      end;
   if v<=u then SoSanh:=0.5 else
      if u/v>0.98 then SoSanh:=0.2 else SoSanh:=0.0;
end;


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
   Sa:=0;
   Sb:=0;
   while not seekeof(fd) do
      begin
         readln(fd,id, maua, maub, kqoa, kqob,error);
         Sa:=Sa+kqoa;
         Sb:=Sb+kqob;
         diema:=SoSanh(maua,kqoa,error);
         diemb:=SoSanh(maub,kqob,error);
         tong:=tong+diema+diemb;
         write(fk,'Test ',id,':',' Kq A=',maua:5,' Kq B=',maub:5,'HS A=',
         kqoa:5,' HS B=',kqob:5,' Diem A=',diema:4:1,' Diem B=',diemb:4:1);
         case error of
            0: writeln(fk);
            1: writeln(fk,'Loi doc file Output');
            2: writeln(fk,'So hieu khong hop le');
            3: writeln(fk,'Cau a chua phu het');
            4: writeln(fk,'Cau b chua phu het');
            5: writeln(fk,'Lap ky luc moi !!!');
         end;
      end;
   writeln(fk,'---------------------------------------------------');
   writeln(fk,' Tong so diem =  ',Tong:4:1,'-Tong xep hang =',Sa:5,'-',Sb:5);
   close(fk);
END.