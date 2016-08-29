program forest;

var a,k,b,m,x,x1,y1,s,s1,i:int64;

BEGIN
assign(input,'forest.in');
reset(input);
assign(output,'forest.out');
rewrite(output);
   
   read(a,k,b,m,x);
   i:=1;
   s:=0;
   while s<=x do begin
      if (i<=k) then begin
      if i<k then
        x1:=a;
      if i=k then x1:=0;
      end;
      if (i>k) then begin
      if (i mod k <> 0) then x1:=a
           else x1:=0;
      end;
      
      if (i<=m) then begin
      if i<m then
        y1:=b;
      if i>m then
       y1:=0;
      end;
      if (i>m) then begin
      if (i mod m <> 0) then y1:=b
           else y1:=0;
      end;
      s1:=x1+y1;
      s:=s+s1;
      inc(i);
   end;
   
   write(i-1);
   
close(input);
close(output);
END.