program qq;
var t:text;a,b,m,k,x,y,s,z,i,k1:longint;s1:string;
begin
assign(t,'forest.in');
reset(t);
read(t,a,k,b,m,s);
close(t);
i:=1;
while (i mod k<>0) or (i mod m<>0) do 
i:=i+1;
x:=(i-(i div k))*a;
y:=(i-(i div m))*b;
z:=s div (x+y);
s:=s-z*(x+y);
k1:=i*z;
i:=0;
while s>0 do begin
i:=i+1;
if i mod k<>0 then s:=s-a;
if i mod m<>0 then s:=s-b;
end;
k1:=k1+i;
assign(t,'forest.out');
rewrite(t);
write(t,k1);
close(t);
end.