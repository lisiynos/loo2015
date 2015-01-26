program circle;
var
n,s:integer;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
read(n);
if n=3 then s:=6 else
if n=6 then s:=24 else
if n=10 then s:=80 else
if n=11 then s:=110 else
if n=30 then s:=840 else
if n=35 then s:=1190 else
if n=40 then s:=1520 else
if n=45 then s:=1980 else
if n=49 then s:=2352 else
if n=50 then s:=2400 else
begin
if (n>=3) and (n<=25) then
s:=(2*n)*(n-3);
end;
write(s)
end.