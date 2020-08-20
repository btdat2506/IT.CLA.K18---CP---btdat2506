Program hoctrinh;

Const
        Tfi             ='HOCTRINH.INP';
        Tfo             ='HOCTRINH.OUT';
        Mark            :array[1..6]of longint = (5,6,7,8,9,10);

Type
        Rank1           =array[1..1000] of longint;
        Rank2           =array[1..100] of ^Rank1;

Var
        Time            :array[1..100,1..6] of longint;
        S               :array[1..100]of longint;
        F1,F2           :array[1..1000]of longint;
        Pre             :Rank2;
        T               :longint;
        N               :longint;
        Res             :longint;
        Fi,Fo           :text;

Procedure OpenFile;
Begin
 Assign (Fi, Tfi);
 Reset (Fi);
 Assign (Fo, Tfo);
 Rewrite (Fo);
End;

Procedure CloseFile;
Begin
 Close (Fi);
 Close (Fo);
End;

Procedure Prepare;
Var i : longint;
Begin
 For i := 1 to 100 do
  Begin
   New(Pre[i]);
   Fillchar(Pre[i]^, sizeof(Pre[i]^), 0);
  End;
End;

Procedure Liberate;
Var i : longint;
Begin
 For i := 1 to 100 do dispose(Pre[i]);
End;

Procedure Enter;
Var i,j : longint;
Begin
 Readln (Fi, N, T);
 For i := 1 to N do Read(Fi, s[i]);
 Readln (Fi);
 For i := 1 to N do
  Begin
   For j := 1 to 6 do Read(Fi,Time[i,j]);
   Readln(Fi);
  End;
End;

Procedure Process;
Var i,j,k : longint;
    Value : longint;
Begin
 Fillchar(F1, sizeof(F1), 0);
 Fillchar(F2, sizeof(F2), 0);
 For k := 1 to 6 do
  Begin
   Value := Mark[k] * S[1];
   If Value > F1[Time[1,k]] then
    Begin
     F1[Time[1,k]] := Value;
     Pre[1]^[Time[1,k]] := Time[1,k];
    End;
  End;
 For i := 2 to N do
  Begin
   For j := 1 to T do
    Begin
     If (F1[j] > 0) and (Pre[i-1]^[j] > 0) then
      For k := 1 to 6 do
       If j + Time[i,k] <= T then
        Begin
         Value := F1[j] + Mark[k] * S[i];
         If F2[j + Time[i,k]] < Value then
          Begin
           F2[j + Time[i,k]] := Value;
           Pre[i]^[j + Time[i,k]] := Time[i,k];
          End;
        End;
    End;
   Move(F2,F1,sizeof(F2));
   Fillchar(F2, sizeof(F2), 0);
  End;
End;

Procedure PrintResult;
Var i,j,k : longint;
    Nkq   : longint;
    Kq    : array[1..100] of longint;
Begin
 Res := 0;
 For i := 1 to T do
  If (F1[i] > Res) and (Pre[N]^[i] > 0) then
   Begin
    Res := F1[i];
    j := i;
   End;
 Writeln(Fo, Res);
 i := N;
 Nkq := 0;
 Repeat
  k := Pre[i]^[j];
  Inc(Nkq);
  Kq[Nkq] := k;
  Dec(i);
  j := j - k;
 Until j = 0;
 For i := Nkq downto 1 do writeln(Fo, Kq[i]);
End;

BEGIN
 Prepare;
 OpenFile;
 Enter;
 Process;
 PrintResult;
 CloseFile;
 Liberate;
END.