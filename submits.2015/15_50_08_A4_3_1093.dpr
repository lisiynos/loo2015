program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  q,q1:textfile;
  n,p,k,i,i0,v,e,n2,f:Integer;
  a:array[1..200000]of LongInt;
begin
Assign(q,'river.in');
reset(q);
read(q,n);
readln(q,p);
for i:=1 to n do
read(q,a[i]);
read(q,k);

Assign(q1,'river.out');
rewrite(q1);

n2:=n;
for i0:=1 to k do
begin

  f:=0;
  for i:=1 to n2 do
  f:=f+(a[i]*a[i]);
  Writeln(q1,f);


  read(q,e);
  readln(q,v);
  if (e=1) then
    if (v=1) then
    begin
      a[v]:=a[v]+a[v+1];
      for i:=v+1 to n2 do
      a[i]:=a[i+1];
      n2:=n2-1;
    end
    else
    begin
      a[v-1]:=a[v-1]+(a[v] div 2)+(a[v] mod 2);
      a[v]:=a[v+1]+(a[v] div 2);
      for i:=v+1 to n2 do
      a[i]:=a[i+1];
      n2:=n2-1;
    end;
  if e=2 then
    if (v=1) then
    begin
      i:=n2+1;
      while i<>v+1 do
      begin
        a[i]:=a[i-1];
        i:=i-1;
      end;
      a[v+1]:=(a[v] div 2);
      a[v]:=(a[v] div 2)+(a[v] mod 2);
      n2:=n2+1;
    end
    else
    begin
      i:=n2+1;
      while i<>v+1 do
      begin
        a[i]:=a[i-1];
        i:=i-1;
      end;
      a[v+1]:=(a[v] div 2);
      a[v]:=(a[v] div 2)+(a[v] mod 2);
      n2:=n2+1;
    end;
end;

  f:=0;
  for i:=1 to n2 do
  f:=f+(a[i]*a[i]);
  Writeln(q1,f);

close(q);
close(q1);
end.
