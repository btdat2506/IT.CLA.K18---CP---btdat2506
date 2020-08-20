PROGRAM Check_Council;
USES Crt;
CONST
  Inp = 'COUNCIL.INP';
  Out = 'COUNCIL.OUT';
  Max = 100;
VAR
  fi, fo              : Text;
  n, p, k             : Integer;
  Mark, U, S, Comp, G : Array[1..Max] of Integer;
  Club                : Array[1..Max, 1..Max] of Byte;
  i, j, x, y          : Integer;

BEGIN
  Clrscr;

  Assign (fi, Inp);
  Assign (fo, Out);
  Reset (fi);
  Reset (fo);

  Readln (fi, n, p, k);

  For i := 1 to n do
    Begin
      Read (fi, Comp[i], x);

      For j := 1 to x do
        Begin
          Read (fi, y);
          Club[y, i] := 1;
        End;
    End;

  For i := 1 to p do
      Read (fi, U[i]);

  For i := 1 to k do
      Read (fo, G[i]);

  Close (fi);
  Close (fo);

  For i := 1 to k do
    Begin
      Inc (Mark[G[i]]);

      If (Mark[G[i]] > 1) then
         Begin
           Writeln ('WRONG : Nguoi ', G[i], ' duoc chon 2 lan');
           Readln;
           Exit;
         End;

      If (Club[i, G[i]] = 0) then
         Begin
           Writeln ('WRONG : Nguoi ', G[i], ' k0 o trong CLB ', i);
           Readln;
           Exit;
         End;

      Inc (S[Comp[G[i]]]);

      If (S[Comp[G[i]]] > U[Comp[G[i]]]) then
         Begin
           Writeln ('WRONG : Cong ty ', Comp[G[i]], ' co qua ',
                    U[Comp[G[i]]], ' nguoi');
           Readln;
           Exit;
         End;
    End;

  For i := 1 to p do
    If (S[i] = 0) then
       Begin
         Writeln ('WRONG : Cong ty ', Comp[G[i]], ' k0 co nguoi nao');
         Readln;
         Exit;
       End;

  Writeln ('CORRECT');
  Readln;
END.