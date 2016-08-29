program x;
 var
  s, b, a: int64;
  f, d:text;
 begin
  assign(f, 'sumsqr.in');
  reset(f);
  readln(f, a, b);
  s:=sqr(a)+sqr(b);
  assign(d, 'sumsqr.out');
  rewrite(d);
  writeln(d, s);
  close(d);
 end.
