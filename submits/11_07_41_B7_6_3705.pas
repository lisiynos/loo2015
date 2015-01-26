var a,k,b,m,x,c:real;
begin
assign(input,'forest.in');
reset(input);
assign(output,'forest.out');
rewrite(output);
readln(a,k,b,m,x);

c:=x/(a*(1-1/k)+b*(1-1/m));
writeln(trunc(c));
end.

