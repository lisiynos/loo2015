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
  k1:=k;
  m1:=m;

   while (k1<>1) and (m1<>1) and(k1<>m1) do
   begin
     if m1> k1 then
     m1:=m1-k1
     else
     k1:=k1-m1;
   end;
    if k1>m1 then nod:=m1
    else nod:=k1;

    nok:=Round(k*m/nod);
    s:=(nok-k)*a+(nok-m)*b;
    d:=x div s;
    if x>=s then
    s:=x-(x mod s)
    else s:=0;
    s1:=x-s;;
   k1:=k;
  m1:=m;
  while (s<s1) do
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