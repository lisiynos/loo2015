label mark;
var
  o, k, n, j, i, a, b, c, d: integer;
  h: array[1..100] of longint;
  l: array[1..100] of longint;

begin
  assign(input,'hall.in');reset(input);
  assign(output,'hall.out');rewrite(output);
readln(a, b, c, d);
  

      for i := 1 to b do
        for j := 1 to b do
        for n := 1 to b  do
        for k := b downto 1 do
        begin
          if (i * j <= 10) and (i * j >= 2) and ((i + j) * 2 <= 8) and ((i + j) * 2 >= 4) then
            
            h[n] := i;
          l[k] := j;
        end;
  for n := 1 to b do
    for k := b downto 1 do
    begin
      mark: if (h[n] <> l[k]) and (n <> k) and (h[n] <> 0) and (l[k] <> 0) then
      begin
        l[k] := 0;
        h[n] := 0;
        goto mark;
      end else o := o + 1;
    end;
  writeln(o)
end.