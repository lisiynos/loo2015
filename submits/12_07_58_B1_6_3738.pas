var
a,k,b,m,x,c,p:integer;

begin
readln(a,k,b,m,x);
p:=0;
c:=0;
while c<x do
begin
if p mod k>0 then c:=c+a;
if p mod m>0 then c:=c+b;
p:=p+1;
end;
p:=p-1;
writeln(p);
end.