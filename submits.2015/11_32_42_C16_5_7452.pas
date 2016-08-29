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

   k:=n*(n-2)


  else

   k:=n*(n-1);
    writeln(d,k);





    close(d);
 end.
