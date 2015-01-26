program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,l,m,e,i,j,k,x,x1,x2,xr,xm:int64;
begin
assign(input,'forest.in');
reset(input);
read(a,k,b,m,xr);
close(input);
assign(output,'forest.out');
rewrite(output);
xm:=xr;
while(xr>0)do begin
d:=d+(xr div (a+b));
{l:=c;
n:=e;}
c:=(xm div (a+b))div k;
e:=(xm div (a+b))div m;
x1:=c*a;
x2:=e*b;
xm:=xr+x1+x2+(x mod (a+b));
xr:=x1+x2+(x mod (a+b));
end;
write(d);
close(output);
end.
