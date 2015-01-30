program qq;
uses crt;
var k,v,e,n,max1,max2:int64;
    i,j:longint;
begin
clrscr;
assign(input,'circle.in');
reset(input);
read(n);
close(input);
assign(output,'circle.out');
rewrite(output);
if n mod 2 =1 then write(n*n-n)
else write(n*n-2*n);

close(output);
end.
