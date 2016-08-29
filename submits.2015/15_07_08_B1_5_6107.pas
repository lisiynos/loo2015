var
n:integer;
begin
assign(input,'tiling.in'); reset(input);
assign(output,'tiling.out'); rewrite(output);
read(n);
n:=round(n*power(2,n-3));
if n<4 then n:=1;
write(n);
end.