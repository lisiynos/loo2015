var a,b,c:int64; inp,outp:text;
begin
  assign(inp,'c:/fpc/2.6.2/bin/i386-win32/sumqr.in');
  assign(outp,'c:/fpc/2.6.2/bin/i386-win32/sumqr.out');
  reset(inp);
  read(inp,a,b);
  close(inp);
  c:=sqr(a)+sqr(b);
  rewrite(outp);
  write(outp,c);
  close(outp);
end.