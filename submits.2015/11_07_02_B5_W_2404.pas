program _W;
var a,b,s:integer;
begin
assign(input,'sum.in');
assign(output,'sum.out');
reset(input);
rewrite(output);
readln(a,b);
s:=a+b;
write(s);
end.