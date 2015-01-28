program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
a,b,c:Integer;
q:TextFile;
begin
Assign(q,'sum.in');
reset(q);
read(q,a);
read(q,b);
close(q);

c:=b+a;

Assign(q,'sum.out');
rewrite(q);
write(q,c);
close(q);
end.
