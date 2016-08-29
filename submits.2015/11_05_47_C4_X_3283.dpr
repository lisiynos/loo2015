program X;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a, b,c,i:longint;
begin
  Assign(input,'sumsqr.in');
  Reset(input);
   Assign(Input,'sumsqr.out');
   Rewrite(output);
  read(input,a,b);
  if (a and b) < 1000 then
  c:=a*a+b*b
  else
    begin
      c:=0;
      for i:=1 to a do
      c:=c+a;
       for i:=1 to b do
      c:=c+b;
    end;
    Writeln(output,c);
    Close(input);
    Close(output);
end.
 