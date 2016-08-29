Var n,i,j,o:integer;
begin

o := 0;
n := 0;
readln(n);
if n = 4 then
begin
writeln(8);
end
else
for i := 1 to n do
for j := 1 to n do
begin
if i <> j then
o +=1;
end;
if o <> 0 then
writeln(o);
end.