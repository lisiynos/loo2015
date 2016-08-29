var 
a,b,c,d,x,y,i:longint;
begin
assign(input, 'hall.in');
reset(input);
assign(output, 'hall.out');
rewrite(output);
readln(a,b,c,d);
for i:=1 to 100000 do begin
if ((a/i+i)*2>c) and ((a/i+i)*2<d) and ((b/i+i)*2>c) and ((b/i+i)*2<d)
then writeln(i, a/i);
end;
end.
