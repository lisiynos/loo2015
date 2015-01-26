program z6;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,k,b,m,x,s,d, k1, m1:LongInt;

begin
  Assign(Input,'forest.in');
  Reset(input);
  Assign(Output,'forest.out');
  Rewrite(output);
  readln(input,a,k,b,m,x);
  s:=0;
  d:=0;
  k1:=k;
  m1:=m;
  while (s<x) do
    begin
     d:=d+1;
       if (d mod k) <> 0 then k1:=1
       else k1:=0;
       if (d mod m) <> 0 then m1:=1
       else m1:=0;
       s:=s+k1*a+m1*b;

    end;
    Writeln(output,d);
    close(input);
    Close(output);
end.