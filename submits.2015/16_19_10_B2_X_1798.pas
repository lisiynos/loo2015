program x;
var a,b,c:integer;
begin
  assign(input,'sumsqr.in');
  assign(output,'sunsqr.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  c:=sqr(a)+sqr(b);
  writeln(c);
  close(input);
  close(output)
end.
