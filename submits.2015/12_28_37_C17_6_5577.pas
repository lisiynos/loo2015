   read(a,k,b,m,x);
   i:=1;
   s:=0;
   while s<=x do begin
      if (i<=k) then begin
      if (i div k <> 1) then
        x1:=a
           else x1:=0;
      end;
      if (i>k) then begin
      if (i mod k <> 0) then x1:=a
           else x1:=0;
      end;
      
      if (i<=m) then begin
      if (i div m <> 1) then
        y1:=b
           else y1:=0;
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