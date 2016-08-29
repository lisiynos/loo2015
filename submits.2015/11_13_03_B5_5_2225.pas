program _1;
var A,B,X,M,K,i:integer;
begin
i:=0;
readln(A,K,B,M,X);
while X>0 do
begin
i:=i+1;
if (i mod K=0) and (i mod M=0) then break;
if (i mod K=0) then X:=X-B;
if (i mod K=0) then X:=X-A;
if (i mod K<>0) and(i mod M<>0) then X:=X-(A+B);
end;
write(i);
end.
