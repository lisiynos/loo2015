program run;
uses crt;
var i,a,b:longint;
begin
clrscr;
assign(input,'sumsqr.in');
reset(input);
read(a,b);
close(input);
assign(output,'sumsqr.out');
rewrite(output);
write(a*a+b*b);
close(output);
end.
