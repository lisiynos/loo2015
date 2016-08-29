var
a,b:array[1..1000000] of longint;n,k,i,j,s,s1,x,s2,o:integer;t:text;
begin
assign(t,'prizes.in');
reset(t);
read(t,n);
readln(t,k);
for i:=1 to n do
read(t,a[i]);
close(t);
for i:=1 to k do 
s:=s+a[i]; 
for i:=2 to n-k do begin
for j:=i to i+k-1 do
s1:=s1+a[j];
if s1>s then begin s:=s1;o:=i;end; 
s1:=0;
end;
for i:=o-k*2+1 to o+2*k-1 do 
begin
if i>0 then begin
b:=a;
for j:=i to n do
b[j]:=b[j+k];
for x:=1 to k do 
s2:=s2+b[x]; 
for x:=2 to n-2*k+1 do begin
for j:=x to x+k-1 do
s1:=s1+b[j];
if s1>=s2 then begin  s2:=s1; end;
s1:=0;
end;
if s>s2 then s:=s2;
s2:=0;
end;
end;
assign(t,'prizes.out');
rewrite(t);
writeln(t,s);
close(t);
end.