var a, b, c, d, i, j, kolvo, pred :longint;
begin
  assign(input,'hall.in'); reset(input);
  assign(output,'hall.out'); rewrite(output);
  read(a, b);
read(c, d);
  kolvo:=0;
  for i:=a to b do
  begin
      pred:=0;
      for j:=1 to i do
      begin
        if (i mod j = 0) and (j*2 + (i div j)*2 >= c) and (j*2 + (i div j)*2 <= d) then
        begin
          if j = pred then
          begin
            pred:=0;
            break;
          end;
          kolvo:= kolvo+1;
          pred:= i div j; 
        end;
      end;
  end;
  write(kolvo);
end.