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
close(q);

if (a<=1000)and(b<=1000)and(x<=1000)and(k<=1000)and(m<=1000) then
begin
  t:=0;
  while x>0 do
  begin
    t:=t+1;
    if t mod k<>0 then
    x:=x-a;
    if t mod m<>0 then
    x:=x-b;
  end;
end
else
begin
  if (x<k)and(x<k) then
  begin
    t:=(x div (a+b))+1
  end
  else
  begin
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
  end;
end;

Assign(q,'forest.out');
Rewrite(q);
write(q,t);
Close(q);
end.
