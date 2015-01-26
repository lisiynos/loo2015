program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e,i,j,k,x:longint;
begin
assign(input,'forest.in');
reset(input);
read(a,k,b,m,x);
close(input);
{for i:=1 to n do
 for j:=1 to n do begin
}
d:=1;
c:=1;
while(x>0)do begin
 e:=e+1;
 if c<>k then begin
  c:=c+1;
  x:=x-a;
 end
 else c:=0;
 if d<>m then begin
  d:=d+1;
  x:=x-b;
 end
 else d:=0;
end;
assign(output,'forest.out');
rewrite(output);
write(e+1);
close(output);
end.
