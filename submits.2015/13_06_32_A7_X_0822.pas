var
  a, b: longint;

begin
  assign(input, 'sumsqr.in');reset(input);
  assign(output, 'sumsqr.out');rewrite(output);
  readln(a, b);
  writeln(sqr(a) + sqr(b));
end.