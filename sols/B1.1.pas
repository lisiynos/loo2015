program hall;
var 
a,b,c,d,i,j:longint;
s:integer;

begin
 assign(input,'hall.in'); reset(input);
 assign(output,'hall.out'); rewrite(output);
read(a,b,c,d);
for i:=1 to a do
for j:=1 to c do
if (2*(i+j)>=c) and (2*(i+j)<=d) and (i*j<=b) and (i*j>=a) then inc(s);
write(s-1);
end.