const
  maxsiz = 100;
type
  vector = array[1..maxsiz] of integer;
  matrix = array[1..maxsiz] of vector;
  kieucanh = record
           truoc, sau: integer;
         end;
  mangcanh = array[1..maxsiz*maxsiz] of kieucanh;

var
  c: matrix;
  n, k, phat, thu: integer;
  p, q: vector;
  ncanh: integer;  {so canh noi hai lop}
  canh: ^mangcanh; {cac canh noi hai lop}
  tda, nda, tkq: integer;

  procedure Enter;
  var u, i, j, dem, s: integer;
      fdat: text;
  begin
    assign(fdat, 'NET.INP'); reset(fdat);
    readln(fdat, n);
    readln(fdat, k);
    for u := 1 to k do
    begin
      read(fdat, i, j, c[i, j]);
      c[j, i] := c[i, j];
    end;
    readln(fdat, phat, thu);
    read(fdat, tda, nda);
    close(fdat);
    assign(fdat, 'NET.OUT'); reset(fdat);
    readln(fdat, ncanh);
    new(canh);
    for i := 1 to ncanh do
      readln(fdat, canh^[i].truoc, canh^[i].sau);
    close(fdat);
  end;

  procedure BoCanh;
  var i, j: integer;
  begin
    tkq := 0;
    for i := 1 to ncanh do
    begin
      if tkq < c[canh^[i].truoc, canh^[i].sau] then
        tkq := c[canh^[i].truoc, canh^[i].sau];
      c[canh^[i].truoc, canh^[i].sau] := 0;
      c[canh^[i].sau, canh^[i].truoc] := 0;
    end;
  end;

  function OK: boolean;
  var dau, cuoi, u, v: integer;
  begin
    FillChar(p, SizeOf(p), 0);
    p[phat] := phat;
    dau := 1; q[dau] := phat; cuoi := dau;
    while cuoi-dau+1 > 0 do
    begin
      u := q[dau];
      for v := 1 to n do
      if (c[u, v] > 0) and (p[v] = 0) then
      begin
        p[v] := u; inc(cuoi); q[cuoi] := v;
        if v = thu then
        begin
          OK := false; exit;
        end;
      end;
      inc(dau);
    end;
    OK := true;
  end;

BEGIN
  Enter;
  BoCanh;
  writeln('Nhan xet:');
  if not OK then
    writeln('  Error: Khong huy duoc duong di!')
  else
    if tkq > tda then
      writeln('  Error: Thoi gian khong toi uu (ket qua: ', tkq,
               ', dap an: ', tda, ')')
      else
      if ncanh > nda then
        writeln('  Error: So canh khong toi uu (ket qua: ', ncanh,
                 ', dap an: ', nda, ')')
        else
        begin
          writeln('  OK');
          if tkq < tda then writeln('  Extra T!');
          if ncanh < nda then write('  Extra N!');
        end;
END.

