(* Cai dat luong theo Ford - Fulkerson kieu 2 *)
(* 25/12/2004 *)

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

const
     tfi                =               'XK.inp';
     tfo                =               'XK.out';
     maxxe              =               20 + 1;
     maxben             =               26 + 1;
     maxN               =               maxxe + maxben + 2;
type
     m1int              =               array[0..maxn] of integer;
     m2flow             =               array[0..maxn, 0..maxn] of integer;
     m1num              =               array['A'..'Z'] of byte;
     m1char             =               array[0..255] of char;
     m1tro              =               array[0..maxn * maxn * 2] of byte;
     m1bool             =               array[0..maxn] of boolean;
var
     fi, fo             :               text;
     C, F, lC, lF       :               m2flow;
     hd, truoc, D       :               m1int;
     kitu               :               m1char;
     num                :               m1num;
     Px, Py             :               m1int;
     free               :               m1bool;
     tro                :               m1tro;
     be                 :               m1int;
     a, vt              :               m1int;
     sokhach, soxe      :               integer;
     soben              :               integer;
     s, t, N, mf        :               integer;
     L, R, giua, xnow   :               integer;
     ok, codt           :               boolean;

     tbegin             :               longint;
     tnow               :               longint absolute 0: 1132;

procedure init;
begin
     fillchar(Px, sizeof(Px), 0);
     fillchar(Py, sizeof(Py), 0);
end;

procedure nhap;
var ch: char;
    i, j, tg, k: integer;
begin
     assign(fi, tfi);
     reset(fi);

     readln(fi, sokhach, tg);   soben := 0;
     fillchar(num, sizeof(num), 0);
     soben := 0;
     for i := 1 to sokhach do
       begin
            read(fi, ch);
            if num[ch] = 0 then
               begin
                    inc(soben);
                    num[ch] := soben;
               end;
            kitu[i] := ch;
            inc(Py[num[ch]]);
       end;
     readln(fi);

     fillchar(C, sizeof(C), 0);
     soxe := 0;
     for i := 1 to tg do
       begin
            read(fi, j);
            free[i] := false;
            while not seekeoln(fi) do
              begin
                read(fi, ch);
                j := num[ch];
                if j = 0 then continue;
                free[i] := true;
              end;
            if free[i] then inc(soxe);
            readln(fi);
       end;

     reset(fi);

     readln(fi);
     readln(fi);
     i := 0;
     for k := 1 to tg do
       begin
            if free[k] then
              begin
                inc(i);
                read(fi, Px[i]);
                vt[i] := k;
                while not seekeoln(fi) do
                  begin
                    read(fi, ch);
                    j := num[ch];
                    if j = 0 then continue;
                    C[i, soxe + j] := sokhach;
                  end;
            end;
            readln(fi);
       end;

     close(fi);
     s := soxe + soben + 1;   t := s + 1;   N := t;
     for j := 1 to soben do
         C[j + soxe, t] := Py[j];
end;

procedure make_link;
var i, j: integer;
begin
     fillchar(be, sizeof(be), 0);
     for i := 1 to soxe do
       if C[s, i] > 0 then
          begin
            inc(be[s]);
            inc(be[i]);
            for j := soxe + 1 to soxe + soben do
             if C[i, j] > 0 then
               begin
                 inc(be[i]);
                 inc(be[j]);
               end;
          end;
     for j := soxe + 1 to soxe + soben do
       if C[j, t] > 0 then
         begin
           inc(be[j]);
           inc(be[t]);
         end;

     for i := 2 to N + 1 do be[i] := be[i] + be[i - 1];

     for i := 1 to soxe do
       if C[s, i] > 0 then
          begin
            tro[be[s]] := i;
            dec(be[s]);
            tro[be[i]] := s;
            dec(be[i]);
            for j := soxe + 1 to soxe + soben do
             if C[i, j] > 0 then
               begin
                 tro[be[i]] := j;
                 dec(be[i]);
                 tro[be[j]] := i;
                 dec(be[j]);
               end;
          end;
     for j := soxe + 1 to soxe + soben do
       if C[j, t] > 0 then
         begin
           tro[be[j]] := t;
           dec(be[j]);
           tro[be[t]] := j;
           dec(be[t]);
         end;
end;

procedure timduong;
var u, v, dau, cuoi, p: integer;
begin
     dau := 0;   cuoi := 1;
     codt := true;
     hd[1] := s;
     fillchar(truoc, sizeof(truoc), 0);   truoc[s] := N + 1;
     repeat
           inc(dau);
           u := hd[dau];
           for p := be[u] + 1 to be[u + 1] do
             begin
               v := tro[p];
               if (truoc[v] = 0) then
                 if C[u, v] > F[u, v] then
                   begin
                     truoc[v] := u;
                     if v = t then exit;
                     inc(cuoi);
                     hd[cuoi] := v;
                   end;
             end;
     until dau = cuoi;
     codt := false;
end;

procedure tangluong;
var u, v, value, tg: integer;
begin
     value := maxint;
     v := t;
     repeat
       u := truoc[v];
       tg := C[u, v] - F[u, v];
       if tg < value then value := tg;
       v := u;
     until v = s;

     inc(mf, value);
     v := t;
     repeat
       u := truoc[v];
       inc(F[u, v], value);
       dec(F[v, u], value);
       v := u;
     until v = s;
end;

procedure maxflow;
var i, j: integer;
    TF: array[0..maxxe] of boolean;
begin
     fillchar(TF, sizeof(TF), 0);
     for i := 1 to xnow do
       TF[a[i]] := true;
     for i := 1 to soxe do
       if TF[i] then C[s, i] := Px[i] else C[s, i] := 0;

     fillchar(F, sizeof(F), 0);
     mf := 0;
     repeat
           timduong;
           if codt then tangluong else break;
     until false;
     ok := mf = sokhach;
end;

procedure try(i: byte);
var j: byte;
begin
     if ok then exit;
     if i > xnow then
        begin
             maxflow;
             exit;
        end;
     for j := a[i - 1] + 1 to soxe - xnow + i do
       begin
         a[i] := j;
         try(i + 1);
       end;
end;

procedure process;
begin
     ok := false;
     a[0] := 0;
     try(1);
end;

procedure xuly;
var i, j: integer;
begin
     lC := C;
     for i := 1 to soxe do
       begin
         C[s, i] := Px[i];
       end;
     make_link;

     L := 1;   R := soxe;
     while L <= R do
       begin
            giua := (L + R) div 2;
            xnow := giua;
            process;
            if ok then
               begin
                    lF := F;
                    R := giua - 1;
               end
            else L := giua + 1;
       end;
end;

procedure ketqua;
var i, j, u, v: integer;
begin
     assign(fo, tfo);
     rewrite(fo);

     F := lF;
     for i := 1 to sokhach do
       begin
            j := num[kitu[i]];
            v := j + soxe;
            for u := 1 to soxe do
              if F[u, v] > 0 then
                begin
                     write(fo, vt[u], ' ');
                     dec(F[u, v]);
                     break;
                end;
       end;
     writeln(fo);

     close(fo);
end;

begin
     tbegin := tnow;
     init;
     nhap;
     xuly;
     ketqua;
     writeln((tnow - tbegin) / 18.23 :0 :4);
end.