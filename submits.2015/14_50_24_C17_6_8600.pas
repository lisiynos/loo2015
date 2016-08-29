program forest;

var a,k,b,m,x,i,s,y,z:integer;

BEGIN
assign(input,'forest.in');
reset(input);
assign(output,'forest.out');
rewrite(output);
   
   read(a,k,b,m,x);
   s:=0;
   i:=0;
   while s<=x do begin
     inc(i);
     if (i mod k) <> 0 then y:=a;
     if (i mod k) = 0 then y:=0;
     if (i mod m) <> 0 then z:=b;
     if (i mod m) = 0 then z:=0;
     s:=s+y+z;
   end;
   

write(i);
      
      
      
close(input);
close(output);
END.