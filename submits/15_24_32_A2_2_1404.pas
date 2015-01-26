var a,i,k,n,max:longint; cen:array[1..10000]of longint; sum:array[1..100000] of longint; all:longint;
begin
assign(input,'prizes.in'); reset(input);
assign(output,'prizes.out'); rewrite(output);
read(n,k);
readln;
for i:=1 to n do
read(cen[i]);
for i:=1 to n-k+1 do begin
   for a:=i to i+k-1 do
   sum[i]:=sum[i]+cen[a];
end;
max:=sum[1];
all:=1;
for i:=2 to n-k+1 do 
  if sum[i]>max then begin
     max:=sum[i];
     all:=i;
end;
   for i:=all-k+1 to all+k-1 do 
   sum[i]:=0;
max:=sum[1];
for i:=1 to n-k+1 do
if sum[i]>max then max:=sum[i];
writeln(max);
end.