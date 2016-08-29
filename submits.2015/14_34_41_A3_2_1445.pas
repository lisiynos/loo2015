var
  n, k, i, j, bob, perm, perp, perp2, perm2, perp3, ap1, am1: longint;
  cen: array[1..100000] of longint;
  pacen, a: array[1..100000] of longint;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  read(n, k);
  bob:=0;
  for i:=1 to n do read(cen[i]);
  for i:=1 to n do
  begin
    if i = n then perp := 1 else perp := i+1;
    pacen[i]:=cen[i] + cen[perp];
    a[i]:=i;
  end;
  for i:=1 to n do
  begin
    for j:=i to n do
    begin
      if pacen[j] > pacen[i] then
      begin
        pacen[i]:=pacen[j] + pacen[i]; a[i]:=a[j] + a[i];
        pacen[j]:=pacen[i] - pacen[j]; a[j]:=a[i] - a[j];
        pacen[i]:=pacen[i] - pacen[j]; a[i]:=a[i] - a[j];
      end;
    end;
  end;
  for i:=1 to n do
  begin
    if i>1 then perm := i-1 else perm:= n;
    if i = n then perp := 1 else perp := i+1;
    if i+2 > n then perp2 := i+2 mod n else perp2:= i + 2;
    if i-2 < 1 then perm2 := n + i-2 else perm2:= i-2;
    if i+3 > n then perp3 :=i+3 mod n else perp3:= i+3;
    if cen[perm] + cen[perp2] <= pacen[i] then
    begin
      if a[i] + 1 > n then ap1:= 1 else ap1:= a[i] + 1;
      if a[i] - 1 < 1 then am1:= n else am1:= a[i] - 1;
      if (a[perp] <> ap1) and (a[perp] <> am1) then 
      begin
        if k = n-1 then bob:=cen[perp2] else bob:=pacen[perp];        
      end  
      else
      begin
        if (a[perp2] <> ap1) and (a[perp2] <> am1) then bob:= pacen[perp2] else bob:=pacen[perp3];
        if k = n-1 then bob:=cen[perp2];
      end;
      if cen[perm] + cen[perp2] > bob then bob:=cen[perm] + cen[perp2];
      if k = n-1 then bob:=cen[perp2];
      break;
    end;
  end;
  write(bob);
end. 