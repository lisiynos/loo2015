Var n,i,j,o:integer;

Begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
n := 0;
o := 0;
readln(n);
for i := 1 to n do
for j := 1 to n do
begin
if (i <> j) then
if (i mod 2 = 0) and (j mod 2 <> 0) then
o += 1
else if (i mod 2 <> 0) and (j mod 2 = 0) then
o += 1;
end;
writeln(o);
end.