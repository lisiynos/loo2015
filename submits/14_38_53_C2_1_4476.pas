program prizes;
var a:array [1..100000] of integer;
w, k, i, b, m, f, l, z, n:longint;
begin

assign (input, 'prizez.in'); reset (input);
assign (output, 'prizez.out'); rewrite (output);
read (m,k);

for i:=1 to m do
read (a[i]);

for i:=1 to m do
if (w>n) and (w>z) then z:=w;
if (w<n) and(n>z) then z:=n; 
w:=0; n:=0;
 begin
for l:=1 to k do 
w:=w+a[i+k];
n:=n+a[i+1+k]; 
if (w>n) and (w>z) then z:=w;
if (w<n) and(n>z) then z:=n; 
end;

for i:=1 to m do
for l:=1 to k do begin
w:=w+a[i+l];
if w=z then begin 
if a[i-1]>=a[i+k+1] then  f:=f+a[i-1+k] else 
 f:=f+a[i+1+k];
end;
end;
write (f);
write (z);
 

end.