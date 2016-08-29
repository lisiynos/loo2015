Var n,i,j,o:integer;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
o := 0;
n := 0;
readln(n);
for i := 1 to n do
for j := 1 to n do
begin
if i <> j then
o +=1;
end;
writeln(o-n);
end.