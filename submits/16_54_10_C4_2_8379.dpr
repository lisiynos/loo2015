program Z2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var n,k, pos, s1,s2,max,p,i:integer;
  a:Array of integer;
  b:Array of integer;
  p1:Array of longint;
  p2:Array of longint;

begin
  Readln(n,k);
  SetLength(a,n);
  for i:=1 to n do
  read(a[i]);
  for i:=1 to n do
  write(a[i]);
  Writeln(n);
  Writeln(a[10]);
  p:=n-(n mod k);
  SetLength(b,p);
  SetLength(p1,p);
  SetLength(p2,p);
  for i:=1 to k do
      b[1]:=b[1]+a[i];
  p1[1]:=1;
  p2[1]:=k;
  Writeln(b[1],' ',p1[1],' ',p2[1],' ');
  Writeln(p);
  Writeln(a[9]);
  Writeln(a[10]);
  for i:=2 to p-1 do
   begin
      b[i]:=b[i-1]-a[i-1]+a[i+k-1];
      p1[i]:=i;
      p2[i]:=i+k-1;
      Writeln ('b[i-1]= ',b[i-1],'a[i-1]= ',a[i-1],'a[i+k-1]= ',a[i+k-1]);
      Writeln(b[i],' ',p1[i],' ',p2[i],' ');
      
   end;
      Readln(n);
end.
