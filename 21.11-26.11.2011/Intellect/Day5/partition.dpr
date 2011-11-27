program Razbieniya;
    type
      Razb = array [byte] of byte;
    var
      N, i, L:    byte;
      X, Temp, O: Razb;
    procedure CountSort(var X: Razb; L: byte);
    var
      i, j, k: integer;
    begin
      k:=1;
      fillchar(Temp, sizeof(Temp), 0); // Clean temp array
      for i:=1 to L do inc(Temp[X[i]]);
      fillchar(O, sizeof(O), 0); // Clean O array
      for i:=1 to 40 do
        for j:=1 to Temp[i] do
        begin
          O[k]:=i;
          inc(k);
        end;
    end;
    procedure Next(var X:Razb;var L:byte);
    var
      i,j: byte;
	  s: word;
    begin
      i:=L-1;s:=X[L];
      while (i>1)and(X[i-1]<=X[i]) do begin s:=s+X[i];dec(i) end;
      inc(X[i]);
      L:=i+s-1;
      for j:=i+1 to L do X[j]:=1
    end;
  begin
    readln(N);
    write('[''');
    L:=N; for i:=1 to L do X[i]:=1;
    for i:=1 to L do
    begin
      write(1);
      if i <> L then write('+');
    end;
    repeat
      Next(X,L); CountSort(X,L);
      write(''',''');
      for i:=1 to L do
      begin
        write(O[i]);
        if i <> L then write('+');
      end;
    until L=1;
    writeln(''']');
  end.
