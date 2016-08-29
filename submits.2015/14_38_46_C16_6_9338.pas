program les;

 var
  a, k, b, m , x, e:int64;
  i:longint;
  f,d:text;




 begin

  assign(f, 'forest.in');
  reset(f);
  readln(f, a, k, b, m, x);
  assign(d, 'forest.out');
  rewrite(d);

  if (x<=k) and (x<=m) then
   begin



     if (e mod (a+b)) <> 0 then
     e:= (x div (a+b)) +1
     else
      e:= x div (a+b);



   end

 else

  begin

  e:=1;
  x:=x-a-b;


  while x>0 do
   begin

    inc(e);

    if (e mod k) <> 0 then
     x:=x-a;

    if (e mod m) <> 0 then
     x:=x-b;
      end;
   end;
    writeln(d,e);

    close(d);
 end.
