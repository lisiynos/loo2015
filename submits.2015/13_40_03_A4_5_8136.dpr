program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  q:TextFile;
  a,b,c,x,i,i0,Fa,fb:Word;
  p1,p2:array[1..40000]of word;
  f:Boolean;
begin
Assign(q,'circle.in');
Reset(q);
read(q,c);
Close(q);

x:=0;
for a:=1 to c do
for b:=1 to c do
begin
  if a<>b then
  begin
    f:=true;  
    for i0:=1 to c do
    begin
      fa:=Abs(i0-a)mod(c div 2);
      fb:=Abs(i0-b)mod(c div 2);
      p1[i0]:=fa;
      p2[i0]:=fb;
      for i:=1 to i0-1 do
      if (p1[i]=fa)and(p2[i]=fb) then
      begin
        f:=false;
        break
      end;
    end;
    if f=true then
    X:=x+1;
  end;
end;

Assign(q,'circle.out');
Rewrite(q);
write(q,x);
Close(q);
end.
