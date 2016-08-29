   program w;
   var
  a,b:integer;
begin
  Assign (Input,'sum.in');
  Assign (Output,'sum.out');
  reset(input);
  Rewrite(output);
  readln(a,b);
  write(a+b);
end.
