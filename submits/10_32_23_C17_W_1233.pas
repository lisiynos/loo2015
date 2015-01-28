program sum;

var a,b,s:integer;

BEGIN

assign(input,'sum.in');
reset(input);
assign(output,'sum.out');
rewrite(output);

read(a,b);
s:=a+b;
write(s);

close(input);
close(output);

END.