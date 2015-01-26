program forest;
var A, K, B, M, X, days:longint;
begin

assign (input,'forest.in'); reset (input);
assign (output, 'forest.out'); rewrite (output);

read (A,K,B,M,X);

days:=0;

while X>0 do begin

days:=days+1;

if (K mod days <>0) and (M mod days <> 0) then 
X:=X-A-B;


if (M mod days=0) and (K mod days<>0) then
X:=X-B;  


if (M mod days<>0) and (K mod days=0) then
X:=X-A;


end;

write (days);
end.