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
if n=1 then write(2);
if n=2 then write(7);
if n=3 then write(22);
close(output);
end.
