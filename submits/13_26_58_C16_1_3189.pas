program hall;

 var
  a, b, c, d, k: int64;
  x, y: longint;
  f, e: text;

 begin

  assign(f, 'hall.in');
  reset(f);
  readln(f, a, b, c, d);
  assign(e, 'hall.out');
  rewrite(e);

  for x:=1 to b do
   for y:=x to b do
    if (x*y >= a) and (x*y<=b) and (2*(x+y) >= c) and (2*(x+y) <= d) then
     inc(k);

  writeln(e, k);
  close(e);

end.