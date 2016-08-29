var
  n, i, j, c, e, rasa, rasb, pribav, kolvo, per1, per2: integer;
  da, db: array[1..40000] of integer;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  read(n);
  kolvo:=0;
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
    if (i<>j) then
    begin
      pribav:=1;
      for c:=1 to n do
      begin
        if c<i then
        begin
          per1:= i - c;
          per2:= (n-i) + c;
        end
        else begin
          per1:= c - i;
          per2:= i + (n-c);
        end;
        if per1 < per2 then rasa:= per1 else rasa:=per2;
        if c<j then
        begin
          per1:= j - c;
          per2:= (n-j) + c;
        end
        else begin
          per1:= c - j;
          per2:= j + (n-c);
        end;
        if per1 < per2 then rasb:= per1 else rasb:=per2;        
        da[c]:=rasa;
        db[c]:=rasb;
        for e:=1 to c do
        begin
          if (da[c] = da[e]) and (db[c] = db[e]) and (e <> c) then
          begin
            pribav:=0;
            break;
          end;
        end;
        if pribav = 0 then break;
      end;
      kolvo:= kolvo + pribav;
    end;  
    end;
  end;
  write(kolvo);
end. 