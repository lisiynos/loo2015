program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,l,m,e,i,j,k,x,x1,x2:int64;
begin
assign(input,'forest.in');
reset(input);
read(a,k,b,m,x);
close(input);
assign(output,'forest.out');
rewrite(output);
while(x>0)do begin
d:=d+(x div (a+b));
{l:=c;
n:=e;}
c:=(x div (a+b)) div k;
e:=(x div (a+b)) div m;
x1:=c*a;
x2:=e*b;
x:=x1+x2+(x mod (a+b));
end;
write(d);
close(output);
end.
