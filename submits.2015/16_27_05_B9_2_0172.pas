program qq;
uses crt;
var k,v,e,n,max1,max2:int64;
    a,b,c:array[1..100000]of int64;
    i,j:longint;
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

for i:=1 to n-3*k+3 do
for j:=i to i+2*(k-1) do
c[i]:=c[i]+a[j];
max1:=-1;
max2:=-2;
for i:=1 to n-k+1 do begin
 if a[i]>max1 then begin
  max1:=a[i];
  v:=i;
end;

end;
for i:=1 to n-k+1 do
 if(a[i]>max2)and((i<v-k)or(i>v+k))then max2:=a[i];
close(input);
assign(output,'prizes.out');
rewrite(output);
write(max2);
close(output);
end.
