program sumsqr;

var a,b,s:int64;

BEGIN

assign(input,'sumsqr.in');
reset(input);
assign(output,'sumsqr.out');
rewrite(output);

read(a,b);
a:=sqr(a);
b:=sqr(b);
s:=a+b;
write(s);

close(input);
close(output);

END.