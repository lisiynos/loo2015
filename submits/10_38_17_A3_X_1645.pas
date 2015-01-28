var
  a, b:longint;
begin
  assign(input,'sumsqr.in.txt'); reset(input);
  assign(output,'sumsqr.out.txt'); rewrite(output);
  read(a, b);
  write(a*a + b*b);
end.