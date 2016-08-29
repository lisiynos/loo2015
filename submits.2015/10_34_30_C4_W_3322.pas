program W;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b:Integer;

begin
  Assign (input, 'sum.in');
  Reset(input);
  Assign(output,'sum.out');
  Rewrite(output);
 Read(input,a,b);
 Writeln(output,a+b);
 Close(Input);
 Close(Output);

  end.

