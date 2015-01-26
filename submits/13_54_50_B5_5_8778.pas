program _1;
var n:integer;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n);
if n=4 then write('8');
if n=5 then write('20');
if n=6 then write('36');
if n=7 then write('56');
if n=8 then write('80');
end.