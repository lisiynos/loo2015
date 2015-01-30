program qq;
var t:text;a,b,m,k,s,i:longint;
begin
assign(t,'forest.in');
reset(t);
read(t,a,k,b,m,s);
close(t);
while s>0 do begin
i:=i+1;
if i mod k<>0 then s:=s-a;
if i mod m<>0 then s:=s-b;
end;
assign(t,'forest.out');
rewrite(t);
write(t,i);
close(t);
end.