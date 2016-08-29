Var a,b,c,d,p,s,otv:integer;

Begin
readln(a,b,c,d);
For p := 1 to b do
for s := 1 to b do
begin
if (p * s <= b) and (p * s >= a) and (p*2+s*2 >= c) and (p*2+s*2 <= d) then
otv := otv +1;
writeln(p,' ',s);
end;
writeln('');
writeln((otv+1) div 2);
end.