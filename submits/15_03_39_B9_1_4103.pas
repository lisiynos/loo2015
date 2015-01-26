program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e:int64;
    i,j:longint;
begin
clrscr;
assign(input,'hall.in');
reset(input);
read(a,b,c,d);
close(input);
if c mod 2 = 0 then c:=c div 2
else c:=(c div 2)+1;
if d mod 2 = 0 then d:=d div 2
else c:=(c div 2)-1;
for i:=1 to d-1 do
if c-i>2 then begin
 for j:=c-i to d-i do
  if(i*j>=a)and(i*j<=b)then e:=e+1;
 end
else begin
 for j:=2 to d-i do
  if(i*j>=a)and(i*j<=b)then e:=e+1;
 end;
assign(output,'hall.out');
rewrite(output);
write(e);
close(output);
end.
