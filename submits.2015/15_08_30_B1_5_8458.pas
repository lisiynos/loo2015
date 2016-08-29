var
n:longint;
begin
assign(input,'circle.in'); reset(input);
assign(output,'circle.out'); rewrite(output);
read(n);
n:=round(n*power(2,n-3));
if n<4 then n:=1;
write(n);
end.