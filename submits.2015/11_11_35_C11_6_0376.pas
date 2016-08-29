var k,m,p,z:int64;
var inp,outp:text;
var a,b,x:longint;
begin
  assign(inp,'forest.in');
  assign(outp,'forest.out');
  reset(inp);
  read(inp,a,k,b,m,x);
  close(inp);
  p:=0; z:=1;
  if (x<k)and(x<m) then
    if (trunc(10*x/(a+b)) mod 10)<>0 then z:=trunc(p/(a+b))+1 else
      if (trunc(10*x/(a+b)) mod 10)=0  then z:=trunc(p/(a+b));
  if (x>k)or(x>m) then
      begin
  While p<x do
   begin
    if ((z mod k)=0)and((z mod m)=0)
     then begin z:=z+1;  end
     else if ((z mod k)=0)and((z mod m)<>0)
       then begin z:=z+1; p:=p+b;  end
       else if ((z mod k)<>0)and((z mod m)=0)
         then begin z:=z+1; p:=p+a;  end
         else if ((z mod k)<>0)and((z mod m)<>0)
           then begin z:=z+1; p:=p+a+b;  end;
    end;
   z:=z-1;    end;
  Rewrite(outp);
  Write(outp,z);
  Close(outp);
end.