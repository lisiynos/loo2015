var
k,m,x:uint64;
a,b,c:longint;
begin
assign(input,'forest.in'); reset(input);
assign(output,'forest.out'); rewrite(output);
read(a,k,b,m,x);
c:=1;
while x>0 do
begin
if (c mod k<>0) or (k=0) then x:=x-a;
if (c mod m<>0) or (m=0) then x:=x-b;
inc(c);
end;
write(c-1);
end.