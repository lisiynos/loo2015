program forest;

var a,k,b,m,x,i,s,y,z:int64;

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
      
      if i<k then y:=a;
      if i=k then y:=0;
      if i>k then begin
         if i mod k <> 0 then y:=a;
         if i mod k=0 then y:=0;
      end;
      
      if i<m then z:=b;
      if i=m then z:=0;
      if i>m then begin
         if i mod m <> 0 then z:=b;
         if i mod m=0 then z:=0;
      end;
      
      s:=s+y+z;
end;

write(i);
      
      
      
close(input);
close(output);
END.