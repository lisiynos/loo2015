var n,k,i:integer;
var C:array [1..100000] of integer;
begin 
assign(input,'tilling.in');
reset(input);
assign(output,'tilling.out');
rewrite(output);
readln(n,k);
for i:=2 to 100000 do begin
c[1]:=2;
c[i]:=c[i-1]*3+1;
end;
writeln(c[n]);
end.
