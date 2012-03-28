{$APPTYPE CONSOLE}

var
 i: Integer;
 u: Integer;
 v: Integer;
 kol: Integer;
 ks: Integer;
 mark: array[1..1000] of Integer;

begin
assign(input, 'comp.in'); reset(input);
assign(output, 'comp.out'); rewrite(output);
kol:=0;
ks:=0;
readln(n, m);
for i:=1 to m do
begin
 readln(u,v);
 if mark[u]=0
 then if mark[v]=0
 then begin {случай 1}
 inc(kol);
 inc(ks);
 mark[u]:= ks;
 mark[v]:= ks;
 end
 else mark[u]:= mark[v] {случай 2}
 else if mark[v]=0
 then mark[v]:= mark[u]
 {случай 2 - симметричный}
 else if mark[u]<>mark[v] {случай 4}
 then begin
 max:= v;
 min:= u;
 if u>v then begin 
 max:= u; 
 min:= v end;
 for i:= 1 to n do 
 if mark[i]= max
 then mark[i]:= min;
 dec(kol);
 end
end;
for i:=1 to N do 
 if mark[i]=0 then inc(kol);
writeln(kol);
end.
