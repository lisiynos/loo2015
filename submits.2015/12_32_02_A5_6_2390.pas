program q2;
var
n,v:integer;
begin
 Assign(input, 'circle.in');
  Assign(output, 'circle.out');
  reset(input);
  rewrite(output);
read(n);
if n mod 2 = 1 then
v:= n*(n-1)
else
v:= n*2;
write(v);
end.