program circle;

var n,x:integer;

BEGIN
   assign(input,'circle.in');
   reset(input);
   assign(output,'circle.out');
   rewrite(output);
   
   read(n);
   if n mod 2 = 0 then
      x:=n*(n-2)
   else 
      x:=n*(n-1);
   write(x);
   close(input);
   close(output);
END.