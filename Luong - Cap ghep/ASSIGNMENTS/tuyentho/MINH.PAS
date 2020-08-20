{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16000,0,655360}
uses crt;
const
  FILEINP='ASSIGN.IN0987654321P';
  FILEOUT='ASSIGN.OU0987654321T';
  MAX=300;
  MAXC=15000;
type
  Arr1=array[1..2*MAX]of integer;
  Arr4=array[1..MAX]of integer;
  Arr2=array[1..MAX]of ^Arr4;
  Arr3=array[1..2*MAX]of boolean;
var
  n,m,r,Start,Finish,Result1:integer;
  Result2:longint;
  MatchX,MatchY,Fx,Fy,Trace,List,Best,Save:Arr1;
  c:Arr2;
 procedure Enter;
  var
    f:text;
    i,j,u,v:integer;
  begin
    assign(f,FILEINP);
    reset(f);
    readln(f,m,n,r);
    for i:=1 to m do
     read(f,List[i]);
    readln(f);
    for i:=1 to n do
     begin
       new(c[i]);
       for j:=1 to r do
        c[i]^[j]:=-MAXC;
     end;
    while not SeekEof(f) do
     begin
       read(f,v,u,c[u]^[v]);
       c[u]^[v]:=-c[u]^[v];
     end;
  end;
 procedure Init;
  var
    i,j:integer;
  begin
    fillchar(MatchX,SizeOf(MatchX),0);
    fillchar(MatchY,SizeOf(MatchY),0);
    fillchar(Fy,SizeOf(Fy),0);
    for i:=1 to n do
     begin
       Fx[i]:=c[i]^[List[1]];
       for j:=2 to m do
        if c[i]^[List[j]]>Fx[i] then Fx[i]:=c[i]^[List[j]];
       if Result1>0 then
        begin
          Save[i]:=1;
          Best[i]:=c[i]^[1];
          for j:=2 to r do
           if c[i]^[j]>Best[i] then
            begin
              Best[i]:=c[i]^[j];
              Save[i]:=j;
            end;
          if Best[i]>Fx[i] then Fx[i]:=Best[i];
       end;
     end;
  end;
 function GetC(i,j:integer):integer;
  begin
    if j<=m then GetC:=Fx[i]+Fy[j]-c[i]^[List[j]]
    else GetC:=Fx[i]+Fy[j]-Best[i];
  end;
 function FindAugmentingPath:integer;
  var
    Queue:Arr1;
    i,j,Top,Bot:integer;
  begin
    fillchar(Trace,SizeOf(Trace),0);
    Queue[1]:=Start;
    Top:=1;
    Bot:=1;
    while Top<=Bot do
     begin
       i:=Queue[Top];
       inc(Top);
       for j:=1 to m+Result1 do
        if (Trace[j]=0) and (GetC(i,j)=0) then
         begin
           Trace[j]:=i;
           if MatchY[j]=0 then
            begin
              FindAugmentingPath:=j;
              exit;
            end;
           inc(Bot);
           Queue[Bot]:=MatchY[j];
         end;
     end;
    FindAugmentingPath:=0;
  end;
 procedure EnLarge;
  var
    x,Next:integer;
  begin
    repeat
     x:=Trace[Finish];
     Next:=MatchX[x];
     MatchX[x]:=Finish;
     MatchY[Finish]:=x;
     Finish:=Next;
    until Finish=0;
  end;
 procedure SubX_AddY;
  var
    i,j,Delta:integer;
    VisitedX,VisitedY:Arr3;
  begin
    fillchar(VisitedX,SizeOf(VisitedX),False);
    fillchar(VisitedY,SizeOf(VisitedY),False);
    VisitedX[Start]:=True;
    for i:=1 to m+Result1 do
     if Trace[i]<>0 then
      begin
        VisitedX[MatchY[i]]:=True;
        VisitedY[i]:=True;
      end;
    Delta:=maxint;
    for i:=1 to n do
     if VisitedX[i] then
      for j:=1 to m+Result1 do
       if (not VisitedY[j]) and (GetC(i,j)<Delta) then Delta:=GetC(i,j);
    for i:=1 to n do if VisitedX[i] then dec(Fx[i],Delta);
    for i:=1 to m do if VisitedY[i] then inc(Fy[i],Delta);
  end;
 procedure Solve;
  var
    i,Min:integer;
  begin
    Result1:=0;
    Init;
    Min:=n;
    if Min>m then Min:=m;
    for Start:=1 to Min do
     begin
       repeat
        Finish:=FindAugmentingPath;
        if Finish=0 then SubX_AddY;
       until Finish<>0;
       Enlarge;
     end;
    for i:=1 to n do
     if (MatchX[i]=0) or (c[i]^[List[MatchX[i]]]=-MAXC) then inc(Result1);
    Init;
    for Start:=1 to n do
     begin
       repeat
        Finish:=FindAugmentingPath;
        if Finish=0 then SubX_AddY;
       until Finish<>0;
       Enlarge;
     end;
  end;
 procedure PrintResult;
  var
    f:text;
    i:integer;
  begin
    assign(f,FILEOUT);
    rewrite(f);
    Result2:=0;
    for i:=1 to n do
     if MatchX[i]<=m then dec(Result2,c[i]^[List[MatchX[i]]])
     else dec(Result2,Best[i]);
    writeln(f,Result1,' ',Result2);
    for i:=1 to n do
     if MatchX[i]<=m then writeln(f,List[MatchX[i]])
     else writeln(f,Save[i]);
    close(f);
  end;
begin
  clrscr;
  Enter;
  Solve;
  PrintResult;
end.