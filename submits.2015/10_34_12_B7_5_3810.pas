var a,n:integer;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
readln(n);
if n mod 2=0 then a:=n*(n-2);
if n mod 2=1 then a:=n*(n-1);
writeln(a);
end.