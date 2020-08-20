(*  *)

{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}

const
     tfi                =               'assign.in0987654321p';
     tfo                =               'assign.ou0987654321t';
     maxn               =               300 + 1;
     maxc               =               10001;
type
     m1int              =               array[0..maxn] of integer;
     m2int              =               array[0..maxn] of ^m1int;
     m1long             =               array[0..maxn] of longint;
var
     fi, fo             :               text;
     C                  :               m2int;
     truoc, hd, arg     :               m1int;
     tho, viec          :               m1int;
     kieu, Cmin         :               m1int;
     Fx, Fy, D          :               m1long;
     lFx, lFy           :               m1long;
     M, N, R            :               integer;
     old, sta, fin      :               integer;
     dau, cuoi          :               integer;
     total              :               longint;
     ok                 :               boolean;

     po                 :               pointer;
     tbegin             :               longint;
     tnow               :               longint absolute 0: 1132;

procedure init;
var i: integer;
begin
     mark(po);
     for i := 1 to maxn do
       begin
            new(C[i]);
            fillchar(C[i]^, sizeof(C[i]^), $FF);
       end;
end;

procedure nhap;
var i, j, u, v: integer;
begin
     assign(fi, tfi);
     reset(fi);

     readln(fi, M, N, R);
     for i := 1 to M do read(fi, kieu[i]);   readln(fi);
     while not seekeof(fi) do
       readln(fi, u, v, C[u]^[v]);

     close(fi);
end;

procedure tangcap(j: integer);
var i, jnext: integer;
begin
     while j > 0 do
       begin
            i := truoc[j];
            jnext := tho[i];
            tho[i] := j;
            viec[j] := i;
            j := jnext;
       end;
end;

procedure BFS(i: integer);
var dau, cuoi, j: integer;
begin
     dau := 0;   cuoi := 1;
     hd[1] := i;
     fillchar(truoc, sizeof(truoc), 0);
     repeat
           inc(dau);
           i := hd[dau];
           for j := 1 to N do
             if (truoc[j] = 0) and (C[kieu[i]]^[j] >= 0) then
               begin
                    truoc[j] := i;
                    if viec[j] = 0 then
                      begin
                           tangcap(j);
                           exit;
                      end;
                    inc(cuoi);
                    hd[cuoi] := viec[j];
               end;
     until dau = cuoi;
end;

procedure cgdon;
var i, j: integer;
begin
     old := M;
     fillchar(tho, sizeof(tho), 0);
     fillchar(viec, sizeof(viec), 0);
     for i := 1 to M do BFS(i);
     for j := 1 to N do
       if viec[j] = 0 then inc(M);

     fillchar(Cmin, sizeof(Cmin), $5F);
     for j := 1 to N do
       begin
         for i := 1 to R do
           if (C[i]^[j] <> -1) and (C[i]^[j] < Cmin[j]) then
              Cmin[j] := C[i]^[j];
         if Cmin[j] = Cmin[0] then Cmin[j] := -1;
       end;
end;

function get(i, j: integer): longint;
begin
     if i > old then get := Cmin[j]
     else get := C[kieu[i]]^[j];
end;

function found: boolean;
var i, j: integer;
    w: longint;
begin
     found := true;
     if fin <> 0 then exit;
     if ok then exit;
     repeat
           inc(dau);
           i := hd[dau];
           for j := 1 to N do
             if (truoc[j] = 0) and (get(i, j) <> -1) then
               begin
                    w := get(i, j) - Fx[i] - Fy[j];
                    if w = 0 then
                      begin
                           truoc[j] := i;
                           if viec[j] = 0 then
                             begin
                                  fin := j;
                                  exit;
                             end;
                           inc(cuoi);
                           hd[cuoi] := viec[j];
                      end
                    else
                      if w < D[j] then
                        begin
                             D[j] := w;
                             arg[j] := i;
                        end;
               end;
     until dau = cuoi;
     found := false;
end;

procedure suanhan;
var delta, i, j: longint;
begin
     delta := maxlongint;
     for j := 1 to N do
       if (truoc[j] = 0) and (D[j] < delta) then delta := D[j];
     if delta > maxc then
       begin
            ok := true;    exit;
       end;
     Fx[sta] := Fx[sta] + delta;
     for j := 1 to N do
       if truoc[j] = 0 then D[j] := D[j] - delta
       else
         begin
              i := viec[j];
              Fx[i] := Fx[i] + delta;
              Fy[j] := Fy[j] - delta;
         end;
     for j := 1 to N do
       if (D[j] = 0) and (truoc[j] = 0) then
         begin
              truoc[j] := arg[j];
              if viec[j] = 0 then
                begin
                     fin := j;
                     exit;
                end;
              inc(cuoi);
              hd[cuoi] := viec[j];
         end;
end;

procedure cgts;
var i, j: integer;
begin
     fillchar(tho, sizeof(tho), 0);
     fillchar(viec, sizeof(viec), 0);
     fillchar(Fx, sizeof(Fx), 0);
     fillchar(Fy, sizeof(Fy), 0);
     total := 0;
     for i := 1 to M do
       begin
            fillchar(truoc, sizeof(truoc), 0);
            ok := false;
            dau := 0;   cuoi := 1;
            sta := i;   fin := 0;
            hd[1] := i;
            lFx := Fx;   lFy := Fy;
            for j := 1 to N do
              begin
                   D[j] := maxlongint;
                   arg[j] := i;
              end;
            while not found do suanhan;
            if fin <> 0 then tangcap(fin)
            else
              begin
                   Fx := lFx;
                   Fy := lFy;
              end;
       end;
end;

procedure xuly;
begin
     cgdon;
     cgts;
end;

procedure ketqua;
var i, j, k: integer;
begin
     assign(fo, tfo);
     rewrite(fo);

     total := 0;
     for j := 1 to N do total := total + get(viec[j], j);
     writeln(fo, M - old, ' ', total);
     for j := 1 to N do
       begin
            i := viec[j];
            if i <= old then writeln(fo, kieu[i])
            else
                for k := 1 to R do
                  if C[k]^[j] = Cmin[j] then
                     begin
                          writeln(fo, k);
                          break;
                     end;
       end;

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