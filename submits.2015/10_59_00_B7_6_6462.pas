var a,k,b,m,x,c:integer;
begin
assign(input,'forest.in');
reset(input);
assign(output,'forest.out');
rewrite(output);
readln(a,k,b,m,x);
c:=trunc(a mod k);
b:=trunc(b mod m);
c:=x div (a*(1-1/k)+b*(1-1/m);
writeln(c);
end.

