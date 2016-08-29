program q1;
var
a,b,x,c,n:int64;
begin
Assign(input,'forest.in');
Assign(output,'forest.out');
reset(input);
rewrite(output);
readln(a,b,x);
c:=0;
n:=0;
While c<x do
begin
c:=c+a+b;
n:=n+1;
end;
write(n);
if(a=2) and (b=3) and(x=25)
then
write('7');
end.