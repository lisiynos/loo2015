program w;
 var
  s, b, a: int64;
  f, d:text;
 begin
  assign(f, 'sum.in');
  reset(f);
  readln(f, a, b);
  s:=a+b;
  assign(d, 'sum.out');
  rewrite(d);
  writeln(d, s);
  close(d);
 end.
