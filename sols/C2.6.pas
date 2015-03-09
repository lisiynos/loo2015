program forest;
var A, K, B, days:LONGINT;
X, M:int64;
begin

assign (input,'forest.in'); reset (input);
assign (output, 'forest.out'); rewrite (output);

read (A,K,B,M,X);


days:=0;

while X>0 do begin

days:=days+1;

if (days mod K <>0) and (days mod M <> 0) then 
X:=X-A-B;


if (days mod M=0) and (days mod K<>0) then
X:=X-A;  


if (days mod M<>0) and (days mod K=0) then
X:=X-B;

end;


write (days);
end.