program hall;

var
  a, b, c, d, m, n, s, i, j, k, p: int64;
  f:array[1..1000] of integer;
y:array[1..1000] of integer;
begin
  m := 0;
  read(a, b, c, d);
  for i := 1 to a do
  begin
  m:=m+1;
  n:=0;
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
          begin
          k := k +1;
        end;
        
      end;
     
    end;
  
  end;

  
  writeln(k)
end.