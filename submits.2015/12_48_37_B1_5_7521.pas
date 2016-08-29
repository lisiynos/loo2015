var
n:int64;
begin
assign(input,'circle.in'); reset(input);
assign(output,'circle.out'); rewrite(output);
read(n);
n:=n*2*(n-3);
if n=0 then n:=1;
write(n);
end.