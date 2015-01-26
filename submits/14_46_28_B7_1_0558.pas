var 
A,B,C,D,x,i:integer;
begin
assign(input, 'hall.in');
reset(input);
assign(output, 'hall.out');
rewrite(output);
readln(A,B,C,D);
for i:=1 to B do begin
if ((A/i+i)*2>=C) and ((A/i+i)*2<=D) 
then inc(x);
end;
writeln(x);
end.
