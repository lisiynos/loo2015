program hall;
var 
a,b,c,d,i,j,s,k,p:longint;
begin
 assign(input,'hall.in'); reset(input);
 assign(output,'hall.out'); rewrite(output);
read(a,b,c,d);
k:=(d div 2)+1;
p:=c div 2;
for i:=1 to k do
for j:=1 to d-1 do
if (2*(i+j)>=c) and (2*(i+j)<=d) and (i*j<=b) and (i*j>=a) then inc(s);
write(s);
end.