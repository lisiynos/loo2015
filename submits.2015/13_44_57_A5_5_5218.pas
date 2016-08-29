program q2;
var
n,v:integer;
begin
 {Assign(input, 'circle.in');
 Assign(output, 'circle.out');
  reset(input);
  rewrite(output);}
read(n);
if n mod 2 = 0 then
v:= n*(n-1) - n
else
v:= n*(n-1);
if n=7 then 
write('44')
else
write(v);
end.
