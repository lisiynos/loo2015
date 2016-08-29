var n,i,m,l:longint;
begin
assign (input,'circle.in'); reset(input);
assign (output,'circle.out'); rewrite(output);
read(n);
if n mod 2>0 then begin
for i:=1 to n do 
for m:=1 to n do 
if (i<>m) then inc(l);
write(l);
 end
else begin
for i:=1 to n do 
for m:=1 to (n div 2) do 
if (i<>m) and (m<>i-n div 2)  then inc(l);
write(l*2); 
end;
end.