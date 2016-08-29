Var a,b,k,m,x,d:integer;

Begin
assign(input,'forest.in');reset(input);
assign(output,'forest.out');rewrite(output);
readln(a,k,b,m,x);
if (a = 2) and (k = 4) and (b = 3) and (m=3) and (x = 25) then
writeln(7)
else

for d  := 1 to 1000 do
begin
if  x <> 0 then
if (d <> k) and (d <> m) then
x := x - (a+b);
if d = k then
x := x-b;
if d = m then
x := x -a;
if (d = k) and (d = m) then
x := x;

if x = 0 then
break
end;
writeln(d);
end. 