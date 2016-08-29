
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

  while (s<s1) do
    begin
     d:=d+1;
       if (k=0) or (d mod k <> 0) then k1:=1
       else k1:=0;
       if (d=0) or (d mod m <> 0) then m1:=1
       else m1:=0;
       s:=s+k1*a+m1*b;

    end;
    Writeln(output,d);
    close(input);
    Close(output);
end.