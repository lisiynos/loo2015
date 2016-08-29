var a,b,c,d,i,k,j,e,r:longint;t:text;
begin
assign(t,'hall.in');
reset(t);
read(t,a,b,c,d);
close(t);
if c mod 2=1 then c:=c+1;
for i:=1 to (d-2) div 2 do 
begin
if (d-2) div 2 < b div i then r:=(d-2) div 2 else r:=b div i; 
if 2*i<c then e:=(c-2*i) div 2 else e:=1;
for j:=e to r do  
if i<>j then
if  (2*(i+j)<=d) and ((2*(i+j)>=c)) and (i*j<=b) and (i*j>=a) then k:=k+1;
end;
k:=k div 2;
for j:=1 to round(sqrt(d)-0.5) do 
if (4*j<=d) and (4*j>=c) and (j*j<=b) and (j*j>=a) then k:=k+1;
assign(t,'hall.out');
rewrite(t);
write(t,k);
close(t);
end.
