   program x;
   var
  a,b:integer;
begin
  Assign (Input,'sumsqr.in');
  Assign (Output,'sumsqr.out');
  reset(input);
  Rewrite(output);
  readln(a,b);
  a:=a*a;
  b:=b*b;
  write(a+b);
end.
