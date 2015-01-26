program hall;
var 
a,b,c,d,i,j,s:longint;

begin
 assign(input,'hall.in'); reset(input);
 assign(output,'hall.out'); rewrite(output);
read(a,b,c,d);
for i:=1 to d do
for j:= 1 to d do
if (2*(i+j)>=c) and (2*(i+j)<=d) and (i*j<=b) and (i*j>=a) then inc(s);
write(s);
end.