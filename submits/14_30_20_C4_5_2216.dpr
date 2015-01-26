program z52;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var
  n,k,i:LongInt;

begin
  Assign(input,'circle.in');
  Reset(input);
  Assign(Output,'circle.out');
  Rewrite(output);
  read(input,n);
  k:=1;
  for i:=2 to n-1 do
  k:=k+i;
  k:=k*2;
  if (n mod 2)=0 then
  k:=k-2*(n div 2);
  Writeln(output,k);
  Close(input);
  Close(output);

end.
