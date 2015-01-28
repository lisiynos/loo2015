var a,b,c:int64;
var inp,outp:text;
begin
  assign(inp,'c:/fpc/2.6.2/bin/i386-win32/sum.in');
  assign(outp,'c:/fpc/2.6.2/bin/i386-win32/sum.out');
  reset(inp);
  read(inp,a,b);
  close(inp);
  c:=a+b;
  rewrite(outp);
  write(outp,c);
  close(outp);
  writeln(trunc(21.5),round(21.5));
end.
