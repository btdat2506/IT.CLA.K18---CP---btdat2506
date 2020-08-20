CONST
  Inp = 'COUNCIL.IN5P';
  n   = 100;
  p   = 49;
  k   = 50;
  Rd  = 1000;
VAR
  f       : Text;
  i, j, x : Integer;
  Club    : Array[1..n, 0..k] of Byte;
  Comp    : Array[1..n] of Byte;
  U       : Array[1..n] of Byte;
  st      : Boolean;

BEGIN
  For i := 1 to Rd do
      j := Random (1);

  Repeat
    FillChar (U, Sizeof (U), 0);
    For i := 1 to n do
      Begin
        Comp[i] := Random (p) + 1;
        U[Comp[i]] := 1;
      End;

    st := True;
    For i := 1 to p do
      If (U[i] = 0) then
         Begin
           st := False;
           Break;
         End;
  Until st;

  For i := 1 to n do
    Begin
      Club[i, 0] := Random (k) + 1;

      FillChar (U, Sizeof (U), 0);

      For j := 1 to Club[i, 0] do
        Begin
          Repeat
            x := Random (k) + 1;
          Until (U[x] = 0);

          U[x] := 1;
          Club[i, j] := x;
        End;
    End;

  For i := 1 to p do
      U[i] := Random (n) + 1;

  Assign (f, Inp);
  ReWrite (f);

  Writeln (f, n, ' ', p, ' ', k);
  For i := 1 to n do
    Begin
      Write (f, Comp[i], ' ', Club[i, 0]);

      For j := 1 to Club[i, 0] do
          Write (f, ' ', Club[i, j]);

      Writeln (f);
    End;
  For i := 1 to p do
      Write (f, U[i], ' ');

  Close (f);
END.