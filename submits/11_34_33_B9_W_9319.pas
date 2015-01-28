program run;
uses crt;
var i,j,a,b:integer;
begin
assign(input,'sumsqr.in');
reset(input);
read(a,b);
close(input);
assign(output,'sumsqr.out');
rewrite(output);
write(a*a+b*b);
close(output);          {}
end.
