program forest;

var a,k,b,m,x,i,s:int64;

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
      
      if (i<k) then begin if (i<m) then s:=s+a+b
      else if (i=m) then s:=s+a
      else if (i>m) and (i mod m <> 0) then s:=s+a+b
      else if (i>m) and (i mod m = 0) then s:=s+a;
      continue;
      end
      
      else if (i=k) then begin if (i<m) then s:=s+b
      else if (i=m) then s:=s
      else if (i>m) and (i mod m <> 0) then s:=s+b
      else if (i>m) and (i mod m = 0) then s:=s;
      continue;
      end
      
      else if (i>k) then begin
         if i mod k <> 0 then begin
            if (i=m) then s:=s+a
            else if (i>m) and (i mod m <> 0) then s:=s+a+b
            else if (i>m) and (i mod m = 0) then s:=s+a;
           continue;
         end
         else begin if (i=m) then s:=s
            else if (i>m) and (i mod m <> 0) then s:=s+b
            else if (i>m) and (i mod m = 0) then s:=s;
            continue;
         end;
      end;
   
   
   
   end;

write(i);
      
      
      
close(input);
close(output);
END.