var sum, p, a, b, c, d:int64;
    sqlow, sqhigh:int64;
    i, j:longint;
    ar:array [1..100000] of int64;
begin
assign(input, 'hall.in'); reset(input);
assign(output, 'hall.out'); rewrite(output);
read(a, b, c, d);
for i := 1 to floor(sqrt(b)) do
  begin
    sqlow := ceil(a/i); 
    sqhigh := floor(b/i);
    //write(sqlow, ' ', sqhigh);
    for j := sqlow to sqhigh do
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