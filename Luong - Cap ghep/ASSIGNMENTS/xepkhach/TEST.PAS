const
  maxkhach = 200;
  maxxe =20;
  maxsiz = maxkhach+maxxe+2;
var
  nx, m, soxe, da: byte;
  fdat: text;
  fn: string;
  ch: array[1..maxkhach] of char;
  kh: array[1..maxkhach] of byte;
  path: array[1..maxxe] of string[30];
  xe, pxe: array[1..maxxe] of byte;

  procedure ReadInp;
  var i, j, jj, so: byte;
      s: string;
      tmp: char;
  begin
{    write('Doc file input: '); readln(fn);}
    assign(fdat, 'XK.INP');
    {$I-}
    reset(fdat);
    {$I+}
    if IOResult <> 0 then
    begin
      writeln('Khong co file input!');
      halt;
    end;
    readln(fdat, m, nx);
    for i := 1 to m do read(fdat, ch[i]);
    readln(fdat);
    for j := 1 to nx do
    begin
      read(fdat, xe[j]);
      read(fdat, tmp);
      readln(fdat, path[j]);
    end;
    close(fdat);
    fillchar(pxe, sizeof(pxe), 0);
    assign(fdat, 'XK.DAP');
    {$I-}
    reset(fdat);
    {$I+}
    if IOResult = 0 then
    begin
      read(fdat, da); close(fdat);
    end else writeln('Khong co file dap an!');
  end;

  procedure ReadOut;
  var i: byte;
  begin
{    write('Doc file output: '); readln(fn);}
    assign(fdat, 'XK.OUT');
    {$I-}
    reset(fdat);
    {$I+}
    if IOResult <> 0 then
    begin
      writeln('Error: Khong co file output');
      halt;
    end;
    for i := 1 to m do read(fdat, kh[i]);
    close(fdat);
  end;

  procedure Test;
  var i, j: byte;
  begin
    for i := 1 to m do
    begin
      j := kh[i];
      if not (j in [1..nx]) then
      begin
        writeln('Error: Khach ', i, ' khong co xe!');
        halt;
      end;
      if Pos(ch[i], path[j]) = 0 then
      begin
        writeln('Error: Khach ', i, ' khong len duoc xe ', j);
        halt;
      end;
      inc(pxe[j]);
    end;
    soxe := 0;
    for j := 1 to nx do
    begin
      if pxe[j] > xe[j] then
      begin
        writeln('Error: Xe ', j, ' qua tai!');
        halt;
      end;
      if pxe[j] > 0 then inc(soxe);
    end;
    if soxe > da then
      writeln('Error: Chua toi uu!  (dap an ', da, ')')
    else if soxe = da then writeln('Ok!') else writeln('Excellent!');
  end;

BEGIN
  ReadInp;
  ReadOut;
  Test;
END.
