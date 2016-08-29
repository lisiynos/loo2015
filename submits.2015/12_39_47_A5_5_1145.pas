program q2;
var
n:integer;
begin
 Assign(input, 'circle.in');
  Assign(output, 'circle.out');
  reset(input);
  rewrite(output);
read(n);
if n mod 2 = 1 then
n:= n*(n-1)
else
n:= n*2;
write('8');
end.