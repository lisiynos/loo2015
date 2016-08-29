program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  q:TextFile;
  a,b,k,m,x,t,p,pb,pa:Int64;
begin
Assign(q,'forest.in');
Reset(q);
read(q,a);
read(q,k);
read(q,b);
read(q,m);
read(q,x);
Close(q);

p:=k*m;
pa:=(k-1)*m*a;
pb:=k*(m-1)*b;
x:=x mod (pa+pb);
t:=(x div (pa+pb))*p;
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
