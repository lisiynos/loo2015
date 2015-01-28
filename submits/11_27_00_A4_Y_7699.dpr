program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
m,n,i,i0,i1,i2,p:Integer;
q:textfile;
f:Boolean;
A:array[1..1000,1..1000]of Char;
begin
Assign(q,'alligator.in');
reset(q);
read(q,n);
Readln(q,m);
for i:=1 to n do
begin
for i0:=1 to m-1 do
read(q,a[i,i0]);
readln(q,a[i,i0]);
end;
close(q);

p:=0;
f:=true;
while f<>False do
begin
f:=False;
for i:=1 to n do
for i0:=1 to m do
begin
   case a[i,i0] of
   'N':begin
         i1:=i;
         i2:=i0;
         while (i1<>0)and(a[i1,i2]<>'.') do
         begin
         i1:=i1-1;
         end;
         if i1=0 then
         begin
           p:=p+1;
           a[i,i0]:='.';
           f:=true;
         end;
       end;
   'S':begin
         i1:=i;
         i2:=i0;
         while (i1<>n)and(a[i1,i2]<>'.') do
         begin
         i1:=i1+1;
         end;
         if i1=n then
         begin
           p:=p+1;
           a[i,i0]:='.';
           f:=true;
         end;
       end;
   'W':begin
         i1:=i;
         i2:=i0;
         while (i2<>0)and(a[i1,i2]<>'.') do
         begin
         i2:=i2-1;
         end;
         if i2=0 then
         begin
           p:=p+1;
           a[i,i0]:='.';
           f:=true;
         end;
       end;
   'E':begin
         i1:=i;
         i2:=i0;
         while (i2<>m)and(a[i1,i2]<>'.') do
         begin
         i2:=i2+1;
         end;
         if i2=m then
         begin
           p:=p+1;
           a[i,i0]:='.';
           f:=true;
         end;
       end;
   end;
end;
end;

Assign(q,'alligator.out');
rewrite(q);
write(q,p);
close(q);
end.
