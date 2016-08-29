var a,k,b,m,x,p,z:int64;
var inp,outp:text;
begin
  assign(inp,'forest.in');
  assign(outp,'forest.out');
  reset(inp);
  read(inp,a,k,b,m,x);
  close(inp);
  p:=0; z:=1;
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
   z:=z-1;
  Rewrite(outp);
  Write(outp,z);
  Close(outp);
end.