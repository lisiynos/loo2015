program kol;

 var
  n,k:int64;
  f,d:text;



 begin

  assign(f, 'circle.in');
  reset(f);
  readln(f,n);
  assign(d, 'circle.out');
  rewrite(d);

  if (n mod 2)=0 then
   begin
   k:=n*n;
   writeln(d,k/2:0:0);
   end
  else
   begin
   k:=n*4;
    writeln(d,k);
   end;




    close(d);
 end.
