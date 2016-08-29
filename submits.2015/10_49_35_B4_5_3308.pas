program circle;
var
n,s:integer;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
read(n);
if (n>=3) and (n<=25) then
s:=(2*n)*(n-3);
write(s)
end.