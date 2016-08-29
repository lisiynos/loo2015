program hall;

var
  a, b, c, d, m, n, s, i, j, k, p: int64;

begin
assign(input,'hall.in');
assign(output,'hall.out');
reset(input);
rewrite(output);
  m := 1;
  n := 0;
  read(a, b, c, d);
  for i := 1 to a do
  begin
    for j := 1 to b do
    begin
    n := n + 1;
      s := m * n; 
      
      if (s >= a) and (s <= b)
        then
      begin
        p := 2 * (m + n);
        
        if (p >= c) and (p <= d)
          then
          k := k + 1;
        
      end
      
    end;
  end;
  m:=m+1;
  
  writeln(k+1)
end.