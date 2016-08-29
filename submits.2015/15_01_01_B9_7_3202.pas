program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e,i,j,k,x:int64;
begin
assign(input,'tiling.in');
reset(input);
read(n);
close(input);
assign(output,'tiling.out');
rewrite(output);
for i:=n+1 downto 2 do
d:=d*i;
if n mod 2 = 0 then write(d-n+1)
else write(d+n-1);
close(output);
end.
