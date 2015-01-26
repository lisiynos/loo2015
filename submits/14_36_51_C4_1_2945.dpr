program Z1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    a,b,c,d,x,k,m1,m2: LongInt;
    function max(a,b:longint):LongInt;
    begin
      if a>=b then max:=a else max:=b;
    end;
    function min(a,b:longint):LongInt;
    begin
      if a<=b then min:=a else min:=b;
    end;

begin
  Assign (input, 'hall.in' );
  Reset(input);
  Assign(output,'hall.out');
  Rewrite(output);
  Readln(input,a,b,c,d);
  k:=0;
  m2:=1;
  m1:=0;
  x:=1;
 While (x<=Round(Sqrt(b))) and (m2>m1) do
    begin

        m1:=max(Round(a/x),(((c-2*x) div 2)));
        m2:=min(Round(b/x),(((d-2*x) div 2)));
        if m1<x then m1:=x;
        if m2>=m1  then
         k:=k+m2-m1+1;
         x:=x+1;
    end;
    Writeln(output,k);
    close(input);
    close(output);
end.
