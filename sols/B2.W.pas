program w;
var a,b,c:integer;
begin
  assign(input,'sum.in');
  assign(output,'sum.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  c:=a+b;
  writeln(c);
  close(input);
  close(output)
end.
