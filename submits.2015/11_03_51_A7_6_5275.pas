var
  d, a, k, b, m, x, i: integer;

begin
assign(input,'forest.in');reset(input);
assign(output,'forest.out');rewrite(output);
  readln(a, k, b, m, x);
  if x <> 0 then
    
    
    
    
          for i := 1 to 1000 do
    for d := 1 to 1000 do
    
    begin
      

      if (d div i <> k) and (d div i <> m) then
        x := x - (a + b);
      if d div i = k then
        x := x - b;
      if d div i = m  then
        x := x - a;
      if (d div i = m) and (d div i = k) then
        x := x;

      
      if x = 0 then
        writeln(d);
      
      
  end;
  
  
end.