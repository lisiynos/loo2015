program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k,n,x,p,f,c,i,i0:LongInt;
  q:TextFile;
  a:array[1..100000]of Integer;
begin
Assign(q,'prizes.in');
reset(q);
read(q,n);
read(q,k);
for i:=1 to n do
read(q,a[i]);
close(q);

x:=0;
c:=0;
for i:=1 to n-k+1 do
begin
p:=0;
for i0:=0 to k-1 do
p:=p+a[i0+i];
if p>x then
begin
x:=p;
f:=i;
end;
end;

for i:=f to f+k-1 do
a[i]:=0;

for i:=1 to n-k+1 do
begin
p:=0;
for i0:=0 to k-1 do
p:=p+a[i0+i];
if (p>c) then
c:=p;
end;

Assign(q,'prizes.out');
rewrite(q);
write(q,c);
close(q);
end.
