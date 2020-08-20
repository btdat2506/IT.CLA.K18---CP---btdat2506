type
  select = array[1..8] of integer;
const
  ddong: select = (2, 1, -1, -2, -2, -1,  1,  2);
  dcot : select = (1, 2,  2,  1, -1, -2, -2, -1);
  fi = 'XH.INP';
  fo = 'XH.OUT';
var
  a: array[-1..102, -1..102] of byte;
  n, k, w, h, tketqua, tdapan: integer;
  ma, dich: array[1..100, 1..100] of byte;
  f: text;
  codapan: boolean;
(************ xac dinh trong so ****************)

  procedure Enter;
  var i, j, l: integer;
  begin
    fillchar(a, sizeof(a), 1);
    fillchar(ma, sizeof(ma), 0);
    fillchar(dich, sizeof(dich), 0);
    assign(f, fi); reset(f);
    readln(f, n); k := 0;
    for i := 1 to n do
      for j := 1 to n do
      begin
        read(f, a[i, j]);
        if a[i, j] = 2 then
        begin
          ma[i, j] := 1; inc(k);
        end;
      end;
    codapan := true; tdapan := 0;
    if seekeof(f) then codapan := false else read(f, tdapan);
    close(f);
    if codapan then
    begin
      writeln('Dap an:');
      writeln('  t-dapan = ', tdapan);
    end
    else writeln('Chua co dap an!');
  end;

  procedure ReadResult;
  var
      i, u, v, u1, v1, umin, vmin, umax, vmax, sobuoc, maxbuoc, ll: integer;
  begin
    writeln('Ket qua:');
    assign(f, fo); reset(f);
    readln(f, tketqua);
    writeln('  t-ketqua = ', tketqua);
    if tketqua > -1 then
    begin
      maxbuoc := 0;
      umin := n; vmin := n;
      umax := 1; vmax := 1;
      for i := 1 to k do
      begin
        read(f, u, v);
        if not (u in [1..n]) or not (v in [1..n]) then
        begin
          writeln('Error dong ', i, ': o (', u, ',', v, ') nam ngoai');
          exit;
        end;
        if ma[u, v] = 0 then
        begin
          writeln('Error dong ', i, ': Vi tri xuat phat sai');
          exit;
        end;
        if ma[u, v] = 2 then
        begin
          writeln('Error dong ', i, ': Vi tri xuat phat trung lap');
          exit;
        end;
        ma[u, v] := 2;
        sobuoc := 0;
        while not seekeoln(f) do
        begin
          read(f, u1, v1);
          if not (u1 in [1..n]) or not (v1 in [1..n]) then
          begin
            writeln('Error dong ', i, ': o (', u1, ',', v1, ') nam ngoai');
            exit;
          end;
          if abs(u1-u)+abs(v1-v) <> 3 then
          begin
            writeln('Error dong ', i, ': buoc di ', u, ',', v, '-', u1, ',', v1, ' sai');
            exit;
          end;
          if a[u1, v1] = 1 then
          begin
            writeln('Error dong ', i, ': o (', u1, ',', v1, ') bi cam');
            exit;
          end;
          u := u1; v := v1;
          inc(sobuoc);
        end;
        readln(f);
        if maxbuoc < sobuoc then maxbuoc := sobuoc;
        if dich[u, v] > 0 then
        begin
          writeln('Error dong ', i, ': Vi tri ket thuc trung lap');
          exit;
        end;
        dich[u, v] := 1;
        if umin > u then umin := u;
        if vmin > v then vmin := v;
        if umax < u then umax := u;
        if vmax < v then vmax := v;
      end;  {for i}
      writeln('  t-phuongan = ', maxbuoc);
      writeln('  Hang xep = (', umin, ',', vmin, ') - (', umax, ',', vmax, ')');
      {kiem tra hang w, h}
      for u := umin to umax do
        for v := vmin to vmax do
        if dich[u, v] = 0 then
        begin
          writeln('Error: Vi tri ket thuc ', u, ',', v, ' nam ngoai hang');
          exit;
        end;
      if maxbuoc <> tketqua then
        writeln('Error: t-ketqua khong trung voi t-phuongan');
      if codapan then
      begin
        if tketqua > tdapan then
          writeln('Ket qua chua toi uu')
        else
          if tketqua < tdapan then
            writeln('Extra')
          else
            writeln('Ok');
      end;
    end else  {if tketqua > -1}
    begin
      if codapan then
      begin
        if tdapan <> -1 then
          writeln('Error: Co cach xep voi thoi diem ket thuc ', tdapan)
        else
          writeln('Ok');
      end;
    end;
  end;

BEGIN
  Enter;
  ReadResult;
END.

