var sum, p, a, b, c, d:int64;
    sqlow, sqhigh:int64;
    i, j:longint;
begin
assign(input, 'hall.in'); reset(input);
//assign(output, 'hall.out'); rewrite(output);
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
              if i = j then sum := sum + 2
              else sum := sum + 1;
            end;
      end;
  end;
write(sum div 2);
end.