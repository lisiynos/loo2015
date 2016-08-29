program les;
var a,k,b,m,d,x:longint;
begin
  assign(input,'forest.in');
  assign(output,'forest.out');
  reset(input);
  rewrite(output);
  readln(a,k,b,m,x);
  d:=1;
  while x>0 do
    begin
      if d mod k<>0 then x:=x-a;
      if d mod m<>0 then x:=x-b;
      if x>0 then d:=d+1
    end;
  writeln(d);
  close(input);
  close(output)
end.

