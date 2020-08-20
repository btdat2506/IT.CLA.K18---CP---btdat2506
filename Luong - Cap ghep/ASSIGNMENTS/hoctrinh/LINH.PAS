const
     fi='HOCTRINH.INP';
     go='HOCTRINH.OUT';
     mark:array[1..6]of longint = (5,6,7,8,9,10);
type
    Rank1=array[1..1000] of longint;
    Rank2=array[1..100] of ^Rank1;
var
   Time:array[1..100,1..6] of longint;
   S:array[1..100]of longint;
   F1,F2:array[1..1000]of longint;
   Pre: Rank2;
   T: longint;
   N :longint;
   Res :longint;
   f,g:text;
procedure openfile;
 begin
      assign(f,fi); reset(f);
      assign(g,go); rewrite(g);
 end;
procedure closefile;
 begin
      close(f);
      close(g);
 end;
procedure prepare;
 var
    i : longint;
 Begin
      For i:=1 to 100 do
         Begin
              new(Pre[i]);
              fillchar(Pre[i]^, sizeof(Pre[i]^), 0);
         end;
 end;
procedure liberate;
 var
    i:longint;
 begin
      for i:=1 to 100 do dispose(pre[i]);
 end;
Procedure enter;
 var
    i,j:longint;
 begin
      readln(f,N,T);
      For i:=1 to N do read(f,s[i]);
      readln (f);
      For i:=1 to N do
          begin
               for j:=1 to 6 do Read(f,Time[i,j]);
               Readln(f);
          end;
 end;
procedure process;
 var
    i,j,k:longint;
    Value:longint;
 begin
      fillchar(F1, sizeof(F1), 0);
      fillchar(F2, sizeof(F2), 0);
      for k := 1 to 6 do
          begin
               Value:= Mark[k]*S[1];
               if Value>F1[Time[1,k]] then
                  begin
                       F1[Time[1,k]]:=Value;
                       Pre[1]^[Time[1,k]]:=Time[1,k];
                  end;
          end;
      for i := 2 to N do
          begin
               for j := 1 to T do
                   begin
                        if (F1[j] > 0) and (Pre[i-1]^[j] > 0) then
                        for k := 1 to 6 do
                            if j + Time[i,k] <= T then
                            begin
                                 Value := F1[j] + Mark[k] * S[i];
                                 if F2[j + Time[i,k]] < Value then
                                 begin
                                      F2[j + Time[i,k]] := Value;
                                      Pre[i]^[j + Time[i,k]] := Time[i,k];
                                 end;
                            end;
                   end;
               Move(F2,F1,sizeof(F2));
               Fillchar(F2, sizeof(F2), 0);
          end;
 end;
procedure PrintResult;
 var
   i,j,k: longint;
    Nkq: longint;
    Kq:array[1..100] of longint;
 begin
      res:=0;
      for i:=1 to T do
       if (F1[i]>Res) and (Pre[N]^[i]>0) then
          begin
               res:=F1[i];
               j :=i;
          end;
      writeln(g,Res);
      i:=N;
      Nkq:=0;
      repeat
            k := Pre[i]^[j];
            Inc(Nkq);
            Kq[Nkq] := k;
            Dec(i);
            j := j - k;
      until j = 0;
      for i := Nkq downto 1 do writeln(g, Kq[i]);
 end;
begin
 prepare;
 openfile;
 enter;
 process;
 printresult;
 closefile;
 liberate;
end.