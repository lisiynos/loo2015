program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  q:TextFile;
  n,k,x,i:LongInt;
begin
Assign(q,'tiling.in');
Reset(q);
read(q,n);
read(q,k);
Close(q);

if k=1 then
x:=8
else
begin
  x:=2;
  for i:=1 to n-1 do
  x:=x*3+1;
end;

Assign(q,'tiling.out');
Rewrite(q);
write(q,x);
Close(q);
end.
