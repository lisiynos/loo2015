var sum, p, a, b, c, d:int64;
    sqlow, sqhigh:real;
    i, j:longint;
    ar:array [1..100000] of int64;
begin
assign(input, 'hall.in'); reset(input);
assign(output, 'hall.out'); rewrite(output);
read(a, b, c, d);
for i := 1 to trunc(sqrt(b))+1 do
  begin
    sqlow := a/i;
    if sqlow <> trunc(sqlow) then
      sqlow := sqlow + 1; 
    sqhigh := trunc(b/i);
    for j := trunc(sqlow) to trunc(sqhigh) do
      begin
        p := (j+i)*2;
        if (p >= c) and (p <= d) then
            begin
            if ar[i] <> j then
              begin
              ar[i] := j;
              ar[j] := i;
              sum := sum + 1;
              end;
           // writeln(i, ' ', j);
            end;
      end;
  end;
write(sum);
end.