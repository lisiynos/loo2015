var
  n, p, k, i, kva, j, kus1, kus2, per: longint;
  a: array[1..100000] of longint;
  sob: array[1..100000, 1..2] of longint;
begin
  assign(input,'river.in'); reset(input);
  assign(output,'river.out'); rewrite(output);
  read(n, p);
  kva:= 0;
  for i:=1 to n do 
  begin
    read(a[i]);
    kva:= kva + a[i]*a[i];
  end;
  writeln(kva);
  read(k);
  for i:=1 to k do read(sob[i, 1], sob[i,2]);
  for i:=1 to k do
  begin
    kva:=0;
  {  for j:=1 to sob[i,2]-1 do
    begin
      kva:= kva + a[j] * a[j];
    end;}
    if sob[i, 1] = 1 then
    begin
      if (sob[i, 2] = 1) then a[2]:= a[2] + a[1] else
      begin
        if sob[i, 2] = n then a[n-1]:=a[n-1] + a[n] else
        begin
          kus1:=a[sob[i,2]] div 2;
          kus2:=a[sob[i,2]] div 2 + a[sob[i,2]] mod 2;
          a[sob[i,2]-1]:=a[sob[i,2]-1] + kus1;
          a[sob[i,2]+1]:=a[sob[i,2]+1] + kus2;
      end; end;
          n:=n-1;
          for j:=sob[i,2] to n do
          begin
            a[j]:=a[j+1];
          end;      
    end;
    if sob[i,1] = 2 then
    begin
      n:=n+1;
      kus1:=a[sob[i,2]] div 2; kus2:=a[sob[i,2]] div 2 + a[sob[i,2]] mod 2;
      a[sob[i,2]]:= kus1;
      per:=kus2;
      for j:=sob[i,2] + 1 to n do
      begin
        kus2:=a[j];
        a[j]:=per;
        per:=kus2;
      end;
    end;
    for j:=1 to n do kva:=kva + a[j]*a[j];
    writeln(kva);    
  end;
end.