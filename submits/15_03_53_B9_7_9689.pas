program do_not_fail_me_again;
uses crt;
var a,b,c,d,n,m,e,j,k,x:int64;
i:longint;
begin
assign(input,'tiling.in');
reset(input);
read(n);
close(input);
assign(output,'tiling.out');
rewrite(output);
d:=1;
for i:=n+1 downto 2 do
d:=d*i;
if n mod 2 = 0 then write(d-n+1)
else write(d+n-1);
close(output);
end.
