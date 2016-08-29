var
a,b,c,d,i,j:longint;
s:integer;
begin
assign(input,'hall.in'); reset(input);
 assign(output,'hall.out'); rewrite(output);
read(a,b,c,d);
for i:=1 to round(d/2+1) do 
for j:=1 to d-1 do 
if (2*(i+j)>=c) and (2*(i+j)<=d) and (i*j<=b) and (i*j>=a) then inc(s);
write(s);
end.