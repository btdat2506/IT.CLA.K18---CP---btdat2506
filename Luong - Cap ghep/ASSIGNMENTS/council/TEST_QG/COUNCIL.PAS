{$M 65521,0,655360}
{$R+,Q+}
PROGRAM Dai_dien;
USES Crt;
CONST
  Inp   = 'COUNCIL.INP';
  Out   = 'COUNCIL.OUT';
  MaxN  = 100;
  MaxPK = 50;
TYPE
  TArr1 = Array[1..MaxN] of Integer;
  TArr2 = Array[1..MaxPK] of Integer;
  TArr3 = Array[1..MaxPK, 1..MaxN] of Integer;
  TArr4 = Array[1..3] of TArr1;
VAR
  fi, fo         : Text;
  n, p, k        : Integer;
  U, B           : TArr2;
  Club           : TArr3;
  G1, G2, M1, M2 : TArr4;
  SG, C          : TArr1;
  Ok             : Boolean;

{---}
PROCEDURE Readdata;
  Var
    i, j, x, y : Integer;

  Begin
    FillChar (Club, Sizeof (Club), 0);

    Assign (fi, Inp);
    Reset (fi);

    Read (fi, n, p, k);

    For i := 1 to n do
      Begin
        Read (fi, x);
        C[i] := x;

        Read (fi, x);

        For j := 1 to x do
          Begin
            Read (fi, y);
            Club[y, i] := 1;
          End;
      End;

    For i := 1 to p do
        Read (fi, U[i]);

    Close (fi);
  End;

{---}
PROCEDURE MatchComp (co : Integer); Forward;

PROCEDURE MatchHuman1 (human : Integer);
  Var
    i : Integer;

  Begin
    M1[2, human] := 1;

    For i := 1 to k do
      If (M2[3, i] = 0) and (Club[i, human] = 1) and (G2[3, i] = 0) then
         Begin
           Ok := True;
           G1[2, human] := i;
           G2[3, i] := human;
           Exit;
         End;

    For i := 1 to k do
      If (M2[3, i] = 0) and (Club[i, human] = 1) and (M1[2, G2[3, i]] = 0) then
         Begin
           M2[3, i] := 1;

           MatchHuman1 (G2[3, i]);

           If Ok then
              Begin
                G1[2, human] := i;
                G2[3, i] := human;
                Exit;
              End;
         End;

    If (G2[2, human] > 0) and (M2[2, human] = 0) and
       (M1[1, G2[2, human]] = 0) then
       Begin
         M2[2, human] := 1;

         MatchComp (G2[2, human]);

         If Ok then
            G2[2, human] := 0;
       End;
  End;

PROCEDURE MatchComp (co : Integer);
  Var
    i : Integer;

  Begin
    M1[1, co] := 1;

    For i := 1 to n do
      If (C[i] = co) then
         Begin
           If (M1[2, i] = 0) and (G2[2, i] = 0) then
              MatchHuman1 (i);

           If (M2[2, i] = 0) and (G2[2, i] > 0) then
              Begin
                M2[2, i] := 1;
                MatchComp (G2[2, i]);
              End;

           If Ok then
              Begin
                Inc (SG[co]);
                G2[2, i] := co;
                Exit;
              End;
         End;
  End;

PROCEDURE Flow1;
  Var
    i : Integer;

  Begin
    FillChar (G1, Sizeof (G1), 0);
    FillChar (G2, Sizeof (G2), 0);
    FillChar (SG, Sizeof (SG), 0);

    For i := 1 to p do
      If (G1[1, i] = 0) then
         Begin
           FillChar (M1, Sizeof (M1), 0);
           FillChar (M2, Sizeof (M2), 0);
           Ok := False;

           MatchComp (i);

           If not Ok then
              Exit;
         End;
  End;

{---}
PROCEDURE MatchClub (cl : Integer); Forward;

PROCEDURE MatchHuman2 (human : Integer);
  Var
    i, j : Integer;

  Begin
    M2[2, human] := 1;

    If (M1[1, C[human]] = 0) then
       Begin
         M1[1, C[human]] := 1;

         If (SG[C[human]] < U[C[human]]) then
            Begin
              Ok := True;
              Inc (SG[C[human]]);
            End
         Else
           For j := 1 to n do
             If (M2[2, j] = 0) and (C[j] = C[human]) and (G2[2, j] = i) then
                Begin
                  MatchHuman2 (j);

                  If Ok then
                     Break;
                End;

         If Ok then
            Begin
              G2[2, human] := C[human];
              Exit;
            End;
       End;

    If (G1[2, human] > 0) and (M1[2, human] = 0) and
       (M2[3, G1[2, human]] = 0) then
       Begin
         M1[2, human] := 1;

         MatchClub (G1[2, human]);

         If Ok then
            G1[2, human] := 0;
       End;
  End;

PROCEDURE MatchClub (cl : Integer);
  Var
    i : Integer;

  Begin
    M2[3, cl] := 1;

    For i := 1 to n do
      If (Club[cl, i] = 1) then
         Begin
           If (M2[2, i] = 0) and (G1[2, i] = 0) then
              MatchHuman2 (i);

           If (M1[2, i] = 0) and (G1[2, i] > 0) then
              Begin
                M1[2, i] := 1;
                MatchClub (G1[2, i]);
              End;

           If Ok then
              Begin
                G1[2, i] := cl;
                G2[3, cl] := i;
                Exit;
              End;
         End;
  End;

PROCEDURE Flow2;
  Var
    i : Integer;

  Begin
    For i := 1 to k do
      If (G2[3, i] = 0) then
         Begin
           FillChar (M1, Sizeof (M1), 0);
           FillChar (M2, Sizeof (M2), 0);
           Ok := False;

           MatchClub (i);

           If not Ok then
              Exit;
         End;
  End;
{---}

PROCEDURE Process;
  Begin
    Flow1;

    If Ok then
       Flow2;
  End;

PROCEDURE WriteResult;
  Var
    i : Integer;

  Begin
    Assign (fo, Out);
    ReWrite (fo);

    If not Ok then
       Writeln (fo, -1)
    Else
       For i := 1 to k do
           Write (fo, G2[3, i], ' ');

    Close (fo);
  End;

{---}
BEGIN
  Clrscr;
  Readdata;
  Process;
  WriteResult;
END.