program qq;
type
qwer = record
x,y:integer;
end;
var n,b,c,d,e,f,g,h,i,j:longint;t:text;a:Array[1..10000] of qwer;p:boolean;
begin
assign(t,'circle.in');
reset(t);
read(t,n);
close(t);
for i:=1 to n do 
for j:=1 to n do begin
p:=false;
for f:=1 to n do
if i<>j then begin
d:=abs(i-f);
b:=abs(j-f);
if n-d<d then d:=n-d;
if n-b<b then b:=n-b;
a[f].x:=d;
a[f].y:=b;
end;
if i<>j then begin
for e:=1 to n do 
for c:=e+1 to n do
if (a[e].x=a[c].x) and (a[e].y=a[c].y) then p:=true;
if p=false then h:=h+1;
end;
end;
assign(t,'circle.out');
rewrite(t);
write(t,h);
close(t);
end.