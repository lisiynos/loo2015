     program q2;
var
n,k,i,max,min:integer;
a: array [1..100000] of integer;
begin
  Assign (Input,'prizes.in');
  Assign (Output,'prizes.out');
  reset(input);
  Rewrite(output);
readln(n,k);
for i:=1 to n do
begin
read(a[i]);

end; 

max:=a[i];
for i:=1 to n do
begin
if a[i]>max
then
max:=a[i];
end;

min:=a[i];
for i:=1 to n do
begin
if a[i]<max
then
min:=a[i];
end;

writeln(min+max);
end.
