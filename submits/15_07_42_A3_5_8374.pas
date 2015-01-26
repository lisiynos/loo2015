var
  n, i, j, ploho, kolvo: integer;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  read(n);
  kolvo:=0;
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      ploho:=0;
      if (i<>j) then begin
        if j>i then
        begin
           ploho:=ploho + ((j-i-1)mod 2);
           ploho:=ploho + (((n-j)+i-1) mod 2);
        end
        else
        begin
          ploho:= ploho + ((i-j-1) mod 2);  
          ploho:=ploho + (((n-i)+j-1) mod 2);
        end;
        if ploho=0 then kolvo:=kolvo+1; 
      end;
    end;  
  end;
  write(kolvo);
end.  