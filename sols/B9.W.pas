program run;
uses crt;
var i,j,a,b:longint;
begin
clrscr;
assign(input,'sum.in');
reset(input);
read(a,b);
close(input);
assign(output,'sum.out');
rewrite(output);
write(a+b);
close(output);
end.
