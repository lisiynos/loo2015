program q1;

var
  a, k, b, m, x, c, n: int64;

begin
  Assign(input, 'forest.in');
  Assign(output, 'forest.out');
  reset(input);
  rewrite(output);
  readln(a, k, b, m, x);
  c := 0;
  n := 0;
  while c <= x do
  begin
    c := c + a + b;
    n := n + 1;
    if( n = k) and (n = m) 
      then
    begin
      c := c - (a + b);
      k := k+k;
      m := m+m;
    end
    else 
    if (n = k)
      then
    begin
      c := c - a;
      k := k+k;
    end
    else
    if (n = m)
      then 
      c := c - b;
    m := m+m;
  end;
  
  write(n+1);
end.