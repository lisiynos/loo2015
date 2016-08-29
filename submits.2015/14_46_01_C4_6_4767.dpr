program z6;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,k,b,m,x,s,d, k1, m1,nod,nok,s1:LongInt;

begin
Assign(Input,'forest.in');
  Reset(input);
  Assign(Output,'forest.out');
  Rewrite(output);
  readln(input,a,k,b,m,x);
  s:=0;
  d:=0;



  while (s<x) do
    begin
     d:=d+1;
     if (k=0) then k1:=1
      else if (d mod k <> 0) then k1:=1
       else k1:=0;
       if (m=0) then m1:=1
       else if (d mod m <> 0) then m1:=1
       else m1:=0;
       s:=s+k1*a+m1*b;

    end;
    Writeln(output,d);
    Readln(k);
    //close(input);
   // Close(output);
end.