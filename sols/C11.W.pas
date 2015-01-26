var a,b,c:int64;
var inp,outp:text;
begin
  assign(inp,'sum.in');
  assign(outp,'sum.out');
  reset(inp);
  read(inp,a,b);
  close(inp);
  c:=a+b;
  rewrite(outp);
  write(outp,c);
  close(outp);
  writeln(trunc(21.5),round(21.5));
end.
