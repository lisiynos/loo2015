var
  a, k, b, m, x, y, i: longint;

begin
  assign(input, 'forest.in');
  reset(input);
  assign(output, 'forest.out');
  rewrite(output);
  read(a, k, b, m, x);
  while y < x do 
  begin
    i := i + 1;
    if i mod k <> 0 then y := y + a;
    if i mod m <> 0 then y := y + b;
  end;
  write(i);
end.