var n,k,z,i:longint;
var inp,outp:text;
begin
  assign(inp,'circle.in');
  assign(outp,'circle.out');
  reset(inp);
  read(inp,n);
  close(inp);
  z:=2;

  for i:=3 to n do
   z:=z+2*(i-1);

  if (n mod 2)=0 then z:=z-n;
  rewrite(outp);
  write(outp,z);
  close(outp);
end.