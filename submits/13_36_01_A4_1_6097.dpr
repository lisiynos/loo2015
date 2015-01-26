program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  a,b,c,d,z,i,i0:LongInt;
  q:TextFile;
begin
Assign(q,'hall.in');
reset(q);
read(q,a);
read(q,b);
read(q,c);
read(q,d);
close(q);

z:=0;
for i:=1 to (d div 2) do
for i0:=1 to i do
if ((i+i0)*2<=d)and((i+i0)*2>=c)and(i*i0<=b)and(i*i0>=a) then
z:=z+1;

Assign(q,'hall.out');
rewrite(q);
write(q,z);
close(q);
end.
 