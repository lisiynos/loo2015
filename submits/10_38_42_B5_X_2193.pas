program _2;
var a,b,s:integer;
begin
assign(input,'sumsqr.in');
assign(output,'sumsqr.out');
reset(input);
rewrite(output);
readln(a,b);
a:=sqr(a);
b:=sqr(b);
s:=a+b;
write(s);
end.