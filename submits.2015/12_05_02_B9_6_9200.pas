program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e,i,j,k,x:int64;
begin
assign(input,'forest.in');
reset(input);
read(a,k,b,m,x);
close(input);
d:=x div (a+b);
assign(output,'forest.out');
rewrite(output);
d:=d+(d div k)+(d div m);
write(d);
close(output);
end.
