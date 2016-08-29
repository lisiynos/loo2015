program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  q:TextFile;
  a,b,k,m,x,t,p:Int64;
begin
Assign(q,'forest.in');
Reset(q);
read(q,a);
read(q,k);
read(q,b);
read(q,m);
read(q,x);
Close(q);

p:=(m*k*(a+b))-(a*m)-(b*k);
t:=m*k*(x div p);
x:=x mod p;
while x>0 do
begin
  t:=t+1;
  if t mod k<>0 then
  x:=x-a;
  if t mod m<>0 then
  x:=x-b;
end;

Assign(q,'forest.out');
Rewrite(q);
write(q,t);
Close(q);
end.
