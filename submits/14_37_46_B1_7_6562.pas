var
n:longint;
begin
assign(input,'tiling.in'); reset(input);
assign(output,'tiling.out'); rewrite(output);
read(n);
n:=round((n*2-1)*power(2,(n-1)))+1*(n-1);
write(n);
end.