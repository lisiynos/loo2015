var n,i,m,l:longint;
begin
assign (input,'circle.in'); reset(input);
assign (output,'circle.out'); rewrite(output);
read(n);
for i:=1 to n do 
for m:=1 to n do 
if (i<>m) and (((i<>m-n div 2) and (m<>i-n div 2)) or (n mod 2<>0))  then inc(l);
write(l);
end.