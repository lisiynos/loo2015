var 
A,B,C,D,x,i,j,k:longint;
begin
assign(input, 'hall.in');
reset(input);
assign(output, 'hall.out');
rewrite(output);
readln(A,B,C,D); k:=0; x:=0;
for i:=1 to b do begin
for j:=1 to b do begin
if (i*j>=A) and (i*j<=B) and ((i+j)*2>=C) and ((i+j)*2<=D) and (i=j) then inc(x);
if (i*j>=A) and (i*j<=B) and ((i+j)*2>=C) and ((i+j)*2<=D) and (i<>j) then inc(k);
end; end;
writeln(k/2+x);
end.
