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
end.
