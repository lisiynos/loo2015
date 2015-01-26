var n,i,m,l:int64;
begin
assign (input,'circle.in'); reset(input);
assign (output,'circle.out'); rewrite(output);
read(n);
for i:=1 to n do 
for m:=1 to n do 
if (i<>m) and ((i mod 2<>m mod 2) or (n mod 2>0)) then inc(l);
write(l);
end.