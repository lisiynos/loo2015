program les;

 var
  a, k, b, m ,x,e:int64;
  i:longint;
  f,d:text;




 begin

  assign(f, 'forest.in');
  reset(f);
  readln(f, a, k, b, m, x);
  assign(d, 'forest.out');
  rewrite(d);
  e:=1;
  x:=x-a-b;

  while x<>0 do begin
        inc(e);
   if e<>k then
    x:=x-a;
   if e<>b then
    x:=x-b;
   if x=0 then
    inc(e);
  end;

    writeln(d,e);

    close(d);
 end.
