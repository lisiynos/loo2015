var a,b,c:int64; inp,outp:text;
begin
  assign(inp,'sumqr.in');
  assign(outp,'sumqr.out');
  reset(inp);
  read(inp,a,b);
  close(inp);
  c:=sqr(a)+sqr(b);
  rewrite(outp);
  write(outp,c);
  close(outp);
end.
