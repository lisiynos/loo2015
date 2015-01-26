program _2;

var
  n, k, x, i, l, f: integer;
  a, b: array[1..100000] of integer;

begin
  assign(input,'prizes.in');
  assign(output,'prizes.out');
  reset(input);
  rewrite(output);
  
  
  
  
  f := -1;
  readln(n, k);
  for i := 1 to n do
    read(a[i]);
  x := 1;
  i := 1;
  l := 1;
  repeat
    i := l;
    
    while i - 1 < n do 
    begin
      
      b[x] := a[i] + a[i + 1];
      x := x + 1;
      i := i + k;
    end;
    l := l + 1
    
  until l = n;
 
  
  for i := 1 to n do
    for x := i + 1 to n do
    begin
      if b[i] < b[x] then
      begin
        l := b[i];
        b[i] := b[x];
        b[x] := l;
      end;
    end;
 
  
  x := 1;
  
  while f < 0 do
     begin
    if b[x] = b[x + 1] then
    begin
      f := 3;
      write(b[x])
    end;
   x:=x+1;
   end;
  
end.