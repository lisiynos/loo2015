var a,b,c,d,i,k,l:longint;
begin
assign(input, 'hall.in'); reset(input);
assign(output,'hall.out'); rewrite(output);
read (a,b,c,d);
for i:=1 to 5000 do begin
for k:=1 to 5000 do begin
if ((2*(k+i)>c) or (2*(k+i)=c)) and ((2*(k+i)<d) or (2*(k+i)=d)) and ((k*i>a) or (k*i=a)) and ((k*i<b) or (k*i=b)) and ((k>i) or (k=i))  then inc(l);
end;
end;
writeln (l);
end.
