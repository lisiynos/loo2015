label 1;
var a,b,k,m,l,x,den:int64; 
begin
assign(input,'forest.in'); reset(input);
assign(output,'forest.out'); rewrite(output);
read(a,k,b,m,x);
if (m=0) and (k=0) then begin
 if x mod a+b>0 then writeln ((x div a+b)+1) else writeln (x div a+b); goto 1;
 end;
 if k=m then begin
 if x mod a+b>0 then  begin
 l:=((x div a+b)+1);
    den:=(l div k)+l;
    write(den+(den div k)-l); goto 1; end;
  if x mod a+b=0 then  begin
 l:=x div a+b;
    den:=(l div k)+l;
    write(den+(den div k)-l); goto 1;  
 end; end;
while l<x do begin
 den:=den+1;
   if den mod k<>0 then 
       l:=l+a;
      if den mod m<>0 then 
       l:=l+b;      
      end;
 write(den);
1: end.