program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e,i,j,k,x:int64;
begin
assign(input,'forest.in');
reset(input);
read(a,k,b,m,x);
close(input);

if(x<k)and(x<m)then e:=x div (a+b)
else if(k=m)then begin
d:=(x div (a+b));
d:=d+(d mod k);
end
else begin
while(x>0)do begin
 e:=e+1;
 if e mod k<>0 then x:=x-a;
 if e mod m<>0 then x:=x-b;
end;
end;
assign(output,'forest.out');
rewrite(output);
write(e);
close(output);
end.

