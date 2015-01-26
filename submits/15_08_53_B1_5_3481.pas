var
n:longint;
begin
assign(input,'circle.in'); reset(input);
assign(output,'circle.out'); rewrite(output);
read(n);
n:=round(n*power(2,n-3));
write(n);
end.