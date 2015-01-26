var g,a,b,c,d:longint;
var inp,outp:text;
var k,x,y:longint;
begin
  assign(inp,'hall.in');
  assign(outp,'hall.out');
  reset(inp);
  read(inp,a,b,c,d);
  close(inp);

  k:=0;
//  if b mod 2=0 then G:=round(b/2 -1) else G:=round((b-1)/2);
   for x:=1 to b do
    for y:=x to b do
     if ( x*y>=a) and (x*y<=b) and ((2*x+2*y)>=c) and ((2*x+2*y)<=d)
     then  k:=k+1;
  rewrite(outp);
  write(outp,k);
  close(outp);
end.
