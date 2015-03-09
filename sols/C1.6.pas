program ls;
var i,z,a,k,b,m,x:longint;
begin
 assign (input, 'forest.in');
 assign (output, 'forest.out');
 reset (input);
 rewrite (output);
 readln (a,k,b,m,x);
   for i:=1 to 1000000 do
    begin
     if i mod k <> 0 then
      x:=x-a;
     if i mod m <> 0 then
      x:=x-b;
     if x<=0 then
      break
    end;
 writeln(i);
 close (output);
 close (input)
end.