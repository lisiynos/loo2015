program qq;
uses crt;
var k,v,e,max1,max2:int64;
    a,b:array[1..100000]of int64;
    n,i,j:longint;
begin
clrscr;
assign(input,'prizes.in');
reset(input);
read(n,k);
readln;
for i:=1 to n do
read(b[i]);
for i:=1 to n do
for j:=i to i+k-1 do
a[i]:=a[i]+b[j];
max1:=-1;
max2:=-2;
for i:=1 to n-k+1 do begin
 if a[i]>max1 then begin
  max2:=max1;
  max1:=a[i];
 end;
 if(a[i]<max1)and(a[i]>max2)then max2:=a[i];
end;
close(input);
assign(output,'prizes.out');
rewrite(output);
write(max2);
close(output);
end.
