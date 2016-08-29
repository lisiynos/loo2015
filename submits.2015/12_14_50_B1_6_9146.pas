var
a,k,b,m,x,c,p:integer;

begin
assign(input,'forest.in'); reset(input);
assign(output,'forest.out') rewrite(output);
readln(a,k,b,m,x);
p:=0;
c:=0;
repeat
if (p mod k>0) or (k=0) then c:=c+a;
if (p mod m>0) or (k=0)then c:=c+b;
p:=p+1;
until c>=x;
p:=p-1;
writeln(p);
end.