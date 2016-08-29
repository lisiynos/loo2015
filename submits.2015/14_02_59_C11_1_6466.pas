var g,a,b,c,d:int64;
var inp,outp:text;
var k,x,y:longint;
begin
  assign(inp,'c:/fpc/2.6.2/bin/i386-win32/hall.in');
  assign(outp,'c:/fpc/2.6.2/bin/i386-win32/hall.out');
  reset(inp);
  read(inp,a,b,c,d);
  close(inp);

  k:=0;
  if b mod 2=0 then G:=round(b/2 -1) else G:=round((b-1)/2);
   for x:=1 to G do
    for y:=x to B do
     if ( x*y>=a) and (x*y<=B) and ((2*x+2*y)>=c) and ((2*x+2*y)<=d)
     then  k:=k+1;
  rewrite(outp);
  write(outp,k);
  close(outp);
end.