var a,b,k,m,l,x,den:longint; 
begin
read(a,k,b,m,x);
l:=1;
while l-1<x do begin
 inc(den);
   if den mod m<>0 then 
       l:=l+a;
      if den mod k<>0 then 
       l:=l+b;      
      end;
 writeln(den);
 end.