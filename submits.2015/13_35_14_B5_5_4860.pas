program _1;
var n,f,k,i:integer;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);



k:=2;
i:=4;
readln(n);
while i<>n do begin
k:=k+2;
i:=i+1;
end;

f:= n*k;
write(f);
end.