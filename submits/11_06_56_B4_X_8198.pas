program asd;

var a,d,c:integer;
begin
assign(input,'asd.in');
assign(output,'asd.out');
reset(input);
rewrite(output);
read(a,d);
c:=a*a+d*d;
writeln(c);
end.
